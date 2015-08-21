//************************************************************************************
//
//                  Frequency Counter Configuration Library (Header File)
//
//************************************************************************************
//  FileName:           freqcounter.h
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#ifndef freqcounter_h
#define freqcounter_h



//*******functions for frequency counter**********
void capinit(void);
void capISR(void)__irq;
float freqcal(void);

#endif

