/*
 * AVR_Application.c
 *
 * Created: 10/31/2021 1:30:27 PM
 * Author : Ahmed Sedeek
 */ 

/*-------------------- Includes --------------------*/

#include "Application.h"


/*Initialization*/
/*convert from*/
Button_type decFromButton = {.pin = PINC0, .button_status = BUTTON_NOT_PRESSED};
Button_type hexFromButton = {.pin = PINC1, .button_status = BUTTON_NOT_PRESSED};
Button_type binFromButton = {.pin = PINC2, .button_status = BUTTON_NOT_PRESSED};
/*convert to*/
Button_type decButton = {.pin = PIND2, .button_status = BUTTON_NOT_PRESSED};
Button_type hexButton = {.pin = PIND3, .button_status = BUTTON_NOT_PRESSED};
Button_type binButton = {.pin = PIND4, .button_status = BUTTON_NOT_PRESSED};
Button_type convertButton = {.pin = PIND5, .button_status = BUTTON_NOT_PRESSED};

/*Buttons Status*/


Button_Status_type decButtonStatus = ZERO_INIT; // Button status
Button_Status_type hexButtonStatus = ZERO_INIT; // Button status
Button_Status_type binButtonStatus = ZERO_INIT; // Button status


Button_Status_type convertButtonStatus = ZERO_INIT; // Button status

/*variables*/
u8 ConvFrom, ConvTo, convFlag = 0;


u8 hexToDec[] = "AF"; // Hex to be passed to hexToDecimal function
u8 hexToDecToBin[] = "0";


/************************************************************************/
/*                                   Main                               */
/************************************************************************/
int main(void)
{
	/**********************/
	DConverter_AppInit(); // D-Converter Application Initialization
	/**********************/
	Starting_Message();     
    while (1)
    {		

		ConvFrom = Convert_From_Option();
		ConvTo = Convert_To_Option();
		
		Pressed_Key();
		convFlag = 0;
		
		
		
		
    }
}


/************************************************************************/
/*                           Application Initialization                 */
/************************************************************************/
void DConverter_AppInit(void)
{
	DIO_Init(); // Initializing pins direction.
	LCD_Init();
	
	Button_Init(&decButton); // Initializing decimal choice button
	Button_Init(&hexButton); // Initializing hexadecimal choice button
	Button_Init(&binButton); // Initializing binary choice button
	Button_Init(&convertButton); // Initializing convert action choice button
}
/*-----------------------------------------------------------------------*/


/*No buttons*/
void Starting_Message(void)
{
	LCD_GoToWriteString(FIRST_LINE, CELL_3, "-Welcome to-");
	_delay_ms(1000);
	LCD_GoToWriteString(SECOND_LINE, CELL_3, "D-Converter");
	_delay_ms(1000);
	
	LCD_Clear();
	_delay_ms(1000);
	
	LCD_GoToWriteString(FIRST_LINE, CELL_6, "-By-");
	_delay_ms(1000);
	LCD_GoToWriteString(SECOND_LINE, CELL_3, "Ahmed Sedeek");
	_delay_ms(1000);
	
	LCD_Clear();
	_delay_ms(1000);
	
	LCD_GoToWriteString(FIRST_LINE, CELL_4, "-Options-");
	_delay_ms(1000);
	LCD_GoToWriteString(SECOND_LINE, CELL_1, "Dec - Bin - Hex");
	_delay_ms(1000);
	
	LCD_Clear();
	
	LCD_GoToWriteString(FIRST_LINE, CELL_2, "-Convert From-");
	_delay_ms(1000);
	LCD_GoToWriteString(SECOND_LINE, CELL_1, "Dec | Bin | Hex");
	_delay_ms(1500);
	
	LCD_Clear();
	
	_delay_ms(1000);
	LCD_GoToWriteString(FIRST_LINE, CELL_3, "-Convert To-");
	_delay_ms(1000);
	LCD_GoToWriteString(SECOND_LINE, CELL_1, "Dec | Bin | Hex");
	_delay_ms(1500);
	
	LCD_Clear();
	
	_delay_ms(1000);
	LCD_GoToWriteString(FIRST_LINE, CELL_1, "Press option to");
	LCD_GoToWriteString(SECOND_LINE, CELL_4, "choose..");	
		
}

