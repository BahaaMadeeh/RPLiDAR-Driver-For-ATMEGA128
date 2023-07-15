/*
 * Registers.h
 *
 * Created: 9/5/2022 11:56:00 PM
 *  Author: Bahaa Madeeh
 */ 



#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/* Group A Registers */

#define PORTA_REG  *((volatile uint8*)0x3B)
#define DDRA_REG   *((volatile uint8*)0x3A)
#define PINA_REG   *((volatile uint8*)0x39)

/* Group B Registers */

#define PORTB_REG  *((volatile uint8*)0x38)
#define DDRB_REG   *((volatile uint8*)0x37)
#define PINB_REG   *((volatile uint8*)0x36)

/* Group C Registers */

#define PORTC_REG  *((volatile uint8*)0x35)
#define DDRC_REG   *((volatile uint8*)0x34)
#define PINC_REG   *((volatile uint8*)0x33)

/* Group D Registers */

#define PORTD_REG  *((volatile uint8*)0x32)
#define DDRD_REG   *((volatile uint8*)0x31)
#define PIND_REG   *((volatile uint8*)0x30)

/* Group E Registers */

#define PORTE_REG  *((volatile uint8*)0x23)
#define DDRE_REG   *((volatile uint8*)0x22)
#define PINE_REG   *((volatile uint8*)0x21)

/* Group F Registers */

#define PORTF_REG  *((volatile uint8*)0x62)
#define DDRF_REG   *((volatile uint8*)0x61)
#define PINF_REG   *((volatile uint8*)0x20)

/* Group G Registers */

#define PORTG_REG  *((volatile uint8*)0x65)
#define DDRG_REG   *((volatile uint8*)0x64)
#define PING_REG   *((volatile uint8*)0x63)

/***********************/
/* Timer Registers*/
/***********************/

#define TCCR0_REG   *((volatile uint8*)0x53)
#define TCNT0_REG   *((volatile uint8*)0x52)
#define OCR0_REG    *((volatile uint8*)0x51)
#define TIFR_REG    *((volatile uint8*)0x58)
#define TIMSK_REG   *((volatile uint8*)0x59)

/************************************/
/*   Interrupts Registers           */
/************************************/

#define SREG_REG    *((volatile uint8*)0x5F)
#define GICR_REG    *((volatile uint8*)0x5B)
#define MCUCR_REG   *((volatile uint8*)0x55)
#define MCUCSR_REG  *((volatile uint8*)0x54)

/******************************************/
/*             USART0 Register             */
/******************************************/

#define UBRR0H_REG	*((volatile uint8*)0x90)
#define UCSR0C_REG  *((volatile uint8*)0x95)
#define UBRR0L_REG	*((volatile uint8*)0x29)
#define UDR0_REG	*((volatile uint8*)0x2C)
#define UCSR0A_REG	*((volatile uint8*)0x2B)
#define UCSR0B_REG	*((volatile uint8*)0x2A)

/******************************************/
/*             USART1 Register             */
/******************************************/

#define UBRR1H_REG	*((volatile uint8*)0x98)
#define UCSR1C_REG  *((volatile uint8*)0x9D)
#define UBRR1L_REG	*((volatile uint8*)0x99)
#define UDR1_REG	*((volatile uint8*)0x9C)
#define UCSR1A_REG	*((volatile uint8*)0x9B)
#define UCSR1B_REG	*((volatile uint8*)0x9A)


#endif /* REGISTERS_H_ */