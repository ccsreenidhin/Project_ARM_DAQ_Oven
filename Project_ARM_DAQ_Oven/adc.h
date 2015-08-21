//************************************************************************************
//
//                  ADC Interface Library (Header File)
//
//************************************************************************************
//  FileName:           adc.h
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#ifndef adc_h
#define adc_h

//****************************** Macro Definitions************************************
#define ADCR  AD0CR
#define ADGDR  AD0GDR

//*******functions for adc**********

void adcclk(unsigned char clkdiv);
unsigned int adcchread(unsigned int);

#endif
