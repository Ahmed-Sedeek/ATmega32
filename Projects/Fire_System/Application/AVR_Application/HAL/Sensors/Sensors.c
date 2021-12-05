/*
 * Sensors.c
 *
 * Created: 11/19/2021 3:20:40 PM
 *  Author: Ahmed Sedeek
 */ 
#include "Sensors.h"

#if LM35_CFG == CFG_ENABLE
u16 LM35_GetTemp(void)
{
	u16 temp;
	u16 volt = ADC_GetVolt(LM35_CH);
	temp = volt;
	return temp;
}
#endif

#if MCP9700_CFG == CFG_ENABLE
s16 MCP9700_GetTemp(void)
{
	s16 temp;
	u16 adcRead = ADC_GetVolt(MCP9700_CH);
	temp = ( ( ( adcRead - 510)*6)/35190)+1;
	return temp;
}
#endif

#if MPX4115_CFG == CFG_ENABLE
u16 MPX4115_GetPressure(void)
{
	u16 adcRead = ADC_Read(MPX4115_CH);
	u16 pressure = ( ( (u32)(adcRead - 55) * 1000) / 921) + 150;
	return pressure;
}
#endif

u8 POT_GetPerc(void)
{
	u16 adcRead = ADC_Read(POT_CH);
	u8 per = ((u32)100 * adcRead ) / 1023;
	return per;
}