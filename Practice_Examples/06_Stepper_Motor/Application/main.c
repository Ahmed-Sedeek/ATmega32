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
	Stepper_Steps_CW(64);
	
    while (1)
    {
		
    }
}


/************************************************************************/
/*                           Application Initialization                 */
/************************************************************************/
void Application_Init(void)
{
	/*DIO_Init(); // Initializing pins direction.
	LCD_Init();
	ADC_Init(ADC_VCC, ADC_SCALER_64);
	*/
}

