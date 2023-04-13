/*
 * RCC_reg.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Ahmed Othman
 */

#ifndef MCAL_RCC_RCC_REG_H_
#define MCAL_RCC_RCC_REG_H_

// RCC Base Address 0x4002 1000
/* RC CR */
#define RCC_CR *((volatile u32*)0x40021000)
/* RCC CFGR */
#define RCC_CFGR *((volatile u32*)0x40021004)
/* RCC CIR */
#define RCC_CIR *((volatile u32*)0x40021008)
/* RCC APB2RSTR */
#define RCC_APB2RSTR *((volatile u32*)0x4002100C)
/* RCC APB1RSTR */
#define RCC_APB1RSTR *((volatile u32*)0x40021010)
/* RCC AHBENR */
#define RCC_AHBENR *((volatile u32*)0x40021014)
/* RCC APB2ENR */
#define RCC_APB2ENR *((volatile u32*)0x40021018)
/* RCC APB1ENR */
#define RCC_APB1ENR *((volatile u32*)0x4002101C)
/* RCC BDCR */
#define RCC_BDCR *((volatile u32*)0x40021020)
/* RCC CSR */
#define RCC_CSR *((volatile u32*)0x40021024)
#endif /* MCAL_RCC_RCC_REG_H_ */
