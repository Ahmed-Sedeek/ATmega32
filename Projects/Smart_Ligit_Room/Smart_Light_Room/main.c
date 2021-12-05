/*
 * AVR_Application.c
 *
 * Created: 10/31/2021 1:30:27 PM
 * Author : Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Application.h"


Led_type ledsSeq[LED_SEQ_NUMBER] =
{
	{.pin = PIND0, .led_status = LED_OFF},
	{.pin = PIND1, .led_status = LED_OFF},
	{.pin = PIND2, .led_status = LED_OFF},
	{.pin = PIND3, .led_status = LED_OFF},
	{.pin = PIND4, .led_status = LED_OFF},
	{.pin = PIND5, .led_status = LED_OFF},
	{.pin = PIND6, .led_status = LED_OFF},
	{.pin = PIND7, .led_status = LED_OFF}
};

/************************************************************************/
/*                                   Main                               */
/************************************************************************/
int main(void)
{
	/**********************/
	Application_Init(); // Application Initialization
	/**********************/
	
	u16 adcRead;
	LCD_GoTo(FIRST_LINE, CELL_1);
	LCD_WriteString("ADC Reading:");
    while (1)
    {
		
		 adcRead = ADC_Read(CH_7);
		 LCD_GoTo(SECOND_LINE, CELL_1);
		 LCD_WriteNumber(adcRead);
		 if (adcRead > 847 && adcRead <= 975)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_Off(&ledsSeq[1]);
			 LED_Off(&ledsSeq[2]);
			 LED_Off(&ledsSeq[3]);
			 LED_Off(&ledsSeq[4]);
			 LED_Off(&ledsSeq[5]);
			 LED_Off(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead > 726 && adcRead <= 847)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_Off(&ledsSeq[2]);
			 LED_Off(&ledsSeq[3]);
			 LED_Off(&ledsSeq[4]);
			 LED_Off(&ledsSeq[5]);
			 LED_Off(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead > 605 && adcRead <= 726)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_On(&ledsSeq[2]);
			 LED_Off(&ledsSeq[3]);
			 LED_Off(&ledsSeq[4]);
			 LED_Off(&ledsSeq[5]);
			 LED_Off(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead > 484 && adcRead <= 605)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_On(&ledsSeq[2]);
			 LED_On(&ledsSeq[3]);
			 LED_Off(&ledsSeq[4]);
			 LED_Off(&ledsSeq[5]);
			 LED_Off(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead > 400 && adcRead <= 484)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_On(&ledsSeq[2]);
			 LED_On(&ledsSeq[3]);
			 LED_On(&ledsSeq[4]);
			 LED_Off(&ledsSeq[5]);
			 LED_Off(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead > 360 && adcRead <= 400)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_On(&ledsSeq[2]);
			 LED_On(&ledsSeq[3]);
			 LED_On(&ledsSeq[4]);
			 LED_On(&ledsSeq[5]);
			 LED_Off(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead > 320 && adcRead <= 360)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_On(&ledsSeq[2]);
			 LED_On(&ledsSeq[3]);
			 LED_On(&ledsSeq[4]);
			 LED_On(&ledsSeq[5]);
			 LED_On(&ledsSeq[6]);
			 LED_Off(&ledsSeq[7]);
		 }
		 else if (adcRead >= 0 && adcRead <= 320)
		 {
			 LED_On(&ledsSeq[0]);
			 LED_On(&ledsSeq[1]);
			 LED_On(&ledsSeq[2]);
			 LED_On(&ledsSeq[3]);
			 LED_On(&ledsSeq[4]);
			 LED_On(&ledsSeq[5]);
			 LED_On(&ledsSeq[6]);
			 LED_On(&ledsSeq[7]);
		 }
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
	
	/* 8 Leds Initializations */
	for (u8 ledCounter = ZERO_INIT; ledCounter < LEDS_SEQ; ledCounter++)
	{
		LED_Init(&ledsSeq[ledCounter]);
	}
}

