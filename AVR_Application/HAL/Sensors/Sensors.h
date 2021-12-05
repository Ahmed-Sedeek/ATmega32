/*
 * Sensors.h
 *
 * Created: 11/19/2021 3:20:56 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"
#include "StdTypes.h"

/*Selecting the sensor*/
#define  LM35_CFG      CFG_ENABLE   // LM35 Temperature sensor
#define  MCP9700_CFG   CFG_DISABLE  // MCP9700 Temperature sensor
#define  MPX4115_CFG   CFG_ENABLE   // MPX4115 Pressure sensor

#if LM35_CFG == CFG_ENABLE      // Temperature sensor

#define LM35_CH		   CH_7

#endif // LM35

#if MCP9700_CFG == CFG_ENABLE // Temperature sensor

#define MCP9700_CH		CH_7

#endif // MCP9700

#if MPX4115_CFG == CFG_ENABLE // Pressure sensor

#define MPX4115_CH		CH_0

#endif // MPX4115


#define POT_CH		CH_0

u16 LM35_GetTemp(void);        // Temperature sensor
s16 MCP9700_GetTemp(void);     // Temperature sensor
u16 MPX4115_GetPressure(void); // Pressure sensor

u8 POT_GetPerc(void);


#endif /* SENSORS_H_ */