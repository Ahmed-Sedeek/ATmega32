/*
 * @File		: AVR_Application.c
 * @Created     : 10/31/2021 1:30:27 PM
 * @Author      : Ahmed Sedeek
 * @GitHub      : https://github.com/Ahmed-Sedeek
 * @Linked In   : https://www.linkedin.com/in/ahmed-sedeek-/
 */ 


/*================================================================
 * @Project			: 
 * @Platform		: ATmega
 * @Peripheral		: ATmega32
  ================================================================*/ 


/* ================ Linking Section ================ */
#include "Application.h"

/* ================ Definition Section ================ */

/* ================ Global Declaration Section ================ */

/*Leds Initializations*/
// Led_type led1 = {.pin = PINC0, .led_status = LED_OFF};
// Led_type led2  = {.pin = PINC1, .led_status = LED_OFF};
	
/*buttons Initializations*/
 //Button_type button1 = {.pin = PIND2, .button_status = BUTTON_NOT_PRESSED};
 //Button_type button2  = {.pin = PIND3, .button_status = BUTTON_NOT_PRESSED};
	 
Button_Status_type button1_status = ZERO_INIT;

/* ================ Main Function Section ================ */
int main(void)
{
	/* Application Initialization */
	Application_Init(); 
	
	
	
    while (1)
    {
		
	}
}


/*================ Sub Program Section ================*/
void Application_Init(void)
{
	DIO_Init(); // Initializing pins direction.
	LCD_Init();
// 	ADC_Init(ADC_VCC, ADC_SCALER_64);
	
	/*leds*/
// 	LED_Init(&led1);
//	LED_Init(&led2);
	/*buttons*/
// 	Button_Init(&button1);
// 	Button_Init(&button2);
}



/*========================================================================
 *	  Revision Log
 *	  Date			   By				Ticket No.			Description
 	  --------------   --------------   --------------		--------------
      4Dec2021		   Ahmed Sedeek	    Ticket-1			Main File
  ========================================================================*/ 
