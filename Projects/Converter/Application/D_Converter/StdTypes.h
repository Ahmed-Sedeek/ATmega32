/*
 * StdTypes.h
 *
 * Created: 10/31/2021 1:47:20 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

/*------------ Macro Section ------------*/
#define RET_OK         (Std_ReturnType)0x01
#define RET_NOT_OK     (Std_ReturnType)0x00

#define  STD_HIGH  1U
#define  STD_LOW   0U

#define  STD_DIRECTION_OUTPUT   0xFFU
#define  STD_DIRECTION_INPUT    0x00U

#define  STD_TRUE    1U
#define  STD_FALSE   0U

#define ZERO_INIT	 0

#define NULL_PTR	 ((void*)0)


typedef unsigned char	u8;
typedef signed char	    s8;

typedef unsigned int	u16;
typedef signed int	    s16;

typedef unsigned long	u32;
typedef signed long	s32;

typedef   u8  Std_ReturnType;




#endif /* STDTYPES_H_ */