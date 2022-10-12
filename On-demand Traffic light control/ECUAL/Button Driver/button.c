/*
 * button.c
 *
 * Created: 10/4/2022 9:09:40 PM
 *  Author: Hazem Alwakil
 */ 

#include "button.h"


// Button Initialization
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPort, buttonPin, IN); //Input device
}


// Get button State
void BUTTON_read (uint8_t buttonPort, uint8_t buttonPin, uint8_t *state)
{
	DIO_read(buttonPort, buttonPin, state);
}