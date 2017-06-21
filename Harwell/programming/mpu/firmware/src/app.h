/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialise" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

/*! \file app.h
    \brief Contains all the general application code.
    
 All functions that run the application are stored here. Specific code
 for I2C, SPI etc are stored in specialised files.
 */

#ifndef _APP_H
#    define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#    include <stdint.h>
#    include <stdbool.h>
#    include <stddef.h>
#    include <stdlib.h>
#    include "system_config.h"
#    include "system_definitions.h"
#    include "lintott.h"
#    include "global.h"
#    include "i2c.h"

// DOM-IGNORE-BEGIN
#    ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#    endif

    // DOM-IGNORE-END 

    // *****************************************************************************
    // *****************************************************************************
    // Section: Type Definitions
    // *****************************************************************************
    // *****************************************************************************

    // *****************************************************************************


#    define MAX_NUMBER_OF_BUFFERS 7

    /*
     * MPC23107 IO Expander IC's.
     * Communication protocol : I2C
     * 16 Channel input or output.
     * 
     * I2C controlled slave input expander IC's
     * and external DAC addresses.
     * These addresses are already left shifted by one
     * position (lowest bit is read/write flag).
     * 
     * Hardware addresses are actually 7 bit addresses. The
     * top 4 bits are set by the manufacturer (usually 0100
     * unless otherwise requested). The next 3 bits are defined
     * by the levels of pins A0-A2. The last bit is a R/W flag,
     * 0 for read, 1 for write.
     */
    /*! hardware address for Input Expander 0 */
#    define APP_INPUT_EXPANDER_0        0x40
    /*! hardware address for Input Expander 1 */
#    define APP_INPUT_EXPANDER_1        0x42
    /*! hardware address for Input Expander 2 */
#    define APP_INPUT_EXPANDER_2        0x44
    /*! hardware address for Input Expander 3 */
#    define APP_INPUT_EXPANDER_3        0x46
    /*! hardware address for Output Expander 0 */
#    define APP_OUTPUT_EXPANDER_0       0x49 // includes write bit
    /*! hardware address for Output Expander 1 */
#    define APP_OUTPUT_EXPANDER_1       0x4B // includes write bit
    /*! hardware address for Output Expander 2 */
#    define APP_OUTPUT_EXPANDER_2       0x4D // includes write bit
    /*! hardware address for Output Expander 3 */
#    define APP_OUTPUT_EXPANDER_3       0x4F // includes write bit

    /*! hardware address for DAC chip */
#    define APP_OUTPUT_DAC              0xC0 // 0x60 left shifted 1 place for R/W bit

#    define IOEXPANDER_WRITE 1
#    define IOEXPANDER_READ  0

    // MCP23X17 IO Expander register addresses

    /*
     * opcode store.
     */
    typedef union {
        uint8_t code;

        struct {
            uint8_t address : 7;
            uint8_t rw : 1;
        } bits;
    } OPCODE;

    /*
     * setup data.
     */
    typedef union {
        uint8_t status;

        struct {
            uint8_t UNUSED : 1;
            uint8_t INTPOL : 1;
            uint8_t ODR : 1;
            uint8_t HAEN : 1;
            uint8_t DISSLW : 1;
            uint8_t SEQOP : 1;
            uint8_t MIRROR : 1;
            uint8_t BANK : 1;
        } bits;
    } IOCON;

    typedef union {
        uint8_t address;

        struct {
            uint8_t address : 7;
            uint8_t ReadWrite : 1;
        } bits;
    } DAC_ADDRESS;

    typedef union {
        uint8_t data;

        struct {
            uint8_t address : 5;
            uint8_t command : 2;
            uint8_t UNUSED : 1;
        } byte;
    } DAC_COMMAND;

    typedef union {
        uint16_t data;
        //        struct {
        //            uint8_t upper;
        //            uint8_t lower;
        //        } bytes;

        struct {
            uint8_t UNUSED : 4;
            uint8_t lower : 12;
        };
    } DAC_DATA;

    typedef union {
        uint16_t status;

        struct {
            uint16_t UNUSED : 12;
            uint8_t VR1B : 1;
            uint8_t VR1A : 1;
            uint8_t VR0B : 1;
            uint8_t VR0A : 1;
        } bits;

        struct {
            uint16_t UNUSED : 12;
            uint8_t VR1 : 2;
            uint8_t VR0 : 2;
        } vref;
    } DAC_VREF;

#    define DAC_VREF_UNBUFFERED 0x0
#    define DAC_VREF_BUFFERED   0x1
#    define DAC_INT_BAND_GAP    0x2
#    define DAC_VDD             0x3

    typedef union {
        uint16_t status;

        struct {
            uint16_t UNUSED : 12;
            uint8_t PB1B : 1;
            uint8_t PB1A : 1;
            uint8_t PB0B : 1;
            uint8_t PB0A : 1;
        } bits;

        struct {
            uint16_t UNUSED : 12;
            uint8_t PB1 : 2;
            uint8_t PB0 : 2;
        } vref;
    } DAC_POWERDOWN;

