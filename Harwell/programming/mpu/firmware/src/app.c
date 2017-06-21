/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

/*! \file app.cpp
    \brief Contains all the general application code.
    
    All functions that run the application are stored here. Specific code
    for I2C, SPI etc are stored in specialised files.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"



// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
 */

APP_DATA appData;
#if defined(ENABLE_USB)
/* USB Receive data buffer */
uint8_t receiveDataBuffer[64] APP_MAKE_BUFFER_DMA_READY;
/* USB Transmit data buffer */
uint8_t transmitDataBuffer[64] APP_MAKE_BUFFER_DMA_READY;
#endif

#if defined(ENABLE_I2C)
DRV_I2C_BUFFER_HANDLE i2cTxBuffer[2]; // only two bytes are required to set output 
DRV_I2C_BUFFER_HANDLE i2cRxBuffer[64];
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

#if defined(ENABLE_USB)

USB_DEVICE_HID_EVENT_RESPONSE APP_USBDeviceHIDEventHandler
(
        USB_DEVICE_HID_INDEX iHID,
        USB_DEVICE_HID_EVENT event,
        void * eventData,
        uintptr_t userData
        ) {

    USB_DEVICE_HID_EVENT_DATA_REPORT_SENT * reportSent;
    USB_DEVICE_HID_EVENT_DATA_REPORT_RECEIVED * reportReceived;

    /* Check type of event */
    switch (event) {

        case USB_DEVICE_HID_EVENT_REPORT_SENT:
        {

            /* The eventData parameter will be USB_DEVICE_HID_EVENT_REPORT_SENT
             * pointer type containing details about the report that was
             * sent. */
            reportSent = (USB_DEVICE_HID_EVENT_DATA_REPORT_SENT *) eventData;
            if (reportSent->handle == appData.txTransferHandle) {
                // Transfer progressed.
                appData.hidDataTransmitted = true;
            }

            break;
        }

        case USB_DEVICE_HID_EVENT_REPORT_RECEIVED:
        {

            /* The eventData parameter will be USB_DEVICE_HID_EVENT_REPORT_RECEIVED
             * pointer type containing details about the report that was
             * received. */

            reportReceived = (USB_DEVICE_HID_EVENT_DATA_REPORT_RECEIVED *) eventData;
            if (reportReceived->handle == appData.rxTransferHandle) {
                // Transfer progressed.
                appData.hidDataReceived = true;
            }

            break;
        }

        case USB_DEVICE_HID_EVENT_SET_IDLE:
        {

            /* For now we just accept this request as is. We acknowledge
             * this request using the USB_DEVICE_HID_ControlStatus()
             * function with a USB_DEVICE_CONTROL_STATUS_OK flag */

            USB_DEVICE_ControlStatus(appData.usbDeviceHandle, USB_DEVICE_CONTROL_STATUS_OK);

            /* Save Idle rate received from Host */
            appData.idleRate = ((USB_DEVICE_HID_EVENT_DATA_SET_IDLE*) eventData)->duration;
            break;
        }

        case USB_DEVICE_HID_EVENT_GET_IDLE:
        {

            /* Host is requesting for Idle rate. Now send the Idle rate */
            USB_DEVICE_ControlSend(appData.usbDeviceHandle, & (appData.idleRate), 1);

            /* On successfully receiving Idle rate, the Host would acknowledge back with a
               Zero Length packet. The HID function driver returns an event
               USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT to the application upon
               receiving this Zero Length packet from Host.
               USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT event indicates this control transfer
               event is complete */

            break;
        }



        default:
        {
            // Nothing to do.
            break;
        }
    }
    return USB_DEVICE_HID_EVENT_RESPONSE_NONE;
}

