/*
 * AVR_Application.c
 *
 * Created: 10/31/2021 1:30:27 PM
 * Author : Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Application.h"




/************************************************************************/
/*                                   Main                               */
/************************************************************************/
int main(void)
{
	/**********************/
	Application_Init(); // Application Initialization
	/**********************/
	u16 pressure;
	u8 fraction, integer;
	LCD_WriteString("Pressure: ");
	
	
    while (1)
    {
		pressure = MPX4115_GetPressure();
		fraction = pressure % 10;
		integer = pressure / 10;
		LCD_GoTo(FIRST_LINE, CELL_10);
		LCD_WriteNumber(integer);
		LCD_WriteChar('.');
		LCD_WriteNumber(fraction);
		LCD_WriteString(" Kps");
		LCD_WriteString("    ");
    }
}


/************************************************************************/
/*                           Application Initialization                 */
/************************************************************************/
void Application_Init(void)
{
	DIO_Init(); // Initializing pins direction.
	LCD_Init();
	ADC_Init(ADC_VCC, ADC_SCALER_64);
}

