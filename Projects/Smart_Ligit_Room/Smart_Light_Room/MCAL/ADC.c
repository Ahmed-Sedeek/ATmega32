/*
 * ADC.c
 *
 * Created: 11/12/2021 4:42:49 PM
 *  Author: Ahmed Sedeek
 */ 

#include "ADC.h"

void ADC_Init(ADC_Vref_type vref, ADC_Scaler_type scaler)
{
	// Voltage reference
	switch( vref)
	{
		case ADC_AREF: // External Voltage reference
			CLEAR_BIT(ADMUX, REFS1);
			CLEAR_BIT(ADMUX, REFS0);
		break;
		
		case ADC_VCC: // Vcc Voltage reference
			CLEAR_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
		break;
		
		case ADC_256:  // internal Voltage reference 2.56 v
			SET_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
		break;
	}
	
	// Selecting adjust read to the right
	CLEAR_BIT(ADMUX, ADLAR);
	
	// Prescaller (clock) 
	ADCSRA = ADCSRA & 0xf8; // 11111000, making the first three zeros to write the scaller on them
	scaler = scaler & 0xf07; // 00000111, making sure that the last five bits of the scaler are 0s
	ADCSRA = ADCSRA | scaler; // Write the scaller value in the first 3 bits of the resister
	
	
	// ADC enable
	SET_BIT(ADCSRA, ADEN);
	
}

u16 ADC_Read(ADC_Channel_type ch)
{
	// Select channel	
	ADMUX &= 0xE0; // Clearing the first 5 bits of the register 0b11100000, to not take old channel
	ADMUX |= ch;   // Writing the channel in the first 5 bits of the register
	
	// Start conversion 
	SET_BIT(ADCSRA, ADSC);
	
	
	// W8 until conversion ends
	while(READ_BIT(ADCSRA, ADSC)); // busy wait
	
	//Reading ADC
	return ADC;
}