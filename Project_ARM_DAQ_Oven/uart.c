//**************************************************************************
//
//                  UART Transreceiver Library (C File)
//
//**************************************************************************
//  FileName:           uart.c
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//*************************************************************************

//*******************************#Includes*********************************
#include "uart.h"
#include "conf.h"
//******************************End of INCLUDES****************************

//*************************************************************************
// Function					:        void uartinit()
// Input						:        None
// Output						:        None
// Overview					:        Set GPIO to UART, Enable transmition, Set baud rate
// Note							:        None
//*************************************************************************
void uartinit()
{
	PINSEL0|=0x00000005;										//set pinconnect block to enable UART0
	UTER=0X80;															//enable UART0 transmit
	ULCR=0X83;															//set U0LCR with 8bit character length and enable DLAB
	UDLL=0X14;															//set DLL with baudrate value
	UDLM=0X00;
	ULCR=0X03;															//Clear DLAB
}

//*************************************************************************
// Function					:        void uarttxstr(char *p)
// Input						:        Pointer to a character array
// Output						:        None
// Overview					:        Load UTHR with data, Read Line status continuously.
// Note							:        None
//*************************************************************************
void uarttxstr(unsigned char *p)
{
	while(*p)
	{
	UTHR=*(p++);														//Load U0THR with 8 bit value 
	while(!(ULSR&0x40));										//wait to set the transmitter empty register
	}
}

//*************************************************************************
// Function					:        Char uartrx()
// Input						:        None
// Output						:        Character
// Overview					:        Read Line Status, Read URBR for the data received
// Note							:        None
//*************************************************************************
unsigned char uartrx()
{
	unsigned char a;
	while(!(ULSR&(1<<0)));								//wait to set the receiver data ready register
	a=URBR;																//copy U0THR value to variable
	return a;
}


//*************************************************************************
// Function					:        void uarttxchar(unsigned char ch)
// Input						:        character
// Output						:        None
// Overview					:        Load UTHR with data, Read Line status continuously.
// Note							:        None
//*************************************************************************
void uarttxchar(unsigned char ch)
{
	UTHR= ch;														//Load U0THR with 8 bit value 
	while(!(ULSR&0x40));										//wait to set the transmitter empty register
}

