/*
 * application.h
 *
 * Created: 10/4/2022 9:11:34 PM
 *  Author: Hazem Alwakil
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Timer Driver/timer.h"
#include "../Utilities/interrupts.h"

//all macros
#define NORMAL_GREEN 0
#define NORMAL_YELLOW_A 1
#define NORMAL_YELLOW_B 7
#define NORMAL_RED 2
#define PEDESTRAIN_CAR_GREEN 3
#define PEDESTRAIN_CAR_YELLOW 4
#define PEDESTRAIN_CAR_RED 5
#define PEDESTRAIN 6
#define GREEN 1
#define YELLOW 2
#define RED 3

// all driver function prototypes
void APP_init(void);
void APP_start(void);

#endif