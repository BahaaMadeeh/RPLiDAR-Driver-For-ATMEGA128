/*
 * UART.c
/*
 * UART.c
 *
 * Created: 9/16/2022 3:11:41 AM
 *  Author: Bahaa Madeeh
 */ 

#include "UART.h"



void USART_Init(uint8 UART_NUM, unsigned long Baud)
{
	
	uint16 UBBR_Value=0;
	switch(UART_NUM)
	{
		case UART0:
		
		/* Set baud rate */
		UBBR_Value = (uint16)(((F_CPU/(8*Baud)))-1);
		UBRR0H_REG = ((UBBR_Value)>>8);
		UBRR0L_REG = (UBBR_Value);
		/* Enable receiver and transmitter */
		//UCSR0B_REG = (1<<4) | (1<<3) ;
		UCSR0B_REG = (1<<4) | (1<<3);
		/* Set frame format: 8data, 1stop bit */
		UCSR0C_REG = (1<<2) | (1<<1);
		/* Enable U2X = 1 (Double speed) */
		UCSR0A_REG = (1<<1);
		break;
		
		case UART1:
		
		/* Set baud rate */
		UBBR_Value = (uint16)(((F_CPU/(8*Baud)))-1);
		UBRR1H_REG = ((UBBR_Value)>>8);
		UBRR1L_REG = (UBBR_Value);
		/* Enable receiver and transmitter */
		UCSR1B_REG = (1<<4) | (1<<3);
		/* Set frame format: 8data, 1stop bit */
		UCSR1C_REG = (1<<2) | (1<<1);
		/* Enable U2X = 1 (Double speed) */
		UCSR1A_REG = (1<<1);
		break;
		
	}

}

void USART_Transmit(uint8 UART_NUM,uint8 data)
{
	switch(UART_NUM)
	{
		case UART0:
		
		/* Wait for empty transmit buffer */
		while ( !( UCSR0A_REG & (1<<5)) )
		;
		/* Put data into buffer, sends the data */
		UDR0_REG = data;
		break;
		
		case UART1:
		
		/* Wait for empty transmit buffer */
		while ( !( UCSR1A_REG & (1<<5)) )
		;
		/* Put data into buffer, sends the data */
		UDR1_REG = data;
		break;
		
	}
}

uint8 USART_Recieve(uint8 UART_NUM)
{
	uint32 uart_flag=0;
	uint8 data = 0;
	switch(UART_NUM)
	{
		case UART0:
		/* Wait for data to be received */
		while ( !(UCSR0A_REG & (1<<7)) );
	
		
		/* Put data into buffer, sends the data */
		data = UDR0_REG;
		break;

		case UART1:

		/* Wait for data to be received */
		while ( !(UCSR1A_REG & (1<<7)) )
		;
		/* Put data into buffer, sends the data */
		data = UDR1_REG;
		break;

	}

	/* Get and return received data from buffer */
	return data;
}

void USART_Flush(void)
{
	uint8 dummy;
	while ( UCSR0A_REG & (1<<7) ) dummy = UDR0_REG;
}

void USART_SendString(uint8 UART_NUM,uint8*data)
{
	uint32 i=0;
	
	while (data[i] != 0)
	{
		USART_Transmit(UART_NUM, data[i]);						/* Send each char of string till the NULL */
		i++;
	}
}

