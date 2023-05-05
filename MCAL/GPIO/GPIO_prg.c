#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_reg.h"
#include "GPIO_cfg.h"

/*************************************************************************/
/* Name       : GPIO_voidSetPortDirection
/* Input      : u8 u8_PORT, u8 u8_PIN, u8 u8_MODE
/* Output     : void
/* Description: This function is used to set the direction of the port
/*************************************************************************/
/* NOT CORRECT */

// void GPIO_voidSetPortDirection(u8 u8_PORT, u8 u8_PIN, u8 u8_MODE)
// {
//   switch (u8_PORT)
//   {
//   case GPIOA:
//     if (u8_PIN < 8)
//     {
//       GPIOA_CRL &= ~(0b1111 << (u8_PIN * 4));

//       GPIOA_CRL |= (u8_MODE << (u8_PIN * 4));
//     }

//     else if (u8_PIN < 16)
//     {
//       GPIOA_CRH &= ~(0b1111 << ((u8_PIN - 8) * 4));

//       GPIOA_CRH |= (u8_MODE << ((u8_PIN - 8) * 4));
//     }
//     break;

//   default:
//     break;
//   }
// }

/*************************************************************************/
/* Name       : GPIO_voidSetPortValue
/* Input      : u8 u8_PORT, u8 u8_VALUE
/* Output     : void
/* Description: This function is used to set the value of the port
/*************************************************************************/
// void GPIO_voidSetPortValue(u8 u8_PORT, u8 u8_VALUE)
// {
//   switch (u8_PORT)
//   {
//   case GPIOA:
//     GPIOA_ODR = u8_VALUE;
//     break;
//   case GPIOB:
//     GPIOB_ODR = u8_VALUE;
//   case GPIOC:
//     GPIOC_ODR = u8_VALUE;
//     break;
//   }
// }

/*************************************************************************/
/* Name       : GPIO_voidSetPinDirection
/* Input      : u8 u8_PORT, u8 u8_PIN, u8 u8_MODE
/* Output     : void
/* Description: This function is used to set the value of the port
/*************************************************************************/
void GPIO_voidSetPinDirection(u8 u8_PORT, u8 u8_PIN, u8 u8_MODE)
{
  switch (u8_PORT)
  {
  case GPIOA:
    if (u8_PIN < 8)
    {
      GPIOA_CRL &= ~((0b1111) << (u8_PIN * 4));

      GPIOA_CRL |= ((u8_MODE) << (u8_PIN * 4));
    }

    else if (u8_PIN < 16)
    {
      u8_PIN = u8_PIN - 8;
      GPIOA_CRH &= ~((0b1111) << (u8_PIN * 4));

      GPIOA_CRH |= ((u8_MODE) << (u8_PIN * 4));
    }
    break;

  case GPIOB:
    if (u8_PIN < 8)
    {
      GPIOB_CRL &= ~((0b1111) << (u8_PIN * 4));

      GPIOB_CRL |= ((u8_MODE) << (u8_PIN * 4));
    }

    else if (u8_PIN < 16)
    {
      u8_PIN = u8_PIN - 8;
      GPIOB_CRH &= ~((0b1111) << (u8_PIN * 4));

      GPIOB_CRH |= ((u8_MODE) << (u8_PIN * 4));
    }
    break;
  case GPIOC:
    if (u8_PIN < 8)
    {
      GPIOC_CRL &= ~((0b1111) << (u8_PIN * 4));

      GPIOC_CRL |= ((u8_MODE) << (u8_PIN * 4));
    }

    else if (u8_PIN < 16)
    {
      u8_PIN = u8_PIN - 8;
      GPIOC_CRH &= ~((0b1111) << (u8_PIN * 4));

      GPIOC_CRH |= ((u8_MODE) << (u8_PIN * 4));
    }
  }
}

/*************************************************************************/
/* Name       : GPIO_voidSetPinValue
/* Input      : u8 u8_PORT, u8 u8_PIN, u8 u8_VALUE
/* Output     : void
/* Description: This function is used to set the value of the pin
/*************************************************************************/
void GPIO_voidSetPinValue(u8 u8_PORT, u8 u8_PIN, u8 u8_VALUE)
{
  switch (u8_PORT)
  {
  case GPIOA:
    WRT_BIT(GPIOA_ODR, u8_PIN, u8_VALUE);
    break;
  case GPIOB:
    WRT_BIT(GPIOB_ODR, u8_PIN, u8_VALUE);
    break;
  case GPIOC:
    WRT_BIT(GPIOC_ODR, u8_PIN, u8_VALUE);
    break;
  }
}

/*************************************************************************/
/* Name       : GPIO_voidTogglePinValue
/* Input      : u8 u8_PORT, u8 u8_PIN
/* Output     : void
/* Description: This function is used to get the value of the pin
/*************************************************************************/
void GPIO_voidTogglePinValue(u8 u8_u8Port, u8 u8_u8Pin)
{
  switch (u8_u8Port)
  {
  case GPIOA:
    TOG_BIT(GPIOA_ODR, u8_u8Pin);
    break;
  case GPIOB:
    TOG_BIT(GPIOB_ODR, u8_u8Pin);
    break;
  case GPIOC:
    TOG_BIT(GPIOC_ODR, u8_u8Pin);
    break;
  }
}

/*************************************************************************/
/* Name       : GPIO_u8GetPinValue
/* Input      : u8 u8_PORT, u8 u8_PIN
/* Output     : void
/* Description: This function is used to get the value of the pin
/*************************************************************************/
u8 GPIO_u8GetPinValue(u8 u8_PORT, u8 u8_PIN)
{
  u8 u8Result = 0;
  switch (u8_PORT)
  {
  case GPIOA:
    u8Result = GET_BIT(GPIOA_IDR, u8_PIN);
    break;
  case GPIOB:
    u8Result = GET_BIT(GPIOB_IDR, u8_PIN);
    break;
  }
  return u8Result;
}