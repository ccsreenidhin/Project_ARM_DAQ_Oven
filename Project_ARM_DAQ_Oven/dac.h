//************************************************************************************
//
//                  DAC Interface Library (Header File)
//
//************************************************************************************
//  FileName:           dac.h
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#ifndef dac_h
#define dac_h

//*******Macro's for DAC**********
#define DACINI PINSEL1|=(1<<19)
#define DAC(x) DACR=((x)<<6)


#endif

