/*
 * dio.h
 *
 * Created: 10/4/2022 9:12:05 PM
 *  Author: Hazem Alwakil
 */ 
#ifndef _DIO_H
#define _DIO_H
#include "../../Utilities/registers.h"

//All driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// direction defines
#define IN 0
#define OUT 1

// Value defines
#define LOW 0
#define HIGH 1



// all driver function prototypes
void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction); // Initialize the DIO direction
void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value); // Write data on DIO
void DIO_toggle(uint8_t portNumber,uint8_t pinNumber); // Toggle the DIO
void DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value); // Read data on DIO


#endif
