
#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/MemMap.h"
#include "../../Utilities/BIT_MATHS.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"



void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
	
}

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port =pin/8;
	uint8 pin_num=pin%8;
	
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT( DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT( DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT( DDRD,pin_num);
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}



void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port =pin/8;
	uint8 pin_num=pin%8;
	
	
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			
			SET_BIT(PORTD,pin_num);
			break;
		}
		
	}
	else if (volt==LOW)
	{
		switch(port)
		{
			case PA:
			
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
	}
	else
	{
		/* do nothing */
	}
	
}


DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port =pin/8;
	uint8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	
	switch(port)
	{
		case PA:
		
		volt=GET_BIT(PINA,pin_num);
		break;
		case PB:
		
		volt=GET_BIT(PINB,pin_num);
		break;
		case PC:
		
		volt=GET_BIT(PINC,pin_num);
		break;
		case PD:
		
		volt=GET_BIT(PIND,pin_num);
		break;
	}
	
	return volt;
}
void DIO_TogglePin(DIO_Pin_type pin)
{
	if(pin<=PINA7)
	{
		TOG_BIT(PORTA,pin);
	}
	else if(pin>=PINB0 && pin<=PINB7)
	{
		TOG_BIT(PORTB,(pin-PINA7-1));
	}
	else if(pin>=PINC0 && pin<=PINC7)
	{
		TOG_BIT(PORTC,(pin-PINB7-1));
	}
	else if(pin>=PIND0 && pin<=PIND7)
	{
		TOG_BIT(PORTD,(pin-PINC7-1));
	}
}

void DIO_WritePort(DIO_Port_type port,uint8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
}
uint8 DIO_ReadPort(DIO_Port_type port)
{
	uint8 value=0;
	switch(port)
	{
		case PA:
		value=PINA;
		break;
		case PB:
		value=PINB;
		break;
		case PC:
		value=PINC;
		break;
		case PD:
		value=PIND;
		break;
	}
	return value;
}