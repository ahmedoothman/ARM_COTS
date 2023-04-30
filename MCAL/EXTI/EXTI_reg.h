/*
 * EXTI_reg.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Dell
 */

#ifndef MCAL_EXTI_EXTI_REG_H_
#define MCAL_EXTI_EXTI_REG_H_

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;

} EXTI_t;

#define EXTI ((volatile EXTI_t *)0x40010400)

#endif /* MCAL_EXTI_EXTI_REG_H_ */
