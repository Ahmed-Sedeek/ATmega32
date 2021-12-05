/*
 * ADC.h
 *
 * Created: 11/12/2021 4:43:11 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef ADC_H_
#define ADC_H_

/*------------ Include Section --------------*/
#include "Utils.h"
#include "MemMap.h"
#include "StdTypes.h"

#define F_CPU 8000000UL
#include <util/delay.h>

typedef enum
{
	ADC_AREF = 0,  // External Voltage reference
	ADC_VCC ,      // Vcc Voltage reference
	ADC_256 = 3	   // internal Voltage reference 2.56 v
}ADC_Vref_type; /* Voltage reference */

typedef enum{	ADC_SCALER_2=0,	ADC_SCALER_4=2,	ADC_SCALER_8,	ADC_SCALER_16,	ADC_SCALER_32,	ADC_SCALER_64,	ADC_SCALER_128	}ADC_Scaler_type; // ADC clock source Scaler divided by..


typedef enum{	CH_0=0,	CH_1,	CH_2,	CH_3,	CH_4,	CH_5,	CH_6,	CH_7}ADC_Channel_type; // ADC Channels


void ADC_Init(ADC_Vref_type vref, ADC_Scaler_type scaler);

/*Reads the ADC Registers from the selected channel*/
u16 ADC_Read(ADC_Channel_type ch);


#endif /* ADC_H_ */