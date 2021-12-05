/*
 * Motor.h
 *
 * Created: 10/31/2021 1:54:10 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_



#include "DIO_Interface.h"

/********************** pin config*************************/

#define   IN1_M1    PINC0
#define   IN2_M1    PINC1

#define   IN1_M2    PINC2
#define   IN2_M2    PINC3

/***********************************************************/

typedef enum{
	M1,
	M2,
	M3,
	M4
}MOTOR_type;



void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);
void MOTOR_Stop(MOTOR_type motor);

/*Robot*/
void ROBOT_MoveForward(void);
void ROBOT_MoveBackward(void);
void ROBOT_MoveRight(void);
void ROBOT_MoveLeft(void);
void ROBOT_Stop(void);



#endif /* MOTOR_H_ */