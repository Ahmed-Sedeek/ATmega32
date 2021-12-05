/*
 * AVR_Application.c
 *
 * Created: 10/31/2021 1:30:27 PM
 * Author : Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Application.h"

/*Initialization*/
Led_type led1 = {.pin = PINC0, .led_status = LED_OFF};
Button_type button1 = {.pin = PIND0, .button_status = BUTTON_NOT_PRESSED};

Button_Status_type button1_status = ZERO_INIT;
/************************************************************************/
/*                                   Main                               */
/************************************************************************/
int main(void)
{
	Application_Init();
    while (1)
    {
	    Button_GetStatus(&button1, &button1_status);
		if (button1_status == BUTTON_PRESSED)
		{
			LED_On(&led1);
		}
		else
		{
			LED_Off(&led1);
		}
    }
}

void Application_Init(void)
{
	Button_Init(&button1);
	LED_Init(&led1);
	//DIO_Init(); // Initializing pins direction.
}