#    define DAC_PD_NORMAL_OPERATION 0x0
#    define DAC_PD_ROUT_1K          0x1
#    define DAC_PD_ROUT_100K        0x2
#    define DAC_PD_OPEN_CCT         0x3

    /*
     * The BANK flag changes the registers from individual reagisters to consecutive.
     * If the IOCON BANK flag is set to 0 the various registers are renumbered.
     * However as the renumbering only takes place AFTER the values are changed.
     * it is only recommended for writes not reads. 
     * 
     * comment out BANK_1 if you intend to set BABK to 0.
     */
#    define BANK_1 // The IOCON BANK Flag.
#    if defined(BANK_1)
#        define GPIOA                       0x09 // Read Port 
#        define GPIOB                       0x19 
#        define OLATA                       0x0A // Write Port 
#        define OLATB                       0x1A 
#        define IODIRA                      0x00 // IO Direction 
#        define IODIRB                      0x10 
#        define IOPOLA                      0x01 // IO Polarity
#        define IOPOLB                      0x11
#        define GPINTENA                    0x02 // GPIO Interrupt enable
#        define GPINTENB                    0x12
#        define DEFVALA                     0x03 // Default Comparison Value (Only used if INTCON=1)
#        define DEFVALB                     0x13
#        define GPPUA                       0x06 // GPIO Pullu Resistor Enable
#        define GPPUB                       0x16
#        define INTFA                       0x07 // Interrupt value. Shows value at interrupt
#        define INTFB                       0x17
#        define INTCAPA                     0x08 // Interrupt Capture.
#        define INTCAPB                     0x18
#        define INTCONA                     0x04 // Interrupt Control
#        define INTCONB                     0x14
#        define IOCONA                      0x05 // IO Control
#        define IOCONB                      0x15
#    else
#        define GPIOA                       0x12 
#        define GPIOB                       0x13 
#        define OLATA                       0x14
#        define OLATB                       0x15
#        define IODIRA                      0x00
#        define IODIRB                      0x01
#        define IOPOLA                      0x02
#        define IOPOLB                      0x03
#        define GPINTENA                    0x04
#        define GPINTENB                    0x05
#        define DEFVALA                     0x06
#        define DEFVALB                     0x07
#        define GPPUA                       0x0C
#        define GPPUB                       0x0D
#        define INTFA                       0x0E
#        define INTFB                       0x0F
#        define INTCAPA                     0x10
#        define INTCAPB                     0x11
#        define INTCONA                     0x08
#        define INTCONB                     0x09
#        define IOCONA                      0x0A
#        define IOCONB                      0x0B
#    endif

    /* Application states

      Summary:
        Application states enumeration

      Description:
        This enumeration defines the valid application states.  These states
        determine the behavior of the application at various times.
     */

    typedef enum {
        /* Application's state machine's initial state. */
        APP_STATE_INIT = 0,
        APP_STATE_SERVICE_TASKS,
        APP_STATE_WAIT_FOR_CONFIGURATION,

        /* Application is running the main tasks */
        APP_STATE_MAIN_TASK,

#    if defined(ENABLE_485)
        /* USART Stuff */
        APP_STATE_485TX, // USART transmit state
        APP_STATE_485RX, // USART receive state
#    endif

#    if defined (ENABLE_232)
        /* USART Stuff */
        APP_STATE_232TX, // USART transmit state
        APP_STATE_232RX, // USART receive state
#    endif

#    if defined(ENABLE_I2C)
        APP_STATE_READ_INPUT_0,
        APP_STATE_READ_INPUT_1,
        APP_STATE_READ_INPUT_2,
        APP_STATE_READ_INPUT_3,
        APP_STATE_WRITE_OUTPUT_0,
        APP_STATE_WRITE_OUTPUT_1,
        APP_STATE_WRITE_OUTPUT_2,
        APP_STATE_WRITE_OUTPUT_3,
        APP_STATE_WRITE_DAC,
#    endif

        /* Application is in an error state */
        APP_STATE_ERROR,

        /* TODO: Define states used by the application state machine. */

    } APP_STATES;

    /*
     * setup data.
     */
    typedef union {
        uint8_t status;

        struct {
            uint8_t UNUSED : 1;
            uint8_t INTPOL : 1;
            uint8_t ODR : 1;
            uint8_t HAEN : 1;
            uint8_t DISSLW : 1;
            uint8_t SEQOP : 1;
            uint8_t MIRROR : 1;
            uint8_t BANK : 1;
        } bits;
    } IOCON;

    // *****************************************************************************

    /* Application Data

      Summary:
        Holds application data

      Description:
        This structure holds the application's data.

      Remarks:
        Application strings and buffers are be defined outside this structure.
     */

    typedef struct {
        /* The application's current state */
        APP_STATES state;

        bool appInitialized;

#    if defined(ENABLE_USB)
        /* Device layer handle returned by device layer open function */
        USB_DEVICE_HANDLE usbDeviceHandle;

        /* Receive data buffer */
        uint8_t * receiveDataBuffer;

        /* Transmit data buffer */
        uint8_t * transmitDataBuffer;

        /* Device configured */
        bool deviceConfigured;

        /* Send report transfer handle*/
        USB_DEVICE_HID_TRANSFER_HANDLE txTransferHandle;

        /* Receive report transfer handle */
        USB_DEVICE_HID_TRANSFER_HANDLE rxTransferHandle;

        /* Configuration value selected by the host*/
        uint8_t configurationValue;

        /* HID data received flag*/
        bool hidDataReceived;

        /* HID data transmitted flag */
        bool hidDataTransmitted;

        /* USB HID current Idle */
        uint8_t idleRate;
#    endif

        /* TODO: Define any additional data used by the application. */
#    if defined(ENABLE_485)
        DRV_HANDLE rs485Handle;
        char rx485Buffer[64]; // RS485 byte received
        char tx485Buffer[64]; // RS485 byte to send
#    endif

#    if defined(ENABLE_I2C)
        DRV_HANDLE i2cMasterHandle;
        DRV_HANDLE i2cSlaveHandle;
        DRV_I2C_BUFFER_EVENT i2cOperationStatus;
        DRV_I2C_BUFFER_HANDLE i2cTxBufferHandle[MAX_NUMBER_OF_BUFFERS];
        DRV_I2C_BUFFER_HANDLE i2cRxBufferHandle[MAX_NUMBER_OF_BUFFERS];
        DRV_I2C_BUFFER_HANDLE i2cSlaveReadHandle;
        DRV_I2C_BUFFER_HANDLE i2cSlaveWriteHandle;
        IOCON iexp_iocon;
        IOCON oexp_iocon;
        OPCODE ioexp_opcode;
#    endif

#    if defined(ENABLE_232)
        DRV_HANDLE rs232Handle;
        char rx232Buffer[64]; // RS232 byte received
        char tx232Buffer[64]; // RS232 byte to send
#    endif        

        /*
         * Application data.
         */

    } APP_DATA;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Callback Routines
    // *****************************************************************************
    // *****************************************************************************
    /* These routines are called by drivers when certain events occur.
     */

    // *****************************************************************************
    // *****************************************************************************
    // Section: Application Initialization and State Machine Functions
    // *****************************************************************************
    // *****************************************************************************

    /*******************************************************************************
      Function:
        void APP_Initialize ( void )

      Summary:
         MPLAB Harmony application initialization routine.

      Description:
        This function initializes the Harmony application.  It places the 
        application in its initial state and prepares it to run so that its 
        APP_Tasks function can be called.

      Precondition:
        All other system initialization routines should be called before calling
        this routine (in "SYS_Initialize").

      Parameters:
        None.

      Returns:
        None.

      Example:
        <code>
        APP_Initialize();
        </code>

      Remarks:
        This routine must be called from the SYS_Initialize function.
     */

    void APP_Initialize(void);


    /*******************************************************************************
      Function:
        void APP_Tasks ( void )

      Summary:
        MPLAB Harmony Demo application tasks function

      Description:
        This routine is the Harmony Demo application's tasks function.  It
        defines the application's state machine and core logic.

      Precondition:
        The system and application initialization ("SYS_Initialize") should be
        called before calling this.

      Parameters:
        None.

      Returns:
        None.

      Example:
        <code>
        APP_Tasks();
        </code>

      Remarks:
        This routine must be called from SYS_Tasks() routine.
     */

    void APP_Tasks(void);

