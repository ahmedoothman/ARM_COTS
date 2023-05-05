/*
 * AFIO_int.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Dell
 */

#ifndef MCAL_AFIO_AFIO_INT_H_
#define MCAL_AFIO_AFIO_INT_H_

#define AFIO_GPIOA 0b0000
#define AFIO_GPIOB 0b0001
#define AFIO_GPIOC 0b0010

#define AFIO_EXTI0 0b0000
#define AFIO_EXTI1 0b0001
#define AFIO_EXTI2 0b0010
#define AFIO_EXTI3 0b0011
#define AFIO_EXTI4 0b0100
#define AFIO_EXTI5 0b0101
#define AFIO_EXTI6 0b0110
#define AFIO_EXTI7 0b0111
#define AFIO_EXTI8 0b1000
#define AFIO_EXTI9 0b1001
#define AFIO_EXTI10 0b1010
#define AFIO_EXTI11 0b1011
#define AFIO_EXTI12 0b1100
#define AFIO_EXTI13 0b1101
#define AFIO_EXTI14 0b1110
#define AFIO_EXTI15 0b1111

void AFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap);

#endif /* MCAL_AFIO_AFIO_INT_H_ */
