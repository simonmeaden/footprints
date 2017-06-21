#include "i2c.h"


char i2cWriteBuffer[64], i2cReadBuffer[64];

void openI2C() {
    appData.i2cMasterHandle = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT::DRV_IO_INTENT_READWRITE);

    if (appData.i2cMasterHandle == DRV_HANDLE_INVALID) {
        // TODO do error shit here
    } else {
        DRV_I2C_BufferEventHandlerSet(appData.i2cMasterHandle,
                i2CBufferEventFunction,
                appData.i2cOperationStatus);
    }
}

void closeI2C() {
    if (appData.i2cMasterHandle != DRV_HANDLE_INVALID) {
        DRV_I2C_Close(appData.i2cMasterHandle);
    }
}

void startI2C() {
    if (appData.i2cMasterHandle != DRV_HANDLE_INVALID) {

    }
}

void stopI2C() {
    if (appData.i2cMasterHandle != DRV_HANDLE_INVALID) {

    }
}


void writeI2C(uint16_t deviceAddress,
        void *writeBuffer, size_t writeSize) {
    SYS_STATUS status = DRV_I2C_Status(sysObj.drvI2C0);
    if (status == SYS_STATUS_READY) {
        /*drvI2CWRBUFHandle =*/ DRV_I2C_Transmit(
                appData.i2cMasterHandle,
                deviceAddress,
                writeBuffer,
                writeSize,
                NULL);
    }
}

void readWriteI2c(uint16_t deviceAddress,
        void *writeBuffer, size_t writeSize,
        void *readBuffer, size_t readSize) {
    if (appData.i2cMasterHandle != DRV_HANDLE_INVALID) {
        SYS_STATUS status = DRV_I2C_Status(sysObj.drvI2C0);

        if (status == SYS_STATUS_READY) {
            /*appData.i2cTxBufferHandle[] =*/ DRV_I2C_TransmitThenReceive(
                    appData.i2cMasterHandle,
                    deviceAddress,
                    writeBuffer,
                    writeSize,
                    readBuffer,
                    readSize,
                    NULL);
        }
    }
}

void readI2c(uint16_t deviceAddress,
        void *writeBuffer, size_t writeSize) {
//    if (appData.i2cMasterHandle != DRV_HANDLE_INVALID) {
//        SYS_STATUS status = DRV_I2C_Status(sysObj.drvI2C0);
//
//        if (status == SYS_STATUS_READY) {
//            /*drvI2CRDBUFHandle =*/ DRV_I2C_Transmit(
//                    appData.i2cMasterHandle,
//                    deviceAddress,
//                    writeBuffer, writeSize,
//                    NULL);
//        }
//    }
}

/*
 * Callback function for 
 */
void i2CBufferEventFunction(DRV_I2C_BUFFER_EVENT event,
        DRV_I2C_BUFFER_HANDLE handle,
        uintptr_t context) {

    switch (event) {
        case DRV_I2C_BUFFER_EVENT_COMPLETE:
            // TODO perform appropriate action
            break;

        case DRV_I2C_BUFFER_EVENT_ERROR:
            // TODO Error handling here.
            break;

        default:
            break;
    }
}
