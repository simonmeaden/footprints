/* 
 * File:   i2c.h
 * Author: simon
 *
 * Created on 03 May 2017, 07:45
 */

#ifndef I2C_H
#define	I2C_H

#include "system_definitions.h"
#include "drv_i2c.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void openI2C();
    void closeI2C();
    void startI2C();
    void stopI2C();
    void writeI2c(uint16_t deviceAddress, 
            void *writeBuffer, size_t writeSize);
    void readWriteI2c(uint16_t deviceAddress, 
            void *writeBuffer, size_t writeSize,
            void *readBuffer, size_t readSize);
    void readI2c(uint16_t deviceAddress, 
            void *readBuffer, size_t readSize);

    /*
     *  
     */
    void i2CBufferEventFunction(DRV_I2C_BUFFER_EVENT event,
            DRV_I2C_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

