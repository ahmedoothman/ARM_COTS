/*
 * NVIC_reg.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Dell
 */

#ifndef MCAL_NVIC_NVIC_REG_H_
#define MCAL_NVIC_NVIC_REG_H_

// Base Address 0xE000E100
#define NVIC_BASE_ADDRESS 0xE000E100

/* This is the enable of the NVIC */
// NVIC Registers
#define NVIC_ISER0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x000)) /* External Interrupts From 0 to 31 */
#define NVIC_ISER1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x004)) /* External Interrupts From 32 to 63 */
#define NVIC_ISER2 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x008)) /* External Interrupts From 64 to 95 */

#define NVIC_ICER0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x080)) /* External Interrupts From 0 to 31 */
#define NVIC_ICER1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x084)) /* External Interrupts From 32 to 63 */
#define NVIC_ICER2 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x088)) /* External Interrupts From 64 to 95 */

#define NVIC_ISPR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x100)) /* External Interrupts From 0 to 31 */
#define NVIC_ISPR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x104)) /* External Interrupts From 32 to 63 */
#define NVIC_ISPR2 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x108)) /* External Interrupts From 64 to 95 */

#define NVIC_ICPR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x180)) /* External Interrupts From 0 to 31 */
#define NVIC_ICPR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x184)) /* External Interrupts From 32 to 63 */
#define NVIC_ICPR2 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x188)) /* External Interrupts From 64 to 95 */

#define NVIC_IABR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x200)) /* External Interrupts From 0 to 31 */
#define NVIC_IABR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x204)) /* External Interrupts From 32 to 63 */
#define NVIC_IABR2 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x208)) /* External Interrupts From 64 to 95 */

#define NVIC_IPR0 *((volatile u8 *)(NVIC_BASE_ADDRESS + 0x300))

#endif /* MCAL_NVIC_NVIC_REG_H_ */
