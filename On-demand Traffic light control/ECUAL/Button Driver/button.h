/*
 * button.h
 *
 * Created: 10/4/2022 9:09:57 PM
 *  Author: Hazem Alwakil
 */ 
#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

//All driver macros
#define BUTTON_PORT PORT_C // port 'C'
#define BUTTON_PIN 2 // pin 2

// Button state macros
#define NOTPRESSED 0 
#define PRESSED 1 

// all driver function prototypes
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin); // Button Initialization
void BUTTON_read (uint8_t buttonPort, uint8_t buttonPin, uint8_t *state); // Get button State
#endif
