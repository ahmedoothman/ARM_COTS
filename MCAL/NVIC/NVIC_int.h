/*
 * NVIC_int.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Dell
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void NVIC_voidSetPriority(u8 Copy_u8IntNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif /* MCAL_NVIC_NVIC_INT_H_ */
