//************************************************************************************
//
//                  UART Interface Library (Header File)
//
//************************************************************************************
//  FileName:           uart.h
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#ifndef uart_h
#define uart_h

//****************************** Macro Definitions************************************
#define UTER U0TER
#define ULCR U0LCR
#define UDLL U0DLL
#define UDLM U0DLM
#define UTHR U0THR
#define ULSR U0LSR
#define URBR U0RBR


//*******functions for uart**********
void uartinit(void);
void uarttxstr(unsigned char *);
unsigned char uartrx(void);
void uarttxchar(unsigned char);

#endif
