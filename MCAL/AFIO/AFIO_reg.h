/*
 * AFIO_reg.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Dell
 */

#ifndef MCAL_AFIO_AFIO_REG_H_
#define MCAL_AFIO_AFIO_REG_H_


typedef struct
{
    volatile u32 EVCR;
    volatile u32 MAPR;
    volatile u32 EXTICR[4];
    volatile u32 MAPR2;

} AFIO_t;

#define AFIO ((volatile AFIO_t *)0x40010000)

#endif /* MCAL_AFIO_AFIO_REG_H_ */
