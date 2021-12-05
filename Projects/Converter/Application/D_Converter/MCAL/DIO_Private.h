/*
 * DIO_Private.h
 *
 * Created: 10/31/2021 1:51:08 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);
extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS]; // Pins statuses




#endif /* DIO_PRIVATE_H_ */