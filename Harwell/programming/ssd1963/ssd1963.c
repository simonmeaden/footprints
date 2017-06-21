//---------------------------------------------------------
/*
Program snippet for writing to Newhaven Display 3.5" TFT

(c)2012 Curt Lagerstam - Newhaven Display International, Inc.

 	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
*/
//---------------------------------------------------------
#include "ssd1963.h"
/*-------------------------------------------------------*/
int TFT_35M_demo(void);

/*******************************************************************************
* Function Name  : TFT_35M_delay
* Description    : Short delay
* Input          : time
* Output         : None
* Return         : None
*******************************************************************************/
void TFT_35M_delay(int time)
{
  int i,j;
  for(i=0;i<(time^1000);i++){
  	for(j=0;j<(time^1000);j++){;}}
}
/*******************************************************************************
* Function Name  : TFT_35M_demo
* Description    : Loops through images on SD Card
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int TFT_35M_demo(void)
{
char filename[18] = "3_5_320240MF_";
char filetype[4] = ".bmp";
char filenumber[1] = "0";
int i,n,result;
char image = 0x30;
UINT blen = sizeof(Buff);
memset(Buff,3,sizeof(Buff));

while(1){						//continuous loop
filename[13]='\0';
filenumber[0] = image;
strncat(filename,filenumber,1);
strncat(filename,filetype,4);	//puts file number into string= "3_5_320240MF_0.bmp"
//...
//-----------MOUNT AND READ FROM SD CARD code removed
//...
TFT_35M_Init();										//initialize TFT
TFT_35M_WindowSet(0x0000,0x013f,0x0000,0x00ef);		//set window
TFT_35M_Write_Command(0x2c);						//write start
GPIO_SetBits(GPIOC, RS);							//RS=1 : write data

for(n=0;n<32;n++){							//read from file 128 times, 7200 bytes each time
		f_read(&File1, Buff, 7200, &blen);	// read line of pixels
		for(i=0;i<7200;i++){
			GPIO_SetBits(GPIOC, nWR);
			GPIO_Write(GPIOB, Buff[i]);
			GPIO_ResetBits(GPIOC, nWR);	
			}							
		}										//read next 7200 bytes
//...
//-----------CLOSE SD CARD FILE code removed
//...
UILCD_SetCursor(0,0);UILCD_DisplayString("Press SEL button");UILCD_SetCursor(1,0);UILCD_DisplayString("for next file.  ");
while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)!=0){;}

image++;
//...
//----------- OPEN SD CARD FILE code removed
//...
}
return 1;
}


/*******************************************************************************
* Function Name  : TFT_35M_Init
* Description    : Initializes LCD.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TFT_35M_Init(void)
{
GPIO_ResetBits(GPIOC, CS1);
GPIO_SetBits(GPIOC, nRD);
GPIO_ResetBits(GPIOC, nWR);
GPIO_WriteBit(GPIOC, RES, Bit_RESET);
delay(5);
TFT_35M_delay(10);
GPIO_WriteBit(GPIOC, RES, Bit_SET);
delay(100);
TFT_35M_delay(10);
TFT_35M_Write_Command(0x01);     //Software Reset
delay(10);
TFT_35M_delay(10);
TFT_35M_Write_Command(0x01);     //Software Reset
delay(10);
TFT_35M_delay(10);
TFT_35M_Command_Write(0xe0,0x01);    //START PLL
TFT_35M_Command_Write(0xe0,0x03);    //LOCK PLL
TFT_35M_Write_Command(0xb0);		//SET LCD MODE  SET TFT 18Bits MODE
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(0x0c);			//SET TFT MODE & hsync+Vsync+DEN MODE
TFT_35M_Write_Data(0x80);			//SET TFT MODE & hsync+Vsync+DEN MODE
TFT_35M_Write_Data(0x01);			//SET horizontal size=320-1 HightByte
TFT_35M_Write_Data(0x3f);		    //SET horizontal size=320-1 LowByte
TFT_35M_Write_Data(0x00);			//SET vertical size=240-1 HightByte
TFT_35M_Write_Data(0xef);			//SET vertical size=240-1 LowByte
TFT_35M_Write_Data(0x00);			//SET even/odd line RGB seq.=RGB
TFT_35M_Command_Write(0xf0,0x00);	//SET pixel data I/F format=8bit
TFT_35M_Command_Write(0x3a,0x60);   // SET R G B format = 6 6 6
TFT_35M_Write_Command(0xe6);   		//SET PCLK freq=4.94MHz  ; pixel clock frequency
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(0x0a);		
TFT_35M_Write_Data(0x3d);		
TFT_35M_Write_Data(0x70);		
TFT_35M_Write_Command(0xb4);		//SET HBP, 
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(0x01);			//SET HSYNC Total=440
TFT_35M_Write_Data(0xb8);			
TFT_35M_Write_Data(0x00);			//SET HBP 68
TFT_35M_Write_Data(0x46);			
TFT_35M_Write_Data(0x0f);			//SET VBP 16=15+1
TFT_35M_Write_Data(0x00);			//SET Hsync pulse start position
TFT_35M_Write_Data(0x00);
TFT_35M_Write_Data(0x00);			//SET Hsync pulse subpixel start position
TFT_35M_Write_Command(0xb6); 		//SET VBP, 
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(0x01);			//SET Vsync total 
TFT_35M_Write_Data(0x48);
TFT_35M_Write_Data(0x00);			//SET VBP=19
TFT_35M_Write_Data(0x0b);		
TFT_35M_Write_Data(0x07);			//SET Vsync pulse 8=7+1
TFT_35M_Write_Data(0x00);			//SET Vsync pulse start position
TFT_35M_Write_Data(0x00);
TFT_35M_Write_Command(0x2a);		//SET column address
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(0x00);			//SET start column address=0
TFT_35M_Write_Data(0x00);
TFT_35M_Write_Data(0x01);			//SET end column address=319
TFT_35M_Write_Data(0x3f);
TFT_35M_Write_Command(0x2b);		//SET page address
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(0x00);			//SET start page address=0
TFT_35M_Write_Data(0x00);
TFT_35M_Write_Data(0x00);			//SET end page address=239
TFT_35M_Write_Data(0xef);
TFT_35M_Write_Command(0x13);		//SET normal mode
TFT_35M_Write_Command(0x29);		//SET display on
}

void TFT_35M_Write_Command(unsigned char command)
{
GPIO_Write(GPIOB, command);
GPIO_ResetBits(GPIOC, RS);
GPIO_ResetBits(GPIOC, nWR);
GPIO_SetBits(GPIOC, nWR);
}

void TFT_35M_Write_Data(unsigned char data1)
{
GPIO_Write(GPIOB, data1);
GPIO_ResetBits(GPIOC, nWR);
GPIO_SetBits(GPIOC, nWR);
}

void TFT_35M_Command_Write(unsigned char REG,unsigned char VALUE)
{
TFT_35M_Write_Command(REG);
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data(VALUE);
}

void TFT_35M_SendData(unsigned long color)
{
GPIO_SetBits(GPIOC, RS);
GPIO_Write(GPIOB, (color>>16));
GPIO_ResetBits(GPIOC, nWR);
GPIO_SetBits(GPIOC, nWR);
GPIO_Write(GPIOB, (color>>8));
GPIO_ResetBits(GPIOC, nWR);
GPIO_SetBits(GPIOC, nWR);
GPIO_Write(GPIOB, (color));
GPIO_ResetBits(GPIOC, nWR);
GPIO_SetBits(GPIOC, nWR);
}

void TFT_35M_WindowSet(unsigned int s_x,unsigned int e_x,unsigned int s_y,unsigned int e_y)
{
TFT_35M_Write_Command(0x2a);		//SET page address
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data((s_x)>>8);			//SET start page address=0
TFT_35M_Write_Data(s_x);
TFT_35M_Write_Data((e_x)>>8);			//SET end page address=319
TFT_35M_Write_Data(e_x);

TFT_35M_Write_Command(0x2b);		//SET column address
GPIO_SetBits(GPIOC, RS);
TFT_35M_Write_Data((s_y)>>8);			//SET start column address=0
TFT_35M_Write_Data(s_y);
TFT_35M_Write_Data((e_y)>>8);			//SET end column address=239
TFT_35M_Write_Data(e_y);
}

void TFT_35M_FULL_ON(unsigned long dat)
{
unsigned long x;
TFT_35M_WindowSet(0x0000,0x013f,0x0000,0x00ef);
TFT_35M_Write_Command(0x2c);
for(x=0;x<307200;x++)
{
TFT_35M_SendData(dat);
}
}

void TFT_35M_QUADS(void)
{
unsigned int i,j;
TFT_35M_WindowSet(0x0000,0x013f,0x0000,0x00ef);
TFT_35M_Write_Command(0x2c);
for(j= 0 ;j<120;j++)
  {
   for(i=0;i<160;i++)
   {
    TFT_35M_SendData(0x0000FF);             //blue
   }
   for(i=0;i<160;i++)
   {
    TFT_35M_SendData(0xFF0000);             //red
   }
 }  
for(j= 0 ;j<120;j++)
  {
   for(i=0;i<160;i++)
   {
    TFT_35M_SendData(0xFFFF00);             //yellow
   }
   for(i=0;i<160;i++)
   {
    TFT_35M_SendData(0x00FF00);             //green
   }
 }
}
/*-------------------------------------------------------*/

