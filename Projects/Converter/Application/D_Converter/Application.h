/*
 * Application.h
 *
 * Created: 11/2/2021 11:15:39 AM
 *  Author: Ahmed Sedeek
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

/*-------------------- Includes --------------------*/

//#include "DIO_Interface.h"

//#include "Led.h"
#include "Button.h"
#include "LCD.h"
#include "KeyPad.h"
#include <stdio.h>
#include "ADC.h"



/*----------------- Macros -----------------*/
#define DEC_BUTTON_FROM_PRESSED	    	1
#define HEX_BUTTON_FROM_PRESSED	    	2
#define BIN_BUTTON_FROM_PRESSED	    	3

#define DEC_BUTTON_TO_PRESSED	    	4
#define HEX_BUTTON_TO_PRESSED	    	5
#define BIN_BUTTON_TO_PRESSED	    	6

#define CONVERT_BUTTON_PRESSED		    7

/*Keypad*/
#define  MIN_NUM_LIMIT					0
#define  MAX_NUM_LIMIT					9



/*-------------------- Functions Prototypes --------------------*/

/*Opening application*/
void Starting_Message(void); // done
u8 Convert_From_Option(void); // done
u8 Convert_To_Option(void);
void Pressed_Key(void);

void DConverter_AppInit(void);


/*Keypad*/

#endif /* APPLICATION_H_ */