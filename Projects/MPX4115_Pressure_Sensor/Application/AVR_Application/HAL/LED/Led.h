/*
 * Led.h
 *
 * Created: 11/2/2021 4:47:56 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef LED_H_
#define LED_H_


/*------------ Include Section ------------*/

#include "DIO_Interface.h"


/*---------------- Macros ----------------*/
#define  LED_SEQ_NUMBER		8

/*---------------- Type Defined ----------------*/

typedef enum
{
	LED_OFF,
	LED_ON
}LED_Status_type;

typedef struct
{
	DIO_Pin_type pin;
	LED_Status_type led_status;
}Led_type;




/*------------ Functions Prototypes ------------*/

Std_ReturnType LED_Init(Led_type *led);
Std_ReturnType LED_On(Led_type *led);
Std_ReturnType LED_Off(Led_type *led);
Std_ReturnType LED_Toggle(Led_type *led);




#endif /* LED_H_ */