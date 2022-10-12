/*
 * led.c
 *
 * Created: 10/4/2022 9:08:59 PM
 *  Author: Hazem Alwakil
 */ 

#include "led.h"


// Initialize LED
void LED_init(uint8_t ledPort,uint8_t ledPin)
{
	DIO_init(ledPort,ledPin,OUT);// Output device
}


// LED on
void LED_on(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, HIGH);
}


// LED off 
void LED_off(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, LOW);
}


// Toggle LED 
void LED_toggle(uint8_t ledPort,uint8_t ledPin)
{
	DIO_toggle(ledPort, ledPin);
}