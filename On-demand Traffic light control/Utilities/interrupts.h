/*
 * interrupts.h
 *
 * Created: 10/7/2022 12:54:48 PM
 *  Author: Hazem Alwakil
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

//vectors
#define EXT_INT_0 __vector_1 //External Interrupt Request 0



//macro defines ISR
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT (void)
#endif /* INTERRUPTS_H_ */