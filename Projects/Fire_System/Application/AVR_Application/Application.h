/*
 * Application.h
 *
 * Created: 11/2/2021 11:15:39 AM
 *  Author: Ahmed Sedeek
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

/*-------------------- Includes --------------------*/

#include "DIO_Interface.h"

#include "LCD.h"
#include "ADC.h"
#include "Sensors.h"
#include "Led.h"
#include "Motor.h"
#include "Button.h"

/*----------------- Macros -----------------*/
#define  BUZZER		PINC5


/*-------------------- Functions Prototypes --------------------*/


void Application_Init(void);


/*Keypad*/

#endif /* APPLICATION_H_ */