u8 Convert_From_Option(void)
{
	u8 retFlag = ZERO_INIT;
	while(convFlag != 1)
	{
		Button_GetStatus(&decButton, &decButtonStatus);
		Button_GetStatus(&hexButton, &hexButtonStatus);
		Button_GetStatus(&binButton, &binButtonStatus);
	
		/*If the decimal button is pressed*/
		if (decButtonStatus == BUTTON_PRESSED && convFlag == 0)
		{
		
			LCD_Clear();
			LCD_WriteString("Converting from:");
			LCD_GoToWriteString(SECOND_LINE, CELL_1, "Decimal.");
			retFlag = DEC_BUTTON_FROM_PRESSED;
			convFlag = 1;
			_delay_ms(1000);
		}
	
		/*If the hexadecimal button is pressed*/
		else if(hexButtonStatus == BUTTON_PRESSED && convFlag == 0)
		{
		
			LCD_Clear();
			LCD_WriteString("Converting from:");
			LCD_GoToWriteString(SECOND_LINE, CELL_1, "Hexadecimal.");
			retFlag = HEX_BUTTON_FROM_PRESSED;
			convFlag = 1;
			_delay_ms(1000);
		}
	
		/*If the binary button is pressed*/
		else if(binButtonStatus == BUTTON_PRESSED && convFlag == 0)
		{
		
			LCD_Clear();
			LCD_WriteString("Converting from:");
			LCD_GoToWriteString(SECOND_LINE, CELL_1, "Binary.");
			retFlag = BIN_BUTTON_FROM_PRESSED;
			convFlag = 1;
			_delay_ms(1000);
		}
	}
	return retFlag;
}

u8 Convert_To_Option(void)
{
	u8 retFlag = ZERO_INIT;
	while(convFlag != 2)
	{
		Button_GetStatus(&decButton, &decButtonStatus);
		Button_GetStatus(&hexButton, &hexButtonStatus);
		Button_GetStatus(&binButton, &binButtonStatus);
		/*If the decimal button is pressed*/
		if (decButtonStatus == BUTTON_PRESSED && convFlag == 1)
		{
			LCD_Clear();
			LCD_WriteString("Converting to:");
			LCD_GoToWriteString(SECOND_LINE, CELL_1, "Decimal.");
			retFlag = DEC_BUTTON_TO_PRESSED;
			convFlag = 2;
			_delay_ms(1000);
		
		}
	
		/*If the hexadecimal button is pressed*/
		else if(hexButtonStatus == BUTTON_PRESSED && convFlag == 1)
		{
			LCD_Clear();
			LCD_WriteString("Converting to:");
			LCD_GoToWriteString(SECOND_LINE, CELL_1, "Hexadecimal.");
			retFlag = HEX_BUTTON_TO_PRESSED;
			convFlag = 2;
			_delay_ms(1000);
		}
	
		/*If the binary button is pressed*/
		else if(binButtonStatus == BUTTON_PRESSED && convFlag == 1)
		{
			LCD_Clear();
			LCD_WriteString("Converting to:");
			LCD_GoToWriteString(SECOND_LINE, CELL_1, "Binary.");
			retFlag = BIN_BUTTON_TO_PRESSED;
			convFlag = 2;
			_delay_ms(1000);
		}
	}
	return retFlag;
}

