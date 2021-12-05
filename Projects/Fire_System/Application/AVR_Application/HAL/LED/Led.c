/*
 * Led.c
 *
 * Created: 11/2/2021 4:47:40 PM
 *  Author: Ahmed Sedeek
 */ 

/*------------ Include Section ------------*/
#include "Led.h"

/************************************************************************/
/*                          LEDs APIs                                   */
/************************************************************************/
Std_ReturnType LED_Init(Led_type *led)
{
	Std_ReturnType ret = RET_NOT_OK;
	if(NULL_PTR == led || led->pin >= TOTAL_PINS)
	{
		return ret;
	}
	else
	{
		DIO_InitPin(led->pin, OUTPUT);
		DIO_WritePin(led->pin, LOW);
		ret = RET_OK;
	}
	return ret;
}

Std_ReturnType LED_On(Led_type *led)
{
	Std_ReturnType ret = RET_NOT_OK;
	if(NULL_PTR == led || led->pin >= TOTAL_PINS)
	{
		return ret;
	}
	else
	{
		DIO_WritePin(led->pin, HIGH);
		ret = RET_OK;
	}
	return ret;
}

Std_ReturnType LED_Off(Led_type *led)
{
	Std_ReturnType ret = RET_NOT_OK;
	if(NULL_PTR == led || led->pin >= TOTAL_PINS)
	{
		return ret;
	}
	else
	{
		DIO_WritePin(led->pin, LOW);
		ret = RET_OK;
	}
	return ret;
}

Std_ReturnType LED_Toggle(Led_type *led)
{
	Std_ReturnType ret = RET_NOT_OK;
	if(NULL_PTR == led || led->pin >= TOTAL_PINS)
	{
		return ret;
	}
	else
	{
		DIO_TogglePin(led->pin);
		ret = RET_OK;
	}
	return ret;
}

