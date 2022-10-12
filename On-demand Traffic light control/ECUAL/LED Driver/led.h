/*
 * led.h
 *
 * Created: 10/4/2022 9:09:23 PM
 *  Author: Hazem Alwakil
 */ 
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
//all driver macros
//Car LEDs
#define LED_CAR_PORT PORT_A //'A'
#define LED_CAR_GREEN_PIN 0
#define LED_CAR_YELLOW_PIN 1
#define LED_CAR_RED_PIN 2

//pedestrian LEDs
#define LED_PED_PORT PORT_B //'B'
#define LED_PED_GREEN_PIN 0
#define LED_PED_YELLOW_PIN 1
#define LED_PED_RED_PIN 2


// all driver function prototypes
void LED_init(uint8_t ledPort,uint8_t ledPin); // Initialize LED
void LED_on(uint8_t ledPort,uint8_t ledPin); // LED on
void LED_off(uint8_t ledPort,uint8_t ledPin); // LED off
void LED_toggle(uint8_t ledPort,uint8_t ledPin); // Toggle LED


#endif