void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context) {
    switch (event) {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* Host has de configured the device or a bus reset has happened.
             * Device layer is going to de-initialize all function drivers.
             * Hence close handles to all function drivers (Only if they are
             * opened previously. */

            //            BSP_LEDOn  (APP_USB_LED_1);
            //            BSP_LEDOn  (APP_USB_LED_2);
            //            BSP_LEDOff (APP_USB_LED_3);
            appData.deviceConfigured = false;
            appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
            break;

        case USB_DEVICE_EVENT_CONFIGURED:
            /* Set the flag indicating device is configured. */
            appData.deviceConfigured = true;

            /* Save the other details for later use. */
            appData.configurationValue = ((USB_DEVICE_EVENT_DATA_CONFIGURED*) eventData)->configurationValue;
#if defined(ENABLE_USB)
            /* Register application HID event handler */
            USB_DEVICE_HID_EventHandlerSet(USB_DEVICE_HID_INDEX_0, APP_USBDeviceHIDEventHandler, (uintptr_t) & appData);
#endif
            /* Update the LEDs */
            //            BSP_LEDOff (APP_USB_LED_1);
            //            BSP_LEDOff (APP_USB_LED_2);
            //            BSP_LEDOn  (APP_USB_LED_3);

            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            /* Switch on green and orange, switch off red */
            //            BSP_LEDOff (APP_USB_LED_1);
            //            BSP_LEDOn  (APP_USB_LED_2);
            //            BSP_LEDOn  (APP_USB_LED_3);
            break;


        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is not available */
            USB_DEVICE_Detach(appData.usbDeviceHandle);
            break;

            /* These events are not used in this demo */
        case USB_DEVICE_EVENT_RESUMED:
        {
            break;
        }

        case USB_DEVICE_EVENT_POWER_DETECTED:
        {
            // This event in generated when VBUS is detected. Attach the device
            USB_DEVICE_Attach(appData.usbDeviceHandle);
            break;
        }

        case USB_DEVICE_EVENT_CONTROL_TRANSFER_DATA_SENT:
        {
            // This event indicates that a Control transfer Data has been sent to Host.
            break;
        }

        case USB_DEVICE_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:
        {
            // This event indicates that a Control transfer Data has been received from Host.
            break;
        }

        case USB_DEVICE_EVENT_CONTROL_TRANSFER_ABORTED:
        {
            // This event indicates a control transfer was aborted.
            break;
        }

        case USB_DEVICE_EVENT_ERROR:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
#endif

/* TODO:  Add any necessary callback functions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
 */


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

//uint8_t* i2cTxBuffer[MAX_NUMBER_OF_BUFFERS];

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

#if defined(ENABLE_USB)
    appData.usbDeviceHandle = USB_DEVICE_HANDLE_INVALID;
    appData.deviceConfigured = false;
    appData.txTransferHandle = USB_DEVICE_HID_TRANSFER_HANDLE_INVALID;
    appData.rxTransferHandle = USB_DEVICE_HID_TRANSFER_HANDLE_INVALID;
    appData.hidDataReceived = false;
    appData.hidDataTransmitted = true;
    appData.receiveDataBuffer = &receiveDataBuffer[0];
    appData.transmitDataBuffer = &transmitDataBuffer[0];
#endif

#if defined(ENABLE_485)    
    appData.rs485Handle = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
#endif

#if defined(ENABLE_232)
    appData.rs232Handle = DRV_USART_Open(DRV_USART_INDEX_1, DRV_IO_INTENT_READWRITE);
#endif

#if defined(ENABLE_I2C)
    //    uint8_t i2cTxBuffer[0] = 
#endif

}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void) {

    /* Check the application's current state. */
    switch (appData.state) {
            /* Application's initial state. */
        case APP_STATE_INIT:
        {
#if defined(ENABLE_USB)
            APP_USB_Init();
#endif
#if defined(ENABLE_I2C)
            APP_I2C_Init();
#endif
#if defined(ENABLE_232)
            APP_232_Init();
#endif
#if defined(ENABLE_485)
            APP_485_Init();
#endif

            appData.appInitialized = true;

            if (appData.appInitialized) {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_WAIT_FOR_CONFIGURATION:
        {

#if defined(ENABLE_USB)
            APP_USB_WaitForConfiguration();
#endif
            break;
        }

        case APP_STATE_MAIN_TASK:
        {
#if defined(ENABLE_USB)
            APP_USB_Tasks();
#endif
        }

        case APP_STATE_ERROR:
        {
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {

            break;
        }

            /* TODO: implement your application state machine.*/


            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
#if defined(ENABLE_485)
    APP_485_Tasks();
#endif

#if defined(ENABLE_232)
    APP_232_Tasks();
#endif

#if defined(ENABLE_I2C)
    APP_I2C_Tasks();
#endif

}

#if defined(ENABLE_USB)

void APP_USB_Init() {
    /* Open the device layer */
    appData.usbDeviceHandle = USB_DEVICE_Open(USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE);

    if (appData.usbDeviceHandle != USB_DEVICE_HANDLE_INVALID) {
        /* Register a callback with device layer to get event notification (for end point 0) */
        USB_DEVICE_EventHandlerSet(appData.usbDeviceHandle, APP_USBDeviceEventHandler, 0);

        appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
    } else {
        /* The Device Layer is not ready to be opened. We should try
         * again later. */
    }
}

void APP_USB_WaitForConfiguration() {
    if (appData.deviceConfigured == true) {
        /* Device is ready to run the main task */
        appData.hidDataReceived = false;
        appData.hidDataTransmitted = true;
        appData.state = APP_STATE_MAIN_TASK;

        /* Place a new read request. */
        USB_DEVICE_HID_ReportReceive(USB_DEVICE_HID_INDEX_0,
                &appData.rxTransferHandle, appData.receiveDataBuffer, 64);
    }
}

void APP_USB_Tasks() {
    if (!appData.deviceConfigured) {
        /* Device is not configured */
        appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
    } else if (appData.hidDataReceived) {
        /* Look at the data the host sent, to see what
         * kind of application specific command it sent. */

        switch (appData.receiveDataBuffer[0]) {
            case 0x80:
            {

                //                        /* Toggle on board LED1 to LED2. */
                //                        BSP_LEDToggle(APP_USB_LED_1);
                //                        BSP_LEDToggle(APP_USB_LED_2);
                //
                //                        appData.hidDataReceived = false;
                //
                //                        /* Place a new read request. */
                //                        USB_DEVICE_HID_ReportReceive(USB_DEVICE_HID_INDEX_0,
                //                                &appData.rxTransferHandle, appData.receiveDataBuffer, 64);

                break;
            }

            case 0x81:
            {

                //                        if (appData.hidDataTransmitted) {
                //                            /* Echo back to the host PC the command we are fulfilling in
                //                             * the first byte.  In this case, the Get Push-button State
                //                             * command. */
                //
                //                            appData.transmitDataBuffer[0] = 0x81;
                //
                //                            if (BSP_SwitchStateGet(APP_USB_SWITCH_1) == BSP_SWITCH_STATE_PRESSED) {
                //                                appData.transmitDataBuffer[1] = 0x00;
                //                            } else {
                //                                appData.transmitDataBuffer[1] = 0x01;
                //                            }
                //
                //                            appData.hidDataTransmitted = false;
                //
                //                            /* Prepare the USB module to send the data packet to the host */
                //                            USB_DEVICE_HID_ReportSend(USB_DEVICE_HID_INDEX_0,
                //                                    &appData.txTransferHandle, appData.transmitDataBuffer, 64);
                //
                //                            appData.hidDataReceived = false;
                //
                //                            /* Place a new read request. */
                //                            USB_DEVICE_HID_ReportReceive(USB_DEVICE_HID_INDEX_0,
                //                                    &appData.rxTransferHandle, appData.receiveDataBuffer, 64);
                //                        }
                break;
            }

            default:
            {

                appData.hidDataReceived = false;

                /* Place a new read request. */
                USB_DEVICE_HID_ReportReceive(USB_DEVICE_HID_INDEX_0,
                        &appData.rxTransferHandle, appData.receiveDataBuffer, 64);
                break;
            }
        }
    }
}
}
#endif

#if defined(ENABLE_232)

void APP_232_Tasks() {
    switch (appData.state) {
        case APP_STATE_232TX:
        {
            APP_send232(appData.tx232Buffer, true);
            break;
        }

        case APP_STATE_485RX:
        {
            switch (appData.rx232Buffer[0]) { // start code for received 232 data.
                    // do something with it
                case DATA_NO_DATA:
                {
                    break;
                }
                default:
                    break;
            }
            break;
        }
    }
}

#endif

#if defined(ENABLE_485)

void APP_485_Tasks() {
    switch (appData.state) {
        case APP_STATE_485TX:
        {
            APP_send485(appData.tx485Buffer, true);
            break;
        }

        case APP_STATE_485RX:
        {
            //            switch (appData.rx485Buffer[0]) { // start code for received 485 data.
            //                    // do something with it
            //                case DATA_NO_DATA:
            //                {
            //                    break;
            //                }
            //                default:
            //                    break;
            //            }
            break;
        }
    }
}
#endif

#if defined(ENABLE_I2C)

OPCODE opcode;

void APP_I2C_Init() {
    IOCON iocon;
    uint8_t txBuffer[2];

    iocon.status = 0; // initialise to 0.
    iocon.bits.BANK = 1; //  Separate banks
    iocon.bits.MIRROR = 1; // Interrupts are OR'd.
    iocon.bits.SEQOP = 1; // BYTE operation
    iocon.bits.DISSLW = 0; // Slew rate control enabled
    iocon.bits.HAEN = 1; // Hardware address enabled.
    iocon.bits.ODR = 0; // Active outputs.
    iocon.bits.INTPOL = 1; // Active high outputs.

    // create the device address opcode for first input expander
    initIOExpander(APP_INPUT_EXPANDER_0, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]); // Set up the IO Control Register
    initIOExpander(APP_INPUT_EXPANDER_1, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_2, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_3, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_0, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_1, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_2, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_3, IOCONA, iocon, IOCONB, iocon, &txBuffer[0]);
    // then the IO Direction
    initIOExpander(APP_INPUT_EXPANDER_0, IODIRA, 0xF, IODIRB, 0xF, &txBuffer[0]); // Set all GPIO pins to Inputs.
    initIOExpander(APP_INPUT_EXPANDER_1, IODIRA, 0xF, IODIRB, 0xF, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_2, IODIRA, 0xF, IODIRB, 0xF, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_3, IODIRA, 0xF, IODIRB, 0xF, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_0, IODIRA, 0x0, IODIRB, 0x0, &txBuffer[0]); // Set all GPIO pins to Outputs.
    initIOExpander(APP_OUTPUT_EXPANDER_1, IODIRA, 0x0, IODIRB, 0x0, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_2, IODIRA, 0x0, IODIRB, 0x0, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_3, IODIRA, 0x0, IODIRB, 0x0, &txBuffer[0]);
    // then the IO Polarity
    initIOExpander(APP_INPUT_EXPANDER_0, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]); // Set all GPIO pins to normal Polarity.
    initIOExpander(APP_INPUT_EXPANDER_1, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_2, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_3, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_0, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]); // Outputs Don't care
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_1, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_2, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_3, IOPOLA, 0x0, IOPOLB, 0x0, &txBuffer[0]);
    // then the GP Interrupt Enable
    initIOExpander(APP_INPUT_EXPANDER_0, GPINTENA, 0xF, GPINTENB, 0xF, &txBuffer[0]); // Set all Input Interrupts pins to Enabled.
    initIOExpander(APP_INPUT_EXPANDER_1, GPINTENA, 0xF, GPINTENB, 0xF, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_2, GPINTENA, 0xF, GPINTENB, 0xF, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_3, GPINTENA, 0xF, GPINTENB, 0xF, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_0, GPINTENA, 0x0, GPINTENB, 0x0, &txBuffer[0]); // Disable interrupts on outputs
    initIOExpander(APP_OUTPUT_EXPANDER_1, GPINTENA, 0x0, GPINTENB, 0x0, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_2, GPINTENA, 0x0, GPINTENB, 0x0, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_3, GPINTENA, 0x0, GPINTENB, 0x0, &txBuffer[0]);
    // then the IO Default value - not set as we aren't using it
    //    APP_I2C_Init_Registers(APP_INPUT_EXPANDER_0, DEFVALA, 0x0, DEFVALB, 0x0, &txBuffer[0]); // Set all interrupts to value change.
    //    APP_I2C_Init_Registers(APP_INPUT_EXPANDER_1, DEFVALA, 0x0, DEFVALB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_INPUT_EXPANDER_2, DEFVALA, 0x0, DEFVALB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_INPUT_EXPANDER_3, DEFVALA, 0x0, DEFVALB, 0x0, &txBuffer[0]);
    // then the IO Interrupt Control
    initIOExpander(APP_INPUT_EXPANDER_0, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]); // Set all interrupts to value change.
    initIOExpander(APP_INPUT_EXPANDER_1, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_2, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_3, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_0, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]); // Interrupts are disabled
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_1, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_2, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]);
    //    APP_I2C_Init_Registers(APP_OUTPUT_EXPANDER_3, INTCONA, 0x0, INTCONB, 0x0, &txBuffer[0]);
    // then the IO Interrupt Control
    initIOExpander(APP_INPUT_EXPANDER_0, GPPUA, 0xF, GPPUB, 0xF, &txBuffer[0]); // Enable all pull up resistors.
    initIOExpander(APP_INPUT_EXPANDER_1, GPPUA, 0xF, GPPUB, 0xF, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_2, GPPUA, 0xF, GPPUB, 0xF, &txBuffer[0]);
    initIOExpander(APP_INPUT_EXPANDER_3, GPPUA, 0xF, GPPUB, 0xF, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_0, GPPUA, 0x0, GPPUB, 0x0, &txBuffer[0]); // Disable all pull up resistors.
    initIOExpander(APP_OUTPUT_EXPANDER_1, GPPUA, 0x0, GPPUB, 0x0, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_2, GPPUA, 0x0, GPPUB, 0x0, &txBuffer[0]);
    initIOExpander(APP_OUTPUT_EXPANDER_3, GPPUA, 0x0, GPPUB, 0x0, &txBuffer[0]);
    
    initDAC();
    
}

