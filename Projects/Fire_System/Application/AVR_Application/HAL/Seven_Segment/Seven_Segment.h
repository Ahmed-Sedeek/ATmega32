/*
 * Seven_Segment.h
 *
 * Created: 11/1/2021 6:38:46 AM
 *  Author: Ahmed Sedeek
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

void Segment_Display(u8 number);
void Segment_TwoDisplays(u8 number);

void Segment_TwoDisplays_BCD(u8 number);
void Segment_Display_BCD(u8 number);

#endif /* SEVEN_SEGMENT_H_ */