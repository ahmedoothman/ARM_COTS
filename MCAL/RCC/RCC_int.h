/*
 * RCC_int.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Ahmed Othman
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

enum RCC_BusId
{
    RCC_AHB,
    RCC_APB1,
    RCC_APB2
};

/****************************************/
/* APB2 */
/****************************************/
// AFIO
#define RCC_AFIO 0

// GPIOA
#define RCC_GPIOA 2
#define RCC_GPIOB 3
#define RCC_GPIOC 4

// ADC
#define RCC_ADC1 9
#define RCC_ADC2 10
#define RCC_ADC3 15

// TIMER
#define RCC_TIM1 11
#define RCC_TIM8 13
// SPI
#define RCC_SPI1 12

// USART
#define RCC_USART1 14

/****************************************/
/* APB1 */
/****************************************/
// TIMER
#define RCC_TIM2 0
#define RCC_TIM3 1
#define RCC_TIM4 2
#define RCC_TIM5 3
#define RCC_TIM6 4
#define RCC_TIM7 5
#define RCC_TIM12 6
#define RCC_TIM13 7
#define RCC_TIM14 8

// WWDG
#define RCC_WWDG 11
// SPI
#define RCC_SPI2 14
#define RCC_SPI3 15

// USART
#define RCC_USART2 17
#define RCC_USART3 18
#define RCC_USART4 19
#define RCC_USART5 20

// I2C
#define RCC_I2C1 21
#define RCC_I2C2 22

// USB
#define RCC_USB 23

// CAN
#define RCC_CAN 25

// BKP
#define RCC_BKP 27

// PWR
#define RCC_PWR 28

// DAC
#define RCC_DAC 29

/****************************************/
/* AHB */
/****************************************/
// DMA
#define RCC_DMA1 0
#define RCC_DMA2 1

// SRAM
#define RCC_SRAM 2

// FLITF
#define RCC_FLITF 4

// CRC
#define RCC_CRC 6

// FSMC
#define RCC_FSMC 8

// SDIO
#define RCC_SDIO 10
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidInitSysClock(void);
#endif /* MCAL_RCC_RCC_INT_H_ */
