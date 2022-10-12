/*
 * registers.h
 *
 * Created: 10/6/2022 1:45:53 PM
 *  Author: Hazem Alwakil
 */ 
/************************************************************************/
/* All Microcontroller Registers                                        */
/************************************************************************/


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "typedef.h"

/************************************************************************/
/*DIO Registers                                                         */
/************************************************************************/

// PORT A Registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

// PORT B Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

// PORT C Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

// PORT D Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


/************************************************************************/
/*Timer Registers                                                       */
/************************************************************************/
//Counter 0
#define TCCR0 *((volatile uint8_t*)0x53) // timer mode , prescaler
#define TCNT0 *((volatile uint8_t*)0x52) // timer starting value
#define TIMSK *((volatile uint8_t*)0x59) //to enable interrupt if needed
#define TIFR *((volatile uint8_t*)0x58) //to check the flag

/************************************************************************/
/*Interrupts Registers                                                  */
/************************************************************************/
#define GICR *((volatile uint8_t*)0x5B)
#define SREG *((volatile uint8_t*)0x5F)
#define GIFR *((volatile uint8_t*)0x5A)
#define MCUCR *((volatile uint8_t*)0x55)

#endif /* REGISTERS_H_ */