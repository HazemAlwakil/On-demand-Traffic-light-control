/*
 * timer.h
 *
 * Created: 10/4/2022 9:10:24 PM
 *  Author: Hazem Alwakil
 */ 
#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"


// all driver function prototypes
void TIMER_init(); // Timer Initialization
void TIMER_delay (uint16_t timerMS); // set delay in ms
#endif
