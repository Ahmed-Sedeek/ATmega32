/*
 * Stepper_Motor.c
 *
 * Created: 11/10/2021 7:43:04 PM
 *  Author: Ahmed Sedeek
 */ 

#include "Stepper_Motor.h"
#include <util/delay.h>

void Stepper_BiPolar_CW(void)
{
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
}
void Stepper_BiPolar_CCW(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
}


void Stepper_UniPolar_CW(void)
{
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
}
void Stepper_UniPolar_CCW(void)
{
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	
	
}

void Stepper_UniPolar_CW_Step1(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}
void Stepper_UniPolar_CW_Step2(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}
void Stepper_UniPolar_CW_Step3(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
void Stepper_UniPolar_CW_Step4(void)
{
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}

void Stepper_UniPolar_HS_CW(void)
{
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
}
void Stepper_UniPolar_HS_CCW(void)
{
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	
}

/*Unipolar stepper motor*/
void Stepper_Steps_CW(u16 step) /// 50 step => 12
{
	u8 stepFlag = 0;
	
	for (u8 i = 0; i < step; i++)
	{
		if (stepFlag == 0)
		{
			Stepper_UniPolar_CW_Step1();
			stepFlag = 1;
		}
		else if (stepFlag == 1)
		{
			Stepper_UniPolar_CW_Step2();
			stepFlag = 2;
		}
		else if (stepFlag == 2)
		{
			Stepper_UniPolar_CW_Step3();
			stepFlag = 3;
		}
		else if (stepFlag == 3)
		{
			Stepper_UniPolar_CW_Step4();
			stepFlag = 0;
		}
	}
}

void Stepper_Angle(u16 angle)
{
	u16 steps = (u32)(angle * 2048) / 360;
	Stepper_Steps_CW(steps);
}