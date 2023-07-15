/*
 * UART.h
 *
 * Created: 9/16/2022 3:11:34 AM
 *  Author: Bahaa Madeeh
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../Utilities/BIT_MATHS.h"
#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/Registers.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define UART0 0
#define UART1 1



void USART_Init(uint8 UART_NUM, unsigned long Baud);
void USART_Transmit(uint8 UART_NUM,uint8 data);
uint8 USART_Recieve(uint8 UART_NUM);
void USART_Flush(void);
void USART_SendString(uint8 UART_NUM,uint8*data);


#endif /* UART_H_ */
