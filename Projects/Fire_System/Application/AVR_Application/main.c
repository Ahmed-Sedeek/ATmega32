/*
 * AVR_Application.c
 *
 * Created: 10/31/2021 1:30:27 PM
 * Author : Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Application.h"

/*Leds Initializations*/
Led_type heatLed = {.pin = PINC0, .led_status = LED_OFF};
Led_type fireLed  = {.pin = PINC1, .led_status = LED_OFF};
	
/*buttons Initializations*/
// Button_type button1 = {.pin = PINC0, .button_status = BUTTON_NOT_PRESSED};
// Button_type button2  = {.pin = PINC1, .button_status = BUTTON_NOT_PRESSED};
/************************************************************************/
/*                                   Main                               */
/************************************************************************/
int main(void)
{
	/**********************/
	Application_Init(); // Application Initialization
	/**********************/
	LCD_GoToWriteString(FIRST_LINE, CELL_1, "T:");
	
	/*Sensors*/
	u16 tempSensor, smokeSensor;
	u8 tempInt , tempFraction , smokeFlag = 0, fireFlag = 0;
	
    while (1)
    {
		tempSensor = LM35_GetTemp();
		tempInt = tempSensor / 10;
		tempFraction = tempSensor % 10;
		LCD_GoTo(FIRST_LINE, CELL_3);
		LCD_WriteNumber(tempInt);
		LCD_WriteChar('.');
		LCD_WriteNumber(tempFraction);
		
		if (tempInt < 35) 
		{
			LCD_GoToClear(SECOND_LINE, CELL_2, 14);
			LCD_GoToWriteString(SECOND_LINE, CELL_6, "-Cool-");
			LCD_GoToClear(FIRST_LINE, CELL_7, 10);
			
			LED_Off(&heatLed);
			LED_Off(&fireLed);
			DIO_WritePin(PINC4, LOW); // Fan (Motor) off
			DIO_WritePin(BUZZER, LOW); // Buzzer off
		}
		
		else if (tempInt >= 35 && tempInt < 65 && smokeFlag == 0)
		{
			LCD_GoToWriteString(FIRST_LINE, CELL_7, "**");
			smokeSensor = ADC_Read(CH_0);
			LCD_GoToWriteString(FIRST_LINE, CELL_9, "Smok:");
			LCD_GoTo(FIRST_LINE, CELL_14);
			LCD_WriteNumber(smokeSensor);
			LCD_GoToClear(SECOND_LINE, CELL_2, 14);
			LCD_GoToWriteString(SECOND_LINE, CELL_2, "-Heat Warning-");
			
			LED_On(&heatLed);
			LED_Off(&fireLed);
			MOTOR_Stop(M2); // Fan (Motor) off
			DIO_WritePin(BUZZER, LOW); // Buzzer off
			
			if (smokeSensor >= 770)
			{
				smokeFlag = 1;
			}
		}
			
		else if (tempInt >= 65 || 1 == smokeFlag)
		{
			LCD_GoToWriteString(FIRST_LINE, CELL_7, "**");
			smokeSensor = ADC_Read(CH_0);
			LCD_GoToWriteString(FIRST_LINE, CELL_9, "Smok:");
			LCD_GoTo(FIRST_LINE, CELL_14);
			LCD_WriteNumber(smokeSensor);
			
			LCD_GoToClear(SECOND_LINE, CELL_2, 14);
			LCD_GoToWriteString(SECOND_LINE, CELL_2, "-Fire Warning-");
			
			LED_Off(&heatLed);
			LED_On(&fireLed);
			MOTOR_CW(M2); // Fan (Motor) on
			DIO_WritePin(BUZZER, HIGH); // Buzzer on
			_delay_ms(500);
			DIO_WritePin(BUZZER, LOW); // Buzzer off
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
	
	/*leds*/
	LED_Init(&fireLed);
	LED_Init(&heatLed);
	/*buttons*/
// 	Button_Init(&button1);
// 	Button_Init(&button2);
}