#    if defined(ENABLE_I2C)
    void APP_I2C_Tasks();
    void APP_I2C_Init();
    
    void initIOExpander(uint8_t code,
            uint8_t registerA, uint8_t valueA,
            uint8_t registerB, uint8_t valueB,
            void* buffer);
    void getInputRegister(uint16_t deviceAddress, uint8_t regId);
    void setOutputRegister(uint16_t deviceAddress, uint8_t regId);

    void initDAC();
    void setDacValue(uint16_t deviceAddress, uint8_t regId, uint16_t value);

#    endif
#    if defined(ENABLE_485)
    void APP_485_Tasks();
    void APP_485_Init();
#    endif
#    if defined(ENABLE_232)
    void APP_232_Tasks();
    void APP_232_Init();
#    endif
#    if defined(ENABLE_USB)
    void APP_USB_Tasks();
    void APP_USB_WaitForConfiguration();
    void APP_USB_Init();
#    endif

#    if defined(ENABLE_USB)
    USB_DEVICE_HID_EVENT_RESPONSE APP_USBDeviceHIDEventHandler(
            USB_DEVICE_HID_INDEX iHID,
            USB_DEVICE_HID_EVENT event,
            void * eventData,
            uintptr_t userData
            );
#    endif

#    if defined(ENABLE_485)
    void APP_send485(char data[64], bool crlf);
    void APP_get485String(char *buffer);
#    endif

#    if defined(ENABLE_232)
    void APP_send232(char data[64], bool crlf);
    void APP_get232String(char *buffer);
#    endif

    void DelayMs(unsigned long int msDelay);
    void DelayUs(unsigned long int usDelay);

#endif /* _APP_H */

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

