/*
 * EXTI_int.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Dell
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define EXTI_LINE0 0
#define EXTI_LINE1 1
#define EXTI_LINE2 2
#define EXTI_LINE3 3
#define EXTI_LINE4 4
#define EXTI_LINE5 5
#define EXTI_LINE6 6
#define EXTI_LINE7 7
#define EXTI_LINE8 8
#define EXTI_LINE9 9
#define EXTI_LINE10 10
#define EXTI_LINE11 11
#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15

#define EXTI_RISING_EDGE 0
#define EXTI_FALLING_EDGE 1
#define EXTI_ON_CHANGE 2

void EXTI_voidInit();
void EXTI_voidEnableEXTI(u8 Copy_u8Line, u8 Copy_u8Mode);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);

void EXTI_voidSetCallBack(u8 Copy_u8Line, void (*ptr)(void));
#endif /* MCAL_EXTI_EXTI_INT_H_ */
