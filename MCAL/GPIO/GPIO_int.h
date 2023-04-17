#ifndef _GPIO_INTERFACE_H

#define _GPIO_INTERFACE_H

#define GPIOA u8 0
#define GPIOB u8 1
#define GPIOC u8 2

// MODE 
#define GPIO_HIGH u8 1
#define GPIO_LOW  u8 0

//PINS
#define PIN0	 u8 0
#define PIN1	 u8 1
#define PIN2	 u8 2
#define PIN3	 u8 3
#define PIN4  	 u8 4
#define PIN5	 u8 5
#define PIN6	 u8 6
#define PIN7	 u8 7
#define PIN8	 u8 8
#define PIN9	 u8 9
#define PIN10	 u8 10
#define PIN11	 u8 11
#define PIN12	 u8 12
#define PIN13	 u8 13
#define PIN14	 u8 14
#define PIN15	 u8 15

// PUSH PULL OUTPUT
#define PUSH_PULL_10MHZ     0b0001
#define PUSH_PULL_2MHZ      0b0010
#define PUSH_PULL_50MHZ     0b0011

// OPEN DRAIN OUTPUT
#define OPEN_DRAIN_10MHZ     0b0101
#define OPEN_DRAIN_2MHZ      0b0110
#define OPEN_DRAIN_50MHZ     0b0111

// AF PUSH PULL OUTPUT
#define AF_PUSH_PULL_10MHZ      0b1001
#define AF_PUSH_PULL_2MHZ       0b1010
#define AF_PUSH_PULL_50MHZ      0b1011

// AF OPEN DRAIN OUTPUT
#define AF_OPEN_DRAIN_10MHZ      0b1101
#define AF_OPEN_DRAIN_2MHZ       0b1110
#define AF_OPEN_DRAIN_50MHZ      0b1111




void MGPIO_voidSetPortDirection(u8_u8Port,u8_u8Pin,u8_u8value);

void MGPIO_voidSetPinValue(u8_u8Port,u8_u8Pin,u8_u8value);

#endif 