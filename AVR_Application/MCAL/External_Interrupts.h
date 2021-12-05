/*
 * External_Interrupts.h
 *
 * Created: 12/1/2021 2:49:58 AM
 *  Author: Ahmed Sedeek
 */ 


#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "led.h"
#include "DIO_Interface.h"

/*--------------- Macros Definitions ---------------*/
#define EXT_INT2_FALLING_EDGE	0
#define EXT_INT2_RISING_EDGE	1


/*--------------- Type Definitions ---------------*/
typedef enum
{
	EXT_INT_LowLevel = 0,
	EXT_INT_LogicalChange,
	EXT_INT_Falling_Edge,
	EXT_INT_RisingEdge
}EXT_IntEdge_type;


/*--------------- Functions Prototypes ---------------*/

/*External interrupts enable*/
void EXTERNAL_INT0_Enable(void);
void EXTERNAL_INT1_Enable(void);
void EXTERNAL_INT2_Enable(void); 

/*External interrupts disable*/
void EXTERNAL_INT0_Disable(void);
void EXTERNAL_INT1_Disable(void);
void EXTERNAL_INT2_Disable(void);

/*External interrupts setting edges*/
void EXTERNAL_INT0_Edge(EXT_IntEdge_type edge);
void EXTERNAL_INT1_Edge(EXT_IntEdge_type edge);
void EXTERNAL_INT2_Edge(u8 edge); // either 0 (falling) or1 (rising)


/*External Interrupts Vectors*/
ISR(INT0_vect);
ISR(INT1_vect);
ISR(INT2_vect);

#endif /* EXTERNAL_INTERRUPTS_H_ */