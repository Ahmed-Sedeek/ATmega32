/*
 * LCD.c
 *
 * Created: 10/31/2021 1:56:49 PM
 *  Author: Ahmed Sedeek
 */ 


#include "LCD.h"

/*-----------------------8 Bit mode---------------------------*/

#if LCD_MODE==_8_BIT

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);//  2 line,5*7;
	LCD_WriteCommand(0x0c);//  cursor , 0x0f,  0x0e;
	LCD_WriteCommand(0x01);//  clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);//  increase ddram address , no shift
}
/*-----------------------4 Bit mode---------------------------*/
#elif LCD_MODE==_4_BIT
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);//  2 line,5*7;
	LCD_WriteCommand(0x0c);//  cursor , 0x0f,  0x0e;
	LCD_WriteCommand(0x01);//  clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);//  increase ddram address , no shift
}
#endif


/*************************************************************************************/


void LCD_WriteChar(u8 ch) // char
{
	LCD_WriteData(ch);
}

void LCD_WriteString(u8*str) // string
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

/*Decimal to.. */

void LCD_WriteNumber(s32 num)//+ve , -ve numbers
{
	u8 str[20];
	u8 rem,i=0;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num>0)
	{
		rem=num%10;
		str[i]=rem+'0';
		num=num/10;
		i++;
	}
	for (s8 j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
}

void LCD_WriteBinary(u8 num)// decimal to binary
{
	s8 i,flag=0;
	for (i=7;i>=0;i--)
	{
		if ((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;
		}
		else
		{
			if (flag==1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}

}

//u8 HexArray[]={'0','1','A'};

void LCD_WriteHex(u8 num)// decimal to hex
{
	u8 Hnibble=num>>4;//0f
	u8 Lnibble =num&0x0f;//0e
	if (Hnibble<=9)
	{
		LCD_WriteChar(Hnibble+'0');
	}
	else
	{
		LCD_WriteChar(Hnibble-10+'A');
	}
	if (Lnibble<=9)
	{
		LCD_WriteChar(Lnibble+'0');
	}
	else
	{
		LCD_WriteChar(Lnibble-10+'A');
	}
	
	//LCD_WriteChar(HexArray[Lnibble]);
	
	
	
}

/*Hexadecimal to.. */
void LCD_HexToDec(u8 hexStr[])
{
	u8 i, len, num = ZERO_INIT;
	u8 decValue = 0;
	u8 base = 1; // base of hex
	
	len = strlen(hexStr); // hex number length
	
	for (int i = len-1; i >= 0; i--)
	{
		if (hexStr[i] >= '0' && hexStr[i] <= '9')
		{
			decValue = decValue + ((hexStr[i] - '0')) * base;
			base *= 16;
		}
		else if (hexStr[i] >= 'A' && hexStr[i] <= 'F')
		{
			decValue = decValue + ((hexStr[i] - 55)) * base;
			base *= 16;
		}
		else if (hexStr[i] >= 'a' && hexStr[i] <= 'f')
		{
			decValue = decValue + ((hexStr[i] - '0' + 10)) * base;
			base *= 16;
		}
	}
	LCD_WriteNumber(decValue);
}

void LCD_HexToBin(u8 hexStr[])
{
	u8 i, len, num = ZERO_INIT;
	u8 decValue = 0;
	u8 base = 1; // base of hex
	
	len = strlen(hexStr); // hex number length
	
	for (int i = len-1; i >= 0; i--)
	{
		if (hexStr[i] >= '0' && hexStr[i] <= '9')
		{
			decValue = decValue + ((hexStr[i] - '0')) * base;
			base *= 16;
		}
		else if (hexStr[0] >= 'A' && hexStr[i] <= 'F')
		{
			decValue = decValue + ((hexStr[i] - 55)) * base;
			base *= 16;
		}
		else if (hexStr[0] >= 'a' && hexStr[i] <= 'f')
		{
			decValue = decValue + ((hexStr[i] - '0' + 10)) * base;
			base *= 16;
		}
	}
	LCD_WriteBinary(decValue);
}

/*Binary to.. */
void LCD_BinToDec(u32 binNumber)
{
	u32 decNumber = 0;
	u8  rem, base = 1;
	while (binNumber != 0)
	{
		rem = binNumber % 10;
		decNumber = decNumber + (rem * base);
		binNumber /= 10;
		base *= 2;
	}
	LCD_WriteNumber(decNumber);
}

void LCD_BinToHex(u16 binNumber)
{
	u16 decNumber = 0;
	u8  rem, base = 1;
	while (0 != binNumber)
	{
		rem = binNumber % 10;
		decNumber = decNumber + (rem * base);
		binNumber /= 10;
		base *= 2;
	}
	LCD_WriteHex(decNumber);
}

void LCD_WriteNumber_4D(u16 num)//14542
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_GoTo(u8 line ,u8 cell)
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+cell);
	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
	
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_GoToClear(u8 line ,u8 cell,u8 numOfCells)
{
	u8 i;
	LCD_GoTo(line,cell);
	for (i=0;i<numOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
	
}

void LCD_GoToWriteString(u8 line,u8 cell,u8*str)
{
	LCD_GoTo(line,cell);
	LCD_WriteString(str);
}

void LCD_Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]); //Pass the bytes of pattern on LCD
	LCD_WriteCommand(0x80);
}

void LCD_WriteFloat(double floatNum)
{
	/*Integer Part*/
	LCD_WriteNumber(floatNum);
	LCD_WriteChar('.');
	u8 integer = floatNum;
	
	/*Float part*/
	double fraction = floatNum - integer;
	u8 intToFlo = fraction * 100;
	LCD_WriteNumber(intToFlo);

}