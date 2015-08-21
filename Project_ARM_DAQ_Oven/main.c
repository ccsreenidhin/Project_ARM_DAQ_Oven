//************************************************************************************
//
//                  Data Aquisition System program (C File)
//
//************************************************************************************
//  FileName:           main.c
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

//*******************************#Includes*********************************
#include "conf.h"
//******************************End of INCLUDES****************************


//***************************** Global Variables***************************
unsigned char cmd[2];
unsigned char rxcmd,rxdata;

//*******function modules used**********
void configmodule(void);
void requestmodule(void);

//*************************************************************************
// Function					:        int main()
// Input						:        NULL
// Output						:        NULL
// Overview					:        Reads the UART and takes the command and data passed from PC
//													 Based on the command configures the modules or requests them.
// Note							:        None
//************************************************************************* 
int main()
{
	uartinit();
	while(1)
	{
	rxcmd=uartrx();																		//read UART buffer for 8 bits of commands
	rxdata=uartrx();																	//read UART buffer for 8 bits of data
	if((rxcmd&0xc0)==0x40) configmodule();						//if last 2 bits of command=01 configure modules 
	else if((rxcmd&0xc0)==0x80) requestmodule();			//if last 2 bits of command=10 request modules
	}
}

//*************************************************************************
// Function					:        void configuration()
// Input						:        NULL
// Output						:        NULL
// Overview					:        Based on the commands passed from PC selects the modules.
//													 Initializes the modules.
// Note							:        None
//************************************************************************* 
void configmodule()
{
	if((rxcmd&0x38)==0x00)	     adcclk(rxdata);					//if module=001 initialize adc with clock value
	else if((rxcmd&0x38)==0x08) capinit();						//if module=010 initialize frequency counter
	else if((rxcmd&0x38)==0x10) pwminit(rxdata);			//if module=011 initialize pwm with period
	else if((rxcmd&0x38)==0x18) DACINI;								//if module=100 initialize DAC
	else if((rxcmd&0x38)==0x20) 											//if module=101 initialize GPIO as input or output
			{	if((rxcmd&0x07)==1)
						GPODIR(rxdata);
				else if((rxcmd&0x07)==0)
						GPIDIR(rxdata);
			}
}

//*************************************************************************
// Function					:        void requestmodule()
// Input						:        NULL
// Output						:        NULL
// Overview					:        Based on the command passed from PC requests the modules
//													 for measurement data.
// Note							:        None
//************************************************************************* 
void requestmodule()
{
	unsigned int val;
	float data;
	unsigned char adc[2],ip[2];
	unsigned char txd[2];
	if((rxcmd&0x38)==0) 													//if module=001 read adc value from the channel specified
			{
				val=adcchread(rxdata);
				sprintf(adc,"%d",val);
				uarttxchar(0xc0);
				uarttxstr(adc);
			}
	else if((rxcmd&0x38)==0x08)										//if module=010 calculate the frequency of input signal
			{
				data=freqcal();
				sprintf(txd,"%f",data);
				uarttxchar(0xc8);
				uarttxstr(txd);
			}
	else if((rxcmd&0x38)==0x10)										//if module=011 set dutycycle for pwm1 and pwm2
			{
				if((rxcmd&0x07)==0)
						pwm1set(rxdata);
				else if((rxcmd&0x07)==1)
						pwm2set(rxdata);
			}
	else if((rxcmd&0x38)==0x18)DAC(rxdata);				//if module=100 output the rxdata as analog
	else if((rxcmd&0x38)==0x20)										//if module=101 read input or set or clear perticular GPIO
			{
				if((rxcmd&0x07)==0)
					{
						val=((IO1PIN>>24)&0x000000ff);
						val&=(1<<rxdata);
						sprintf(ip,"%d",val);
						uarttxchar(0xe0);
						uarttxstr(ip);
					}
				else if((rxcmd&0x07)==1)
					{
						ONOFF(rxdata);
					}
			}
}


