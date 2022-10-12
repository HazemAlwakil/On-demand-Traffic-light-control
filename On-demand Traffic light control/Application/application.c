/*
 * application.c
 *
 * Created: 10/4/2022 9:11:24 PM
 *  Author: Hazem Alwakil
 */ 

#include "application.h"

//Variables
uint8_t i=0;
uint8_t mode=0; //normal & green car led=0		       normal & yellow car led=1		    normal & Red car led=2
				//pedestrian & green car led=3		   pedestrian & yellow car led=4		pedestrian & Red car led=5


void APP_init(void)
{
	
	//LED Initializing
	//Car LEDs
	LED_init(LED_CAR_PORT,LED_CAR_GREEN_PIN); // Car green LED
	LED_init(LED_CAR_PORT,LED_CAR_YELLOW_PIN); // Car yellow LED
	LED_init(LED_CAR_PORT,LED_CAR_RED_PIN); // Car red LED
	//pedestrian LEDs
	LED_init(LED_PED_PORT,LED_PED_GREEN_PIN); // Pedestrian green LED
	LED_init(LED_PED_PORT,LED_PED_YELLOW_PIN); // Pedestrian Yellow LED
	LED_init(LED_PED_PORT,LED_PED_RED_PIN); // Pedestrian red LED
	
	//Button Initializing
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
	
	//Timer Initializing
	TIMER_init();
	
	//Interrupts  Initializing
	//1- Enable global interrupts - setting bit 7 in the status register to 1
	SREG |=(1<<7);
	//2- Choose the external interrupt sense - sense on rising edge
	MCUCR |=(1<<0) |(1<<1);
	//3- Enable external interrupt - bit 6 related to INT0
	GICR |=(1<<6);
		
}

