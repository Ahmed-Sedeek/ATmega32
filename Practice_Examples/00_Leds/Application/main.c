/*
 * AVR_Application.c
 *
 * Created: 10/31/2021 1:30:27 PM
 * Author : Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Application.h"

/*------------ Initialization -------------*/



Led_type ledsSeq[LED_SEQ_NUMBER] = 
{
	{.pin = PINC0, .led_status = LED_OFF},
	{.pin = PINC1, .led_status = LED_OFF},
	{.pin = PINC2, .led_status = LED_OFF},
	{.pin = PINC3, .led_status = LED_OFF},
	{.pin = PINC4, .led_status = LED_OFF},
	{.pin = PINC5, .led_status = LED_OFF},
	{.pin = PINC6, .led_status = LED_OFF},
	{.pin = PINC7, .led_status = LED_OFF}
};

u8 Led_Battery[][LED_SEQ_NUMBER] =
{
	{1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,1,1,1,1,1}
};
void Perform_Led_Seq(Led_type ledsSeq[], u8 Led_Battery[][LED_SEQ_NUMBER], u8 seqLen);

/************************************************************************/
/*                                   Main                               */
/************************************************************************/
int main(void)
{
	Application_Init();
    while (1)
    {
	    
		Perform_Led_Seq(ledsSeq, Led_Battery, 8);
    }
}

void Application_Init(void)
{
	
	//DIO_Init(); // Initializing pins direction.
}

void Perform_Led_Seq(Led_type ledsSeq[], u8 Led_Battery[][LED_SEQ_NUMBER], u8 seqLen)
{
	u8 ledCounter = ZERO_INIT, ledPos = ZERO_INIT;
	for (ledCounter = ZERO_INIT; ledCounter < seqLen; ledCounter++)
	{
		LED_Init(&ledsSeq[ledCounter]);
	}
	for (ledCounter = ZERO_INIT; ledCounter < seqLen; ledCounter++)
	{
		for (ledPos = ZERO_INIT; ledPos < LED_SEQ_NUMBER; ledPos++)
		{
			if (LED_ON == Led_Battery[ledCounter][ledPos])
			{
				LED_On(&ledsSeq[ledPos]);
			}
			else
			{
				LED_Off(&ledsSeq[ledPos]);
			}
		}
		_delay_ms(250);
	}
}