void initIOExpander(uint8_t code,
        uint8_t registerA, uint8_t valueA,
        uint8_t registerB, uint8_t valueB,
        void* buffer) {
    opcode = code;
    opcode.bits.rw = IOEXPANDER_WRITE;
    buffer[0] = registerA; // first byte is the address
    buffer[1] = valueA; // second byte is the data
    writeI2C(opcode, &buffer[0], 2);
    buffer[0] = registerB;
    buffer[1] = valueB;
    writeI2C(opcode, &buffer[0], 2);
}

void initDAC() {
    DAC_VREF vRef;
    DAC_POWERDOWN pDown;
    
    // VDD for reference
    vRef.bits.VR0A = 0;
    vRef.bits.VR0B = 0;
    vRef.bits.VR1A = 0;
    vRef.bits.VR0B = 0;
}

void APP_I2C_Tasks() {
    switch (appData.state) {
        case APP_STATE_READ_INPUT_0:
        {
            getInputRegister(APP_INPUT_EXPANDER_0, GPIOA);
            // TODO deal with first buffer of data in i2cRxBuffer.
            getInputRegister(APP_INPUT_EXPANDER_0, GPIOB);
            // TODO deal with first buffer of data in i2cRxBuffer.
            break;
        }

        case APP_STATE_READ_INPUT_1:
        {
            getInputRegister(APP_INPUT_EXPANDER_1, GPIOA);
            // TODO deal with first buffer of data in i2cRxBuffer.
            getInputRegister(APP_INPUT_EXPANDER_1, GPIOB);
            // TODO deal with first buffer of data in i2cRxBuffer.
            break;
        }

        case APP_STATE_READ_INPUT_2:
        {
            getInputRegister(APP_INPUT_EXPANDER_2, GPIOA);
            // TODO deal with first buffer of data in i2cRxBuffer.
            getInputRegister(APP_INPUT_EXPANDER_2, GPIOB);
            // TODO deal with first buffer of data in i2cRxBuffer.
            break;
        }

        case APP_STATE_READ_INPUT_3:
        {
            getInputRegister(APP_INPUT_EXPANDER_3, GPIOA);
            // TODO deal with first buffer of data in i2cRxBuffer.
            getInputRegister(APP_INPUT_EXPANDER_3, GPIOB);
            // TODO deal with first buffer of data in i2cRxBuffer.
            break;
        }
        case APP_STATE_WRITE_OUTPUT_0:
        {
            setOutputRegister(APP_OUTPUT_EXPANDER_0, GPIOA, i2cTxBuffer[1], 1); // first byte in i2CTxBuffer[0]]
            setOutputRegister(APP_OUTPUT_EXPANDER_0, GPIOB, i2cTxBuffer[2], 1); // second byte in i2cTxBuffer[1]
            break;
        }
        case APP_STATE_WRITE_OUTPUT_1:
        {
            setOutputRegister(APP_OUTPUT_EXPANDER_1, GPIOA, i2cTxBuffer[1], 1); // first byte in i2CTxBuffer[0]]
            setOutputRegister(APP_OUTPUT_EXPANDER_1, GPIOB, i2cTxBuffer[2], 1); // second byte in i2cTxBuffer[1]
            // TODO output 2
            break;
        }
        case APP_STATE_WRITE_OUTPUT_2:
        {
            setOutputRegister(APP_OUTPUT_EXPANDER_2, GPIOA, i2cTxBuffer[1], 1); // first byte in i2CTxBuffer[0]]
            setOutputRegister(APP_OUTPUT_EXPANDER_2, GPIOB, i2cTxBuffer[2], 1); // second byte in i2cTxBuffer[1]
            break;
        }
        case APP_STATE_WRITE_OUTPUT_3:
        {
            setOutputRegister(APP_OUTPUT_EXPANDER_3, GPIOA, i2cTxBuffer[1], 1); // first byte in i2CTxBuffer[0]]
            setOutputRegister(APP_OUTPUT_EXPANDER_3, GPIOB, i2cTxBuffer[2], 1); // second byte in i2cTxBuffer[1]
            break;
        }
        case APP_STATE_WRITE_DAC:
        {

            //            setOutputRegister(APP_OUTPUT_EXPANDER_3, GPIOA, i2cTxBuffer[0], 1); // first byte in i2CTxBuffer[0]]
            //            setOutputRegister(APP_OUTPUT_EXPANDER_3, GPIOB, i2cTxBuffer[1], 1); // second byte in i2cTxBuffer[1]
            break;
        }
    }
}