void APP_start(void)
{
	/*Car green on: if the mode is normal the car green LED will be on for 5 seconds
	through this time we will check if the button had been pressed or not.
	if presses : we will go to pedestrian mode.
	if not will go to normal mode with yellow car LED*/
	if(mode==NORMAL_GREEN)
	{
		
		for(i=0;i<40;i++)
		{
		LED_on(LED_CAR_PORT,LED_CAR_GREEN_PIN);
		TIMER_delay(122);
		if(mode == PEDESTRAIN)
			{
				mode = PEDESTRAIN_CAR_GREEN;
				LED_off(LED_CAR_PORT,LED_CAR_GREEN_PIN);
				break;
			}
		
		}
		LED_off(LED_CAR_PORT,LED_CAR_GREEN_PIN);
		
	}
	//
	if(mode!=PEDESTRAIN_CAR_GREEN)mode= NORMAL_YELLOW_A;
	
	
	/*Car yellow blink: if the mode is normal the car Yellow LED will be blink for 5 seconds
	through this time we will check if the button had been pressed or not.
	if presses : we will go to pedestrian mode.
	if not will go to normal mode with Red car LED*/
	if(mode== NORMAL_YELLOW_A)
	{
		
		for(i=0;i<20;i++)
		{
		LED_toggle(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		TIMER_delay(247);
			if(mode == PEDESTRAIN)
			{
				mode = PEDESTRAIN_CAR_YELLOW;
				LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
				break;	
			}
		}
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		
	}
	
	//
	if((mode!=PEDESTRAIN_CAR_YELLOW) && (mode!=PEDESTRAIN_CAR_GREEN) )
		{
			mode= NORMAL_RED;
		}
	else if(mode == PEDESTRAIN_CAR_GREEN)
	{
		mode = PEDESTRAIN_CAR_GREEN;
	}
	else
	{
		mode = PEDESTRAIN_CAR_YELLOW;
	}
	
	
	/*Car Red on: if the mode is normal the car red LED will be on for 5 seconds
	through this time we will check if the button had been pressed or not.
	if presses : we will go to pedestrian mode.
	if not will go to normal mode with yellow car LED*/
	if(mode== NORMAL_RED)
	{	
		for(i=0;i<40;i++)
		{
			LED_on(LED_CAR_PORT,LED_CAR_RED_PIN);
			TIMER_delay(122);
			if(mode == PEDESTRAIN)
			{
				mode = PEDESTRAIN_CAR_RED;
				LED_off(LED_CAR_PORT,LED_CAR_RED_PIN);
				break;
			}
		}
		LED_off(LED_CAR_PORT,LED_CAR_RED_PIN);
		
	}
	
	
	if((mode!=PEDESTRAIN_CAR_YELLOW) && (mode!=PEDESTRAIN_CAR_GREEN)  && (mode!=PEDESTRAIN_CAR_RED))
	{
		mode= NORMAL_YELLOW_B;
	}
	else if(mode == PEDESTRAIN_CAR_GREEN)
	{
		mode = PEDESTRAIN_CAR_GREEN;
	}
	else if(mode == PEDESTRAIN_CAR_YELLOW)
	{
		mode = PEDESTRAIN_CAR_YELLOW;
	}
	else 
	{
		mode = PEDESTRAIN_CAR_RED;
	}
	
	
	/*Car yellow blink (not to go to red directly): if the mode is normal the car Yellow LED will be blink for 5 seconds
	through this time we will check if the button had been pressed or not.
	if presses : we will go to pedestrian mode.
	if not will go to normal mode with green car LED - to repeat all the steps*/
	if(mode== NORMAL_YELLOW_B)
	{
		
		for(i=0;i<20;i++)
		{
			LED_toggle(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			TIMER_delay(247);
			if(mode == PEDESTRAIN)
			{
				mode = PEDESTRAIN_CAR_YELLOW;
				LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
				break;
			}
			
		}
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		
	}
	
	
	if((mode!=PEDESTRAIN_CAR_YELLOW) && (mode!=PEDESTRAIN_CAR_GREEN)  && (mode!=PEDESTRAIN_CAR_RED))
	{
		mode= NORMAL_GREEN;
	}
	else if(mode == PEDESTRAIN_CAR_GREEN)
	{
		mode = PEDESTRAIN_CAR_GREEN;
	}
	else if(mode == PEDESTRAIN_CAR_YELLOW)
	{
		mode = PEDESTRAIN_CAR_YELLOW;
	}
	else
	{
		mode = PEDESTRAIN_CAR_RED;
	}
	


	
	//if the button pressed while car LED is green or yellow
	if((mode == PEDESTRAIN_CAR_GREEN) ||(mode == PEDESTRAIN_CAR_YELLOW))
	{
		
		//The both yellows will blink, pedestrian LED red will be on
		for(i=0;i<20;i++)
		{
			LED_toggle(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_toggle(LED_PED_PORT,LED_PED_YELLOW_PIN);
			LED_on(LED_PED_PORT,LED_PED_RED_PIN);
			TIMER_delay(247);
		}
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_RED_PIN);
		mode= PEDESTRAIN_CAR_RED;
	}
	//continue the pedestrian mode or button pressed at normal mode with car red LED is on.
	if(mode == PEDESTRAIN_CAR_RED)
	{
		//Car red is on and pedestrian green is on for 5 seconds
		LED_on(LED_CAR_PORT,LED_CAR_RED_PIN);
		LED_on(LED_PED_PORT,LED_PED_GREEN_PIN);
		TIMER_delay(4980);
		LED_off(LED_CAR_PORT,LED_CAR_RED_PIN);
		
		//both yellow blink, pedestrian still green  on for 5 seconds
		for(i=0;i<20;i++)
		{
			LED_toggle(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
			LED_toggle(LED_PED_PORT,LED_PED_YELLOW_PIN);
			TIMER_delay(247);
		}
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_YELLOW_PIN);
		LED_off(LED_PED_PORT,LED_PED_GREEN_PIN);
		
		/*car green on - pedestrian red on - at the end of this 5 seconds 
		the system will transfer to normal mode again with yellow car LED blinking*/
		LED_on(LED_CAR_PORT,LED_CAR_GREEN_PIN);
		LED_on(LED_PED_PORT,LED_PED_RED_PIN);
		TIMER_delay(4980);
		LED_off(LED_CAR_PORT,LED_CAR_GREEN_PIN);
		LED_off(LED_PED_PORT,LED_PED_RED_PIN);
		mode = NORMAL_YELLOW_A;
	}
}
//Interrupt to check the button status
ISR(EXT_INT_0)
{
	mode=6;
}