/*
 * Stepper_Motor.h
 *
 * Created: 11/10/2021 7:43:29 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "DIO_Interface.h"
#include "StdTypes.h"
#include <util/delay.h>
//#define F_CPU 8000000UL
/**************************************************/

#define COIL1A  PINC0
#define COIL1B  PINC1
#define COIL2A  PINC2
#define COIL2B  PINC3

#define DELAY   1000

/**************************************************/
/*Full step*/
void Stepper_BiPolar_CW(void);
void Stepper_BiPolar_CCW(void);

/*Full step*/
void Stepper_UniPolar_CW(void);
void Stepper_UniPolar_CCW(void);

/*Just one step (Full round)*/
void Stepper_UniPolar_CW_Step1(void);
void Stepper_UniPolar_CW_Step2(void);
void Stepper_UniPolar_CW_Step3(void);
void Stepper_UniPolar_CW_Step4(void);

/*Half step*/
void Stepper_UniPolar_HS_CW(void);
void Stepper_UniPolar_HS_CCW(void);


void Stepper_Steps_CW(u16 step);
void Stepper_Angle(u16 angle);

#endif /* STEPPER_MOTOR_H_ */