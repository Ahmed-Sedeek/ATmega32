/*
 * Motor.c
 *
 * Created: 10/31/2021 1:53:26 PM
 *  Author: Ahmed Sedeek
 */ 



#include "MOTOR.h"



void MOTOR_CW(MOTOR_type motor)
{
	switch(motor)
	{
		case M1:
		DIO_WritePin(IN1_M1,HIGH);
		DIO_WritePin(IN2_M1,LOW);
		break;
		case  M2:
		DIO_WritePin(IN1_M2,HIGH);
		DIO_WritePin(IN2_M2,LOW);
		break;
	}
	
	
}

void MOTOR_CCW(MOTOR_type motor)
{
	switch(motor)
	{
		case M1:
			DIO_WritePin(IN1_M1,LOW);
			DIO_WritePin(IN2_M1,HIGH);
		break;
		
		case  M2:
			DIO_WritePin(IN1_M2,LOW);
			DIO_WritePin(IN2_M2,HIGH);
		break;
	}
}

void MOTOR_Stop(MOTOR_type motor)
{
	switch(motor)
	{
		case M1:
			DIO_WritePin(IN1_M1,LOW);
			DIO_WritePin(IN2_M1,LOW);
		break;
		
		case  M2:
			DIO_WritePin(IN1_M2,LOW);
			DIO_WritePin(IN2_M2,LOW);
		break;
	}
}

void ROBOT_MoveForward(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
}


void ROBOT_MoveBackward(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
}

void ROBOT_MoveRight(void)
{
	MOTOR_CW(M1);
	MOTOR_CCW(M3);
}

void ROBOT_MoveLeft(void)
{
	MOTOR_CW(M2);
	MOTOR_CCW(M4);
}

void ROBOT_Stop(void)
{
	MOTOR_Stop(M1);
	MOTOR_Stop(M2);
	MOTOR_Stop(M3);
	MOTOR_Stop(M4);
}

