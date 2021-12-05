/*
 * KeyPad.h
 *
 * Created: 11/5/2021 2:53:14 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*----------------- Include Section -----------------*/

#include "DIO_Interface.h"
#include <stdio.h>

/*------------- config ----------------*/

/*-------------------- Macros --------------------*/
#define  FIRST_OUTPUT	PINB0 // ROWs
#define  FIRST_INPUT	PINB4 // COLs

#define  ROWS	4
#define  COLS	4

#define  KEYPAD_PORT	PB

#define  NO_KEY	  'N'



static u8 KeysArray[ROWS][COLS] =
{
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'F', '0', 'E', 'D'}
};

/*-------------------- Functions Prototypes --------------------*/
u8 KEYPAD_GetKey(void);

#endif /* KEYPAD_H_ */