void setDacValue(uint16_t deviceAddress, uint8_t regId, uint16_t value) {
    DAC_ADDRESS address;
    DAC_COMMAND command;
    DAC_DATA data;
    
    address.address = deviceAddress; // LAlready left shifted.

    command.byte.UNUSED = 0x0; // Unused set to 0 for safety
    command.byte.command = 0x0; // 0b00 = write
    command.byte.address = regId;
}

/*!
 * \brief Get the 8-bit register value from the IO Expander chips.
 * 
 * The IO Expander chips contain two 8-bit values (either input or output or mixed).
 * This function recovers one register value, which defined by the value of regId.
 * The value of device address contains the 7-bit address for the required IO
 * Expander chip plus the write bit. Data is returned in the i2cRxBuffer variable. 
 * 
 * \param deviceAddress a 8-bit chip address. these are set in hardware.
 * \param regId 8-bit register address (either GPIOA or GPIOB)
 * 
 */
void getInputRegister(uint8_t deviceAddress, uint8_t regId) {
    i2cTxBuffer[0] = regId;
    readWriteI2c(deviceAddress, &i2cTxBuffer[0], 1, &i2cRxBuffer[0], 1);
}

void setOutputRegister(uint16_t deviceAddress, uint8_t regId, void* txBuffer, int count) {
    i2cTxBuffer[0] = regId;
    writeI2c(deviceAddress, &txBuffer[0], count);
}
#endif

