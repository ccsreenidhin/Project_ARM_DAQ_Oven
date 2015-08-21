//************************************************************************************
//
//                  GPIO Interface Library (Header File)
//
//************************************************************************************
//  FileName:           gpio.h
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#ifndef gpio_h
#define gpio_h

//*******Macro's for GPIO**********
#define GPODIR(X) IO1DIR|=(X<<24)
#define GPIDIR(X) IO1DIR&=(~(X<<24))
#define ON(X) IO1SET|=((1<<(X))<<24)
#define OFF(X) IO1CLR|=((1<<(X))<<24)
#define ONOFF(X) if((IO1SET&((1<<(X))<<24))==0) IO1SET|=((1<<(X))<<24); else IO1CLR|=((1<<(X))<<24)


#endif
