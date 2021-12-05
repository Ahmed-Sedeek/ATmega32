/*
 * DIO.c
 *
 * Created: 10/31/2021 1:48:50 PM
 *  Author: Ahmed Sedeek
 */ 

#include "DIO_Interface.h"
#include "DIO_Private.h"



/************************************************************************/
/*                         Pins APIs                                   */
/************************************************************************/

/*This function controls the direction of the pins*/
void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
	
}

/**
* @Functionality: This function initializes the the pin direction configuration , case the pin direction is output, input with pull up resistor
*				  or input with free configuration.
* @Param status: The direction status of the pin, output, input free, or input with pull up resistor.
*
* @Param pin:    The pin to be configurated.
* Direction initialize
*/
void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;

	switch (status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
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
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
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
}

DIO_DirectionStatus_type DIO_ReadPinDirection(DIO_Pin_type pin)
{
	DIO_Port_type port = pin / 8;
	u8 pin_num = pin % 8;
	
	DIO_DirectionStatus_type direction = DIRECTION_OUTPUT;
	switch(port)
	{
		case PA:
		direction= READ_BIT(DDRA,pin_num);
		break;
		case PB:
		
		direction=READ_BIT(DDRB,pin_num);
		break;
		case PC:
		
		direction= READ_BIT(DDRC,pin_num);
		break;
		case PD:
		
		direction= READ_BIT(DDRD,pin_num);
		break;
	}
	return direction;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	switch(port)
	{
		case PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		
		case PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		
		case PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		
		case PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;
	}
}

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt= READ_BIT(PINA,pin_num);
		break;
		
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		
		case PC:
		volt= READ_BIT(PINC,pin_num);
		break;
		
		case PD:
		volt= READ_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

/************************************************************************/
/*                         Ports APIs                                   */
/************************************************************************/

void DIO_InitPort(DIO_Port_type port,DIO_PortStatus_type status)
{
	
	switch (status)
	{
		case PORT_OUTPUT:
		switch(port)
		{
			case PA:
			SET_PORT(DDRA);
			CLEAR_PORT(PORTA);
			break;
			
			case PB:
			SET_PORT(DDRB);
			CLEAR_PORT(PORTB);
			break;
			
			case PC:
			SET_PORT(DDRC);
			CLEAR_PORT(PORTC);
			break;
			
			case PD:
			SET_PORT(DDRD);
			CLEAR_PORT(PORTD);
			break;
		}
		break;
		
		case PORT_INFREE:
		switch(port)
		{
			case PA:
			CLEAR_PORT(DDRA);
			CLEAR_PORT(PORTA);
			break;
			case PB:
			CLEAR_PORT(DDRB);
			CLEAR_PORT(PORTB);
			break;
			case PC:
			CLEAR_PORT(DDRC);
			CLEAR_PORT(PORTC);
			break;
			case PD:
			CLEAR_PORT(DDRD);
			CLEAR_PORT(PORTD);
			break;
		}
		break;
		
		case PORT_INPULL:
		switch(port)
		{
			case PA:
			CLEAR_PORT(DDRA);
			SET_PORT(PORTA);
			break;
			case PB:
			CLEAR_PORT(DDRB);
			SET_PORT(PORTB);
			break;
			case PC:
			CLEAR_PORT(DDRC);
			SET_PORT(PORTC);
			break;
			case PD:
			CLEAR_PORT(DDRD);
			SET_PORT(PORTD);
			break;
		}
		break;
	}
}

void DIO_WritePort(DIO_Port_type port,u8 value)
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

Std_ReturnType DIO_ReadPortDirection(DIO_Port_type port)
{
	Std_ReturnType direction = DIRECTION_OUTPUT;
	switch(port)
	{
		case PA:
		direction= READ_PORT(DDRA);
		break;
		
		case PB:
		direction=READ_PORT(DDRB);
		break;
		
		case PC:
		direction= READ_PORT(DDRC);
		break;
		
		case PD:
		direction= READ_PORT(DDRD);
		break;
	}
	return direction;
}

void DIO_TogglePort(DIO_Port_type port)
{	
	switch(port)
	{
		case PA:
		TOGGLE_PORT(PORTA);
		break;
		
		case PB:
		TOGGLE_PORT(PORTB);
		break;
		
		case PC:
		TOGGLE_PORT(PORTC);
		break;
		
		case PD:
		TOGGLE_PORT(PORTD);
		break;
	}
}
