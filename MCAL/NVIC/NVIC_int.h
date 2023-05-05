/*
 * NVIC_int.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Dell
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

// EXTI
#define NVIC_EXTI_LINE0 6
#define NVIC_EXTI_LINE1 7
#define NVIC_EXTI_LINE2 8
#define NVIC_EXTI_LINE3 9
#define NVIC_EXTI_LINE4 10
#define NVIC_EXTI_LINE5 23
#define NVIC_EXTI_LINE6 23
#define NVIC_EXTI_LINE7 23
#define NVIC_EXTI_LINE8 23
#define NVIC_EXTI_LINE9 23
#define NVIC_EXTI_LINE10 40
#define NVIC_EXTI_LINE11 40
#define NVIC_EXTI_LINE12 40
#define NVIC_EXTI_LINE13 40
#define NVIC_EXTI_LINE14 40
#define NVIC_EXTI_LINE15 40

// UART
#define NVIC_USART1 37
#define NVIC_USART2 38
#define NVIC_USART3 39
#define NVIC_UART4 52
#define NVIC_UART5 53

// SPI
#define NVIC_SPI1 35
#define NVIC_SPI2 36
#define NVIC_SPI3 51

// I2C
#define NVIC_I2C1_EV 31
#define NVIC_I2C1_ER 32
#define NVIC_I2C2_EV 33
#define NVIC_I2C2_ER 34

// DMA
#define NVIC_DMA1_CHANNEL1 11
#define NVIC_DMA1_CHANNEL2 12
#define NVIC_DMA1_CHANNEL3 13
#define NVIC_DMA1_CHANNEL4 14
#define NVIC_DMA1_CHANNEL5 15
#define NVIC_DMA1_CHANNEL6 16
#define NVIC_DMA1_CHANNEL7 17

#define NVIC_DMA2_CHANNEL1 56
#define NVIC_DMA2_CHANNEL2 57
#define NVIC_DMA2_CHANNEL3 58
#define NVIC_DMA2_CHANNEL4 59
#define NVIC_DMA2_CHANNEL5 60

// ADC
#define NVIC_ADC1_2 18
#define NVIC_ADC3 47

// TIMERS
#define NVIC_TIM1_BRK_TIM9 24
#define NVIC_TIM1_UP_TIM10 25
#define NVIC_TIM1_TRG_COM_TIM11 26
#define NVIC_TIM1_CC 27

#define NVIC_TIM2 28
#define NVIC_TIM3 29
#define NVIC_TIM4 30

#define NVIC_TIM5 50
#define NVIC_TIM6_DAC 54
#define NVIC_TIM7 55

#define NVIC_TIM8_BRK_TIM12 43
#define NVIC_TIM8_UP_TIM13 44
#define NVIC_TIM8_TRG_COM_TIM14 45
#define NVIC_TIM8_CC 46

// RTC
#define NVIC_RTC_WKUP 20
#define NVIC_RTC_ALARM 41
#define NVIC_RTC_TAMP_STAMP 2

// USB
#define NVIC_USB_HP 19
#define NVIC_USB_LP 20
#define NVIC_USB_WKUP 42

// CAN
#define NVIC_CAN1_TX 32
#define NVIC_CAN1_RX0 33
#define NVIC_CAN1_RX1 34
#define NVIC_CAN1_SCE 35

#define NVIC_CAN2_TX 63
#define NVIC_CAN2_RX0 64
#define NVIC_CAN2_RX1 65
#define NVIC_CAN2_SCE 66

// ETH
#define NVIC_ETH 61
#define NVIC_ETH_WKUP 62

void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void NVIC_voidSetPriority(u8 Copy_u8IntNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif /* MCAL_NVIC_NVIC_INT_H_ */
