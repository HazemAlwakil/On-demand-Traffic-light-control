/*
 * timer.c
 *
 * Created: 10/4/2022 9:10:12 PM
 *  Author: Hazem Alwakil
 */ 
#include "timer.h"
#include <math.h>

// Timer Initialization
void TIMER_init()
{
	TCCR0 = 0x00; //normal mode
	TCNT0 = 0x00; //Starting value
} 

// set delay in ms
void TIMER_delay (uint16_t timerMS)
{
	uint16_t overFlowCounter=0, timerInitial=0;
	uint32_t numberOverFlow=0;
	
	//Tmaxdelay=262.144ms  (2^8)*(1024/10^6)    Fcpu=10^6   prescaler= 1024
	numberOverFlow= ceil(timerMS/262.144);
	timerInitial=(256-((timerMS/1.024)/(numberOverFlow)));
	
	
	TCNT0 = timerInitial; 
	//set 1024 prescaler
	TCCR0 |=(1<<0) | (1<<2);
	while(overFlowCounter< numberOverFlow)
	{
		while((TIFR &(1<<0))==0);
		
		TIFR |=(1<<0); // Clear the over flow flag 
		overFlowCounter++;
	}
	
	overFlowCounter = 0;
	TCCR0 = 0x00; // Timer stop
	
}
