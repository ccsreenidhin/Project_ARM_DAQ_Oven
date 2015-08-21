//************************************************************************************
//
//                  Frequency Counter Library (C File)
//
//************************************************************************************
//  FileName:           freqcounter.c
//  Compiler:           Keil
//  Target Hardware:    ARM7 Development Board
//  Company:            Dexuslab Pvt Ltd
//  website:            www.duxeslabs.com
//  email:              ccsreenidhin@gmail.com
//************************************************************************************

#include "conf.h"
#include "freqcounter.h"

//***************Global Definitions***************
float capcnt;
float captime;
//*************************************************************************
// Function					:        void capISR(void)__irq
// Input						:        Null
// Output						:        Null
// Overview					:        Interrupt routine, the no of pulses captured is
//													 calculated here
// Note							:        None
//************************************************************************* 
void capISR(void)__irq
{
	int regval;
	regval = T0IR;
	capcnt++;																			//count the no of times the capture occured
	captime=T0CR2;																//total time taken for the captures
	T0IR = regval;																//copy the timer0 interrupt register to itself
	VICVectAddr=0x00;
}

//*************************************************************************
// Function					:        void timerinit()
// Input						:        NULL
// Output						:        Null
// Overview					:        Enables capture, timer, sets prescalar.
//													 Also enables Interrupt for timer.
// Note							:        None
//************************************************************************* 
void capinit()
{
	PINSEL1|=(3<<0);														//initialize the PINSEL block for capture operation
	T0CTCR=(1<<3);															//set T0CTCR for using cap0.2 for capture operation
	T0PR=2;																			//set the prescalar value
	T0CCR=(1<<6)|(1<<8);												//set T0CCR for reset and interrupt on capture
	VICIntEnable=(1<<4);												//enable timer0 vectered interrupt
	VICIntSelect=0x00;													//set the interrupt as irq
	VICVectCntl0=(1<<5)|4;											//enable slot for irq
	VICVectAddr0=(unsigned)capISR;							//load the address of the interrupt
	T0TCR=(1<<2);																//reset timer
	T0TCR=(1<<0);																//enable timer
}

//*************************************************************************
// Function					:        float frecal()
// Input						:        Null
// Output						:        Null
// Overview					:        Using no of captures and total time taken calculates 
//													 the frequency;
// Note							:        None
//************************************************************************* 
float freqcal()
{
	int i;
	float freq;
	for(i=0;i<1000;i++);
	freq=(capcnt/captime);											//calculate the frequecy from pulse count and total duration
	return freq;
}
