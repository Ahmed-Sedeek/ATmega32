/*
 * External_Interrupts.c
 *
 * Created: 12/1/2021 2:49:21 AM
 *  Author: Ahmed Sedeek
 */ 
#include "External_Interrupts.h"

/*Led initialization*/
Led_type led1 = {.pin = PINC0, .led_status = LED_OFF};
//LED_Init(&led1);

void EXTERNAL_INT0_Enable(void)
{
	SET_BIT(GICR, BIT6);
}

void EXTERNAL_INT1_Enable(void)
{
	SET_BIT(GICR, BIT7);
}

void EXTERNAL_INT2_Enable(void)
{
	SET_BIT(GICR, BIT5);
}



void EXTERNAL_INT0_Disable(void)
{
	CLEAR_BIT(GICR, BIT6);
}

void EXTERNAL_INT1_Disable(void)
{
	CLEAR_BIT(GICR, BIT7);
}

void EXTERNAL_INT2_Disable(void)
{
	CLEAR_BIT(GICR, BIT5);
}



void EXTERNAL_INT0_Edge(EXT_IntEdge_type edge)
{
	MCUCR &= 0xFC; // 11111100 for the register
	edge &= 0x03; // 00000011 For edge ( just 2 make sure)
	MCUCR |= edge; // Writing the edge valur in the register
}

void EXTERNAL_INT1_Edge(EXT_IntEdge_type edge)
{
	MCUCR &= 0xF3; // 11111100 for the register
	edge &= 0x0C; // 00000011 For edge ( just 2 make sure)
	MCUCR |= edge; // Writing the edge valur in the register
}

void EXTERNAL_INT2_Edge(u8 edge)
{
	if (edge == EXT_INT2_FALLING_EDGE)
		CLEAR_BIT(MCUCSR, BIT6);
		
	else if (edge == EXT_INT2_RISING_EDGE)
		SET_BIT(MCUCSR, BIT6);
}


/*External Interrupts Vectors*/
ISR(INT0_vect)
{
	LED_Toggle(&led1);
}

ISR(INT1_vect)
{
	
}

ISR(INT2_vect)
{
	
}