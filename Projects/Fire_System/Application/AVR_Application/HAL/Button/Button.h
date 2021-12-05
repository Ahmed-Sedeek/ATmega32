/*
 * Button.h
 *
 * Created: 11/1/2021 1:49:57 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

/*-------------------- Includes --------------------*/

#include "DIO_Interface.h"

/*---------------- Type Defined ----------------*/

typedef enum
{
	BUTTON_PRESSED,
	BUTTON_NOT_PRESSED
	
}Button_Status_type;

typedef struct
{
	DIO_Pin_type pin : 6;
	Button_Status_type button_status : 1;
	u8 resreved :  1;
}Button_type;

/*------------ Functions Prototypes ------------*/

Std_ReturnType Button_Init(Button_type* button);
Std_ReturnType Button_GetStatus(Button_type* button, Button_Status_type* button_status);



#endif /* BUTTON_H_ */