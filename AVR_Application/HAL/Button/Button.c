/*
 * Button.c
 *
 * Created: 11/1/2021 1:49:33 PM
 *  Author: Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Button.h"


Std_ReturnType Button_Init(Button_type* button)
{
	Std_ReturnType ret = RET_NOT_OK;
	if(NULL_PTR == button || button->pin >= TOTAL_PINS)
	{
		return ret;
	}
	else
	{
		DIO_InitPin(button->pin, INPULL);
		ret = RET_OK;
	}
	return ret;
}

Std_ReturnType Button_GetStatus(Button_type* button, Button_Status_type* button_status)
{
	Std_ReturnType ret = RET_NOT_OK;
	if(NULL_PTR == button || button->pin >= TOTAL_PINS)
	{
		return ret;
	}
	else
	{
		*button_status = DIO_ReadPin(button->pin);
		button->button_status = *button_status;
		ret = RET_OK;
	}
	return ret;
}