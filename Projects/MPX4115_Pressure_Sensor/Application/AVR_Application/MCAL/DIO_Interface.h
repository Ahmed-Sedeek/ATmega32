/*
 * DIO_Interface.h
 *
 * Created: 10/31/2021 1:49:57 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*---------------- Include Section ----------------*/

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"


/*---------------- Type Defined ----------------*/

typedef enum{
	PA=0,
	PB,
	PC,
	PD,
	TOTAL_PORTS
}DIO_Port_type; // Ports


typedef enum{
	OUTPUT,
	INFREE,
	INPULL

}DIO_PinStatus_type; // Pin Direction

typedef enum{
	PORT_OUTPUT,
	PORT_INFREE,
	PORT_INPULL

}DIO_PortStatus_type; // Port Direction


typedef enum
{
	LOW,
	HIGH
}DIO_PinVoltage_type; // Voltage

typedef enum
{
	DIRECTION_INPUT,
	DIRECTION_OUTPUT
}DIO_DirectionStatus_type; // Direction

typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type; 

/*----------------  ----------------*/

/*---------------- Functions Prototypes ----------------*/

/*Initializing pins directions*/
void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);
/*Write High or Low volt to the pin*/
void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);
/*Reads the status of the pin, High or Low*/
DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin);
/*Reading pin direction*/
DIO_DirectionStatus_type DIO_ReadPinDirection(DIO_Pin_type pin);
/*Toggling pin low to high or vise versa*/
void DIO_TogglePin(DIO_Pin_type pin);


/*---------------- PORTs Config ----------------*/

/*Initializing the port direction, and it's status*/
void DIO_InitPort(DIO_Port_type port,DIO_PortStatus_type status);
/*Write volt on the port, High, or Low*/
void DIO_WritePort(DIO_Port_type port,u8 value);
/*Reading the voltage status of the port*/
u8 DIO_ReadPort(DIO_Port_type port);
/*Reading port direction*/
Std_ReturnType DIO_ReadPortDirection(DIO_Port_type port);
/*Toggling port low to high or vise versa*/
void DIO_TogglePort(DIO_Port_type port);


/*Initializing all the DIOs Pins Directions*/
void DIO_Init(void);





#endif /* DIO_INTERFACE_H_ */