#if defined(ENABLE_485)

void APP_send485(char data[64], bool crlf) {
    int i = 0;
    while (data[i] != '\0') {
        DRV_USART_WriteByte(appData.rs485Handle, data[i]);
        i++;
    }
    if (crlf) {
        DRV_USART_WriteByte(appData.rs485Handle, '\r');
        DRV_USART_WriteByte(appData.rs485Handle, '\n');
    }
}

void APP_get485String(char *buffer) {
    int i = 0;
    while (true) {
        if (!DRV_USART_ReceiverBufferIsEmpty(appData.rs485Handle)) {
            *(buffer + i) = DRV_USART_ReadByte(appData.rs485Handle);
            if (*(buffer + i) == '\n') break;
            i++;
        }
    }
}
#endif

#define GetSystemClock() (SYS_CLK_FREQ)
#define us_SCALE   (GetSystemClock()/2000000)
#define ms_SCALE   (GetSystemClock()/2000)

static uint32_t ReadCoreTimer(void);

static uint32_t ReadCoreTimer() {
    volatile uint32_t timer;

    // get the count reg
    asm volatile("mfc0   %0, $9" : "=r"(timer));

    return (timer);
}

/***********************************************************
 *   Millisecond Delay function using the Count register
 *   in coprocessor 0 in the MIPS core.
 *   When running 200 MHz, CoreTimer frequency is 100 MHz
 *   CoreTimer increments every 2 SYS_CLK, CoreTimer period = 10ns
 *   1 ms = N x CoreTimer_period;
 *   To count 1ms, N = 100000 counts of CoreTimer
 *   1 ms = 10 ns * 100000 = 10e6 ns = 1 ms
 *   When running 80 MHz, CoreTimer frequency is 40 MHz 
 *   CoreTimer increments every 2 SYS_CLK, CoreTimer period = 25ns
 *   To count 1ms, N = 40000 counts of CoreTimer
 *   1ms = 25 ns * 40000 = 10e6 ns = 1 ms
 *   ms_SCALE = (GetSystemClock()/2000) @ 200 MHz = 200e6/2e3 = 100e3 = 100000
 *   ms_SCLAE = (GetSystemClock()/2000) @ = 80e6/2e3 = 40e3 = 40000 
 */

