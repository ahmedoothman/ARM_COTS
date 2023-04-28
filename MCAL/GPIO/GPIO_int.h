#ifndef _GPIO_INT_H

#define _GPIO_INT_H

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

// MODE
#define GPIO_HIGH 1
#define GPIO_LOW 0

// PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

// PUSH PULL OUTPUT
#define PUSH_PULL_10MHZ 0b0001
#define PUSH_PULL_2MHZ 0b0010
#define PUSH_PULL_50MHZ 0b0011

// OPEN DRAIN OUTPUT
#define OPEN_DRAIN_10MHZ 0b0101
#define OPEN_DRAIN_2MHZ 0b0110
#define OPEN_DRAIN_50MHZ 0b0111

// AF PUSH PULL OUTPUT
#define AF_PUSH_PULL_10MHZ 0b1001
#define AF_PUSH_PULL_2MHZ 0b1010
#define AF_PUSH_PULL_50MHZ 0b1011

// AF OPEN DRAIN OUTPUT
#define AF_OPEN_DRAIN_10MHZ 0b1101
#define AF_OPEN_DRAIN_2MHZ 0b1110
#define AF_OPEN_DRAIN_50MHZ 0b1111

// INPUT
#define INPUT_ANALOG 0b0000
#define INPUT_FLOATING 0b0100
#define INPUT_PULL_UP_DOWN 0b1000

// void MGPIO_voidSetPortDirection(u8 u8_u8Port, u8 u8_u8Pin, u8 u8_u8value);
// void MGPIO_voidSetPortValue(u8 u8_u8Port, u8 u8_u8value);

void MGPIO_voidSetPinDirection(u8 u8_PORT, u8 u8_PIN, u8 u8_MODE);
void MGPIO_voidSetPinValue(u8 u8_PORT, u8 u8_PIN, u8 u8_VALUE);
void MGPIO_voidTogglePinValue(u8 u8_u8Port, u8 u8_u8Pin);
u8 MGPIO_u8GetPinValue(u8 u8_PORT, u8 u8_PIN);

#endif