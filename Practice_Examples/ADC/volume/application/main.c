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
	u8 potPerc, printCount;
	u16 adcRead;
	
    u8 pattern[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    LCD_Create_Character(pattern, 1);
	LCD_WriteString("Volume: ");
	
	
    while (1)
    {
		potPerc = POT_GetPerc();
		adcRead = ADC_Read(CH_7);
		printCount = ((adcRead * 16) / 1024); //   printCount/#cellsPrinted(16) = adcRead/1024 
		LCD_GoTo(FIRST_LINE, CELL_9);
		LCD_WriteNumber(potPerc);
		LCD_WriteChar('%');
		LCD_WriteString("    ");
		
		LCD_GoTo(SECOND_LINE, CELL_1);
		for (u8 i = 0; i < printCount; i++)
		{
			LCD_WriteChar(1);
		}
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