void DelayMs(unsigned long int msDelay) {
    register unsigned int startCntms = ReadCoreTimer();
    register unsigned int waitCntms = msDelay * ms_SCALE;

    while (ReadCoreTimer() - startCntms < waitCntms);
}

/***********************************************************
 *   Microsecond Delay function using the Count register
 *   in coprocessor 0 in the MIPS core.
 *   When running 200 MHz, CoreTimer frequency is 100 MHz
 *   CoreTimer increments every 2 SYS_CLK, CoreTimer period = 10ns
 *   1 us = N x CoreTimer_period;
 *   To count 1us, N = 100 counts of CoreTimer
 *   1 us = 10 ns * 100 = 1000 ns  = 1us
 *   When running 80 MHz, CoreTimer frequency is 40 MHz 
 *   CoreTimer increments every 2 SYS_CLK, CoreTimer period = 25ns
 *   To count 1us, N = 40 counts of CoreTimer
 *   1us = 25 ns * 40 = 1000 ns = 1 us
 *   us_SCALE = (GetSystemClock()/2000) @ 200 MHz = 200e6/2e6 = 100 
 *   us_SCLAE = (GetSystemClock()/2000) @ 80 MHz = 80e6/2e6 = 40 
 */

void DelayUs(unsigned long int usDelay) {
    register unsigned int startCnt = ReadCoreTimer();
    register unsigned int waitCnt = usDelay * us_SCALE;

    while (ReadCoreTimer() - startCnt < waitCnt);
}

#if defined(ENABLE_232)

void APP_send232(char data[64], bool crlf) {
    int i = 0;
    while (data[i] != '\0') {
        DRV_USART_WriteByte(appData.rs232Handle, data[i]);
        i++;
    }
    if (crlf) {
        DRV_USART_WriteByte(appData.rs232Handle, '\r');
        DRV_USART_WriteByte(appData.rs232Handle, '\n');
    }
}

void APP_get232String(char *buffer) {
    int i = 0;
    while (true) {
        if (!DRV_USART_ReceiverBufferIsEmpty(appData.rs232Handle)) {
            *(buffer + i) = DRV_USART_ReadByte(appData.rs232Handle);
            if (*(buffer + i) == '\n') break;
            i++;
        }
    }
}
#endif

/*******************************************************************************
 End of File
 */
