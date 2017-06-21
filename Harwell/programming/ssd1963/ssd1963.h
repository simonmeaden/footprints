/* 
 * File:   ssd1963.h
 * Author: simon
 *
 * Created on 16 April 2017, 10:27
 */

#ifndef SSD1963_H
#define	SSD1963_H

#ifdef	__cplusplus
extern "C" {
#endif


void TFT_35M_Init(void);
void TFT_35M_Write_Command(unsigned char command);
void TFT_35M_Write_Data(unsigned char data1);
void TFT_35M_Command_Write(unsigned char REG,unsigned char VALUE);
void TFT_35M_SendData(unsigned long color);
void TFT_35M_WindowSet(unsigned int s_x,unsigned int e_x,unsigned int s_y,unsigned int e_y);
void TFT_35M_FULL_ON(unsigned long dat);

#ifdef	__cplusplus
}
#endif

#endif	/* SSD1963_H */

