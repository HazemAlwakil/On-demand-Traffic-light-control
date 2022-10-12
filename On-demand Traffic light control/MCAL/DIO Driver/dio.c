/*
 * dio.c
 *
 * Created: 10/4/2022 9:11:54 PM
 *  Author: Hazem Alwakil
 */ 

#include "dio.h"

 // Initialize the DIO direction
void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
		if(direction == IN)
		{
			DDRA &=~(1<<pinNumber); //Input
		}
		else if(direction == OUT)
		{
			DDRA |=(1<<pinNumber);  //Output
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_B:
		if(direction == IN)
		{
			DDRB &=~(1<<pinNumber); //Input
		}
		else if(direction == OUT)
		{
			DDRB |=(1<<pinNumber);  //Output
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_C:
		if(direction == IN)
		{
			DDRC &=~(1<<pinNumber); //Input
		}
		else if(direction == OUT)
		{
			DDRC |=(1<<pinNumber);  //Output
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_D:
		if(direction == IN)
		{
			DDRD &=~(1<<pinNumber); //Input
		}
		else if(direction == OUT)
		{
			DDRD |=(1<<pinNumber);  //Output
		}
		else
		{
			//Error Handling
		}
		break;
		
	}
}


// Write data on DIO
void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		if(value == IN)
		{
			PORTA &=~(1<<pinNumber); // write 0 
		}
		else if(value == OUT)
		{
			PORTA |=(1<<pinNumber);  // write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_B:
		if(value == IN)
		{
			PORTB &=~(1<<pinNumber); // write 0
		}
		else if(value == OUT)
		{
			PORTB |=(1<<pinNumber);  // write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_C:
		if(value == IN)
		{
			PORTC &=~(1<<pinNumber); // write 0
		}
		else if(value == OUT)
		{
			PORTC |=(1<<pinNumber);  // write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
		case PORT_D:
		if(value == IN)
		{
			PORTD &=~(1<<pinNumber); // write 0
		}
		else if(value == OUT)
		{
			PORTD |=(1<<pinNumber);  // write 1
		}
		else
		{
			//Error Handling
		}
		break;
		
	}
}


// Toggle the DIO
void DIO_toggle(uint8_t portNumber,uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		PORTA ^=(1<<pinNumber); // toggle bit
		break;
		
		case PORT_B:
		PORTB ^=(1<<pinNumber); // toggle bit
		break;
		
		case PORT_C:
		PORTC ^=(1<<pinNumber); // toggle bit
		break;
		
		case PORT_D:
		PORTD ^=(1<<pinNumber); // toggle bit
		break;
	
	}	
}


// Read data on DIO
void DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = ((PINA &(1<<pinNumber))>>pinNumber);  // Read Pin
		break;
		
		case PORT_B:
		*value = ((PINB &(1<<pinNumber))>>pinNumber);  // Read Pin
		break;
		
		case PORT_C:
		*value = ((PINC &(1<<pinNumber))>>pinNumber);  // Read Pin
		break;
		
		case PORT_D:
		*value = ((PIND &(1<<pinNumber))>>pinNumber);  // Read Pin
		break;
			
	}
}


