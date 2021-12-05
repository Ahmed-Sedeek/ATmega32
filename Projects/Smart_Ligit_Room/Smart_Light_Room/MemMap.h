/*
 * MemMap.h
 *
 * Created: 10/31/2021 1:34:15 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_


/*---------------------- Includes ----------------------*/


#define  F_CPU    8000000

#include <util/delay.h>

/*---------------------- Macros: DIO Section ----------------------*/
/*Port A*/
#define         DDRA         (*(volatile unsigned char *)0x3A) // For direction
#define         PORTA        (*(volatile unsigned char *)0x3B) // For volt high or low
#define         PINA         (*(volatile unsigned char *)0x39) // For reading to know, if high 1 or low 0
/*Port B*/
#define         DDRB         (*(volatile unsigned char *)0x37)
#define         PORTB        (*(volatile unsigned char *)0x38)
#define         PINB         (*(volatile unsigned char *)0x36)
/*Port C*/
#define         DDRC         (*(volatile unsigned char *)0x34)
#define         PORTC        (*(volatile unsigned char *)0x35)
#define         PINC         (*(volatile unsigned char *)0x33)
/*Port D*/
#define         DDRD         (*(volatile unsigned char *)0x31)
#define         PORTD        (*(volatile unsigned char *)0x32)
#define         PIND         (*(volatile unsigned char *)0x30)



/*ADC Registers*/
#define         ADMUX          (*(volatile unsigned char *)0x27)
#define         ADCSRA         (*(volatile unsigned char *)0x26)
#define         ADCH           (*(volatile unsigned char *)0x25)
#define         ADCL           (*(volatile unsigned char *)0x24)

#define         ADC            (*(volatile unsigned short *)0x24)


/*ADMUX register bits*/
#define         ADLAR           5

/*Voltage reference*/
#define         REFS0           6 
#define         REFS1           7

#define		    ADPS0		    0 // ADC prescaler#define			ADPS1			1 // ADC prescaler#define			ADPS2			2 // ADC prescaler#define			ADIE			3#define			ADIF			4#define			ADATE			5#define			ADSC			6 // ADC start conversion (takes 25 cycles on first time, and 13 each time)#define			ADEN			7 // ADC enable bit




#endif /* MEMMAP_H_ */