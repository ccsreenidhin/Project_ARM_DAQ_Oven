//************************************************************************************
//
//                  PWM Generation Library (Header File)
//
//************************************************************************************
//  FileName:           pwm.h
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#include "pwm.h"
#include "conf.h"

//*************************************************************************
// Function					:        void pwminit(int period)
// Input						:        period
// Output						:        NULL
// Overview					:        Selects the PWM channels and set the period of PWM
//													 and T-ON time. Also enable latch register.
// Note							:        None
//************************************************************************* 
void pwminit(int period)
{
	PINSEL0|=(40<<12);
	PWMPCR=0X00;
	PWMPR=2;
	PWMMR0=(period*1000);
	PWMMR2=2500;
	PWMMR4=7500;
	PWMMCR=(1<<1);
	PWMLER=(1<<4)|(1<<2)|(1<<0);
	PWMPCR|=((1<<10)|(1<<12));
	PWMTCR=(1<<1);
	PWMTCR=(1<<0)|(1<<3);
}

//*************************************************************************
// Function					:        void pwmchange(int ton1, int ton2)
// Input						:        ton1 and ton2
// Output						:        Null
// Overview					:        Selects the channel ton time for PWM2 and PWM4
//													 Also sets the Latch enable Register.
// Note							:        None
//************************************************************************* 

void pwm1set(int ton1)
{
PWMMR2 = ton1*100;													//T-ON=ton1
PWMLER = (1<<2)|(1<<4); 								//Update Latch Enable bit for PWMMR2
}

void pwm2set(int ton2)
{
	PWMMR4 = ton2*100;												//T-ON=ton2
	PWMLER = (1<<4)|(1<<2);								//Update Latch Enable bit for PWMMR4
	
}
