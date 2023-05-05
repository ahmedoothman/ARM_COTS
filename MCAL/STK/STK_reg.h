/*
 * STK_reg.h
 *
 *  Created on: May 4, 2023
 *      Author: Dell
 */

#ifndef MCAL_STK_STK_REG_H_
#define MCAL_STK_STK_REG_H_

#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
} STK_t;

#define STK ((volatile STK_t *)STK_BASE_ADDRESS)

#endif /* MCAL_STK_STK_REG_H_ */
