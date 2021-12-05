/*
 * Utils.h
 *
 * Created: 10/31/2021 1:39:35 PM
 *  Author: Ahmed Sedeek
 */ 


#ifndef UTILS_H_
#define UTILS_H_


/*-------------------- Macro declarations --------------------*/
#define  PIN_MASK_VAL	      1U
#define  PORT_MASK_VALUE      0XFF

/*---------------------- Function Macros ----------------------*/
/*Pins Utils*/
#define  SET_BIT(REGISTER, BIT_POS)              (REGISTER |= (PIN_MASK_VAL<<BIT_POS))
#define  CLEAR_BIT(REGISTER, BIT_POS)            (REGISTER &= ~(PIN_MASK_VAL<<BIT_POS))
#define  TOGGLE_BIT(REGISTER, BIT_POS)           (REGISTER ^= (PIN_MASK_VAL<<BIT_POS))
#define  READ_BIT(REGISTER, BIT_POS)             ((REGISTER >> BIT_POS) & PIN_MASK_VAL)
#define  WRITE_BIT(REGISTER, BIT_POS, VALUE)     ((REGISTER &= ~(PIN_MASK_VAL<<BIT_POS))|(VALUE << BIT_POS))

/*Port Utils*/
#define SET_PORT(REGISTER)                 (REGISTER |= PORT_MASK_VALUE)
#define CLEAR_PORT(REGISTER)               (REGISTER &= ~PORT_MASK_VALUE)
#define TOGGLE_PORT(REGISTER)              (REGISTER ^= PORT_MASK_VALUE)
#define READ_PORT(REGISTER)                (REGISTER &= PORT_MASK_VALUE)
//#define WRITE_PORT(REGISTER, VALUE)        ((REGISTER &= ~PORT_MASK_VALUE)|VALUE)



#endif /* UTILS_H_ */