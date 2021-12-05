/*
 * Seven_Segment.c
 *
 * Created: 11/1/2021 6:38:27 AM
 *  Author: Ahmed Sedeek
 */ 

#include "DIO_Interface.h"
#include "Seven_Segment.h"

u8 SegmentNumbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

/*Displays numbers from 0 to 9 on one seven sigma*/
void Segment_Display(u8 number)
{
	DIO_WritePort(PD, SegmentNumbers[number]<<1);
}

/*Displays numbers from 0 to 99 on two seven sigmas*/
void Segment_TwoDisplays(u8 number)
{
	DIO_WritePort(PD, SegmentNumbers[number/10]);
	DIO_WritePort(PC, SegmentNumbers[number%10]);
}

void Segment_Display_BCD(u8 number)
{
	DIO_WritePort(PD, number);
}

void Segment_TwoDisplays_BCD(u8 number)
{
	int firstDigit = number %10;
	int secondDigit = number / 10;
	DIO_WritePort(PD, secondDigit | (firstDigit<<4));
}


