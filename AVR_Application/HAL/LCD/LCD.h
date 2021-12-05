/*
 * LCD.h
 *
 * Created: 10/31/2021 1:55:49 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef LCD_H_
#define LCD_H_




#define  F_CPU   8000000
#include <util/delay.h>
#include "StdTypes.h"
#include "DIO_Interface.h"
#include <math.h>

#define  _4_BIT  1
#define  _8_BIT  2


/**************************pin config************************/

#define  LCD_MODE   _4_BIT

#define  RS          PINA1
#define  EN          PINA2

#define  D7			 PINA6
#define  D6			 PINA5
#define  D5			 PINA4
#define  D4			 PINA3

#define  LCD_PORT   PA

#define  FIRST_LINE		    0
#define  SECOND_LINE		1

typedef enum
{
	CELL_1,
	CELL_2,
	CELL_3,
	CELL_4,
	CELL_5,
	CELL_6,
	CELL_7,
	CELL_8,
	CELL_9,
	CELL_10,
	CELL_11,
	CELL_12,
	CELL_13,
	CELL_14,
	CELL_15,
	CELL_16
}LCD_CellNum_type;

void LCD_Init();

void LCD_Clear(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);

/*----------------- Converter ----------------*/
/*Decimal to.. */
void LCD_WriteNumber(s32 num);		// decimal
void LCD_WriteNumber_4D(u16 num);	// decimal
void LCD_WriteBinary(u8 num);		// Decimal to binary
void LCD_WriteHex(u8 num);			// Decimal to hexa

/*Hexadecimal to.. */
void LCD_HexToDec(u8 hexStr[]); //Hex to decimal, Passing the hex as a string
void LCD_HexToBin(u8 hexStr[]); // Hex to binary

/*Binary to.. */
void LCD_BinToDec(u32 binNumber);
void LCD_BinToHex(u16 binNumber);

void LCD_WriteFloat(double floatNum);



void LCD_GoTo(u8 line ,u8 cell);    // Go to line, col

void LCD_GoToClear(u8 line ,u8 cell,u8 numOfCells);

void LCD_GoToWriteString(u8 line,u8 cell,u8*str);
void LCD_Create_Character(u8*p,u8 Location);


#endif /* LCD_H_ */









 
 
  
   