/*Keypad Pressed Key*/
void Pressed_Key(void)
{
	LCD_Clear();
	u8 pressedKey;
	u32 num = 0;
	u8 hexToDecStr[] = "0";
	//while(convFlag != 3)
	
	switch(ConvFrom)
	{
		case DEC_BUTTON_FROM_PRESSED:
			if (ConvTo == HEX_BUTTON_TO_PRESSED)
			{
				/*----------From decimal to hex----------*/
				LCD_GoToWriteString(FIRST_LINE, CELL_1, "Dec: ");
				LCD_GoToWriteString(SECOND_LINE, CELL_1, "Hex: ");
				LCD_GoTo(FIRST_LINE, CELL_5);
				
				//Button_GetStatus(&convertButton, &convertButtonStatus);
				while(convFlag != 3)
				{
					pressedKey = KEYPAD_GetKey();
					
					/*Check the pressed key*/
					if(pressedKey != NO_KEY)
					{
						
						/*If the key is a number*/
						if (pressedKey >= '0' && pressedKey <= '9')
						{
							num = num*10 + (pressedKey - '0');
							LCD_WriteChar(pressedKey);
						}
					} 
					Button_GetStatus(&convertButton, &convertButtonStatus);
					if (convertButtonStatus == BUTTON_PRESSED)
					{
						LCD_GoTo(SECOND_LINE, CELL_5);
						LCD_WriteString("0x");
						LCD_GoTo(SECOND_LINE, CELL_7);
						LCD_WriteHex(num);
						convFlag = 3;
					}
				}
				
			}
			else if (ConvTo == BIN_BUTTON_TO_PRESSED)
			{
				/*-------From decimal to binary-------*/
				LCD_GoToWriteString(FIRST_LINE, CELL_1, "Dec: ");
				LCD_GoToWriteString(SECOND_LINE, CELL_1, "Bin: ");
				LCD_GoTo(FIRST_LINE, CELL_5);
				
				while(convFlag != 3)
				{
					pressedKey = KEYPAD_GetKey();
			
					/*Check the pressed key*/
					if(pressedKey != NO_KEY)
					{
						/*If the key is a number*/
						if (pressedKey >= '0' && pressedKey <= '9')
						{
							num = num*10 + (pressedKey - '0');
							LCD_WriteChar(pressedKey);
						}
					}
					Button_GetStatus(&convertButton, &convertButtonStatus);
					if (convertButtonStatus == BUTTON_PRESSED)
					{
						LCD_GoTo(SECOND_LINE, CELL_5);
						LCD_WriteString("0b");
						LCD_GoTo(SECOND_LINE, CELL_7);
						LCD_WriteBinary(num);
						convFlag = 3;
					}
				}
				
			}
		break; // convert from decimal
		
		case HEX_BUTTON_FROM_PRESSED:
			if (ConvTo == DEC_BUTTON_TO_PRESSED)
			{
				/*------------From hex to decimal------------*/
				LCD_GoToWriteString(FIRST_LINE, CELL_1, "Hex: ");
				LCD_GoToWriteString(SECOND_LINE, CELL_1, "Dec: ");
				LCD_GoTo(FIRST_LINE, CELL_5);
				u8 i = 0;
				while(convFlag != 3)
				{
					
					pressedKey = KEYPAD_GetKey();
					/*Check the pressed key*/
					if(pressedKey != NO_KEY)
					{
						hexToDecStr[i] = pressedKey;
						LCD_WriteChar(pressedKey);
						i++;
					}
					/*If the convert button is pressed*/
					Button_GetStatus(&convertButton, &convertButtonStatus);
					if (convertButtonStatus == BUTTON_PRESSED)
					{
						LCD_GoTo(SECOND_LINE, CELL_5);
						LCD_HexToDec(hexToDecStr);
						convFlag = 3;
					}
					
				}
			}
			
			else if (ConvTo == BIN_BUTTON_TO_PRESSED)
			{
				/*-------------From hex to binary-------------*/
				LCD_GoToWriteString(FIRST_LINE, CELL_1, "Hex: ");
				LCD_GoToWriteString(SECOND_LINE, CELL_1, "Bin: ");
				LCD_GoTo(FIRST_LINE, CELL_5);

				u8 i = 0;
				while(convFlag != 3)
				{
					pressedKey = KEYPAD_GetKey();
					if(pressedKey != NO_KEY)
					{
						hexToDecStr[i] = pressedKey;
						LCD_WriteChar(pressedKey);
						i++;
					}
					/*If the convert button is pressed*/
					Button_GetStatus(&convertButton, &convertButtonStatus);
					if (convertButtonStatus == BUTTON_PRESSED)
					{
						LCD_GoToWriteString(SECOND_LINE, CELL_5, "0b");
						LCD_HexToBin(hexToDecStr);
						convFlag = 3;
					}
				}
			}
		break; // Convert from hexadecimal
		
		case BIN_BUTTON_FROM_PRESSED:
			if (ConvTo == DEC_BUTTON_TO_PRESSED)
			{
				/*-----------From binary to decimal-------------*/
				LCD_GoToWriteString(FIRST_LINE, CELL_1, "Bin: ");
				LCD_GoToWriteString(SECOND_LINE, CELL_1, "Dec: ");
				LCD_GoTo(FIRST_LINE, CELL_5);
				
			
				while(convFlag != 3)
				{
					pressedKey = KEYPAD_GetKey();
					if(pressedKey != NO_KEY)
					{
						/*If the key is a number*/
						if (pressedKey == '0' || pressedKey == '1')
						{
							num = num*10 + (pressedKey - '0');
							LCD_WriteChar(pressedKey);
						}
					}
					/*If the convert button is pressed*/
					Button_GetStatus(&convertButton, &convertButtonStatus);
					if (convertButtonStatus == BUTTON_PRESSED)
					{
						LCD_GoTo(SECOND_LINE, CELL_5);
						LCD_BinToDec(num);
						convFlag = 3;
					}
				}
			}
			else if (ConvTo == HEX_BUTTON_TO_PRESSED)
			{
				/*------------From binary to hex----------*/
				LCD_GoToWriteString(FIRST_LINE, CELL_1, "Bin: ");
				LCD_GoToWriteString(SECOND_LINE, CELL_1, "Hex: ");
				LCD_GoTo(FIRST_LINE, CELL_5);
				
				while(convFlag != 3)
				{
					pressedKey = KEYPAD_GetKey();
			
					/*Check the pressed key*/
					if(pressedKey != NO_KEY)
					{
						/*If the key is a number*/
						if (pressedKey == '0' || pressedKey == '1')
						{
							num = num*10 + (pressedKey - '0');
							LCD_WriteChar(pressedKey);
						}
					}
					
					/*If the convert button is pressed*/
					Button_GetStatus(&convertButton, &convertButtonStatus);
					if (convertButtonStatus == BUTTON_PRESSED)
					{
						LCD_GoToWriteString(SECOND_LINE, CELL_5, "0x");
						LCD_BinToHex(num);
						convFlag = 3;
					}
				}
			}
		break; // Convert from binary
	}
	return;
}

