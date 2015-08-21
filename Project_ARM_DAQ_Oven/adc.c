//**************************************************************************
//
//                  ADC Converter Library (C File)
//
//**************************************************************************
//  FileName:           adc.c
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//*************************************************************************

//*******************************#Includes*********************************
#include "adc.h"
#include "conf.h"
//******************************End of Includes****************************


//*************************************************************************
// Function					:        void adcclk(unsigned int clkdiv)
// Input						:        Clock Divide parameter
// Output						:        None
// Overview					:        Sampling of Analog values according to clkdiv paramter
// Note						:        None
//*************************************************************************

void adcclk(unsigned char clkdiv)
{
		ADCR=(1<<21)|(clkdiv<<8)|(1<<18);														//Set the clock division
		
}

//*************************************************************************
// Function					:        unsigned long int adcread(unsigned long int c)
// Input						:        Channel number
// Output						:        10-bit Decimal value of the digital equivalent
// Overview					:        Selects the channel and set the bit for conversion
//									 Reads the ADGDR and gives an equivalent digital data.
// Note						:        None
//************************************************************************* 
unsigned int adcchread(unsigned int c)
{
	unsigned int val;
	ADCR|=(1<<c);																					//Select channel & start conversion
	ADCR|=(1<<24);
	do{
	val=ADGDR;																						//Store data from ADGDR to a variable
	}while((val&0x80000000)==0);													//wait for done bit to set
	val=(val>>6)&0x000003ff;															//seperate out the data
	return val;	
}
