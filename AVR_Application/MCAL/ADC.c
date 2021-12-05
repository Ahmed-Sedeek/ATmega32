/*
 * ADC.c
 *
 * Created: 11/12/2021 4:42:49 PM
 *  Author: Ahmed Sedeek
 */ 

#include "ADC.h"

static u8 read_flag = 1;

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

/*Try not to use it, because the float number takes time*/
double ADC_Volt(u16 adcRead)
{
	double volt;
	volt = (5 * adcRead) / 1024;
	return volt;
}

u16 ADC_GetVolt(ADC_Channel_type ch)
{
	u16 adcRead = ADC_Read(ch);
	u16 volt = ((u32) adcRead * 5000) / 1024;
	return volt;
}


/* 2 Substitution functions for ADC_Read function */
void ADC_StartConversion(ADC_Channel_type ch)
{
	if (read_flag == 1)
	{
		// Select channel
		ADMUX &= 0xE0; // Clearing the first 5 bits of the register 0b11100000, to not take old channel
		ADMUX |= ch;   // Writing the channel in the first 5 bits of the register
		
		// Start conversion
		SET_BIT(ADCSRA, ADSC);
		read_flag = 0;
	}	
}

u16 ADC_GetRead(void)
{
	// W8 until conversion ends
	while(READ_BIT(ADCSRA, ADSC)); // busy wait
	
	read_flag = 1;
	//Reading ADC
	return ADC;
}


u16 ADC_GetReadPeriodicCheck(u16 *pdata)
{
	// W8 until conversion ends
	if(READ_BIT(ADCSRA, ADSC) == 0)
	{
		*pdata = ADC;
		read_flag = 1;
		return 1;
	}
	else
	{
		return 0;
	}
	
	//Reading ADC
	return ADC;
}

/*_______________________________________________________*/