#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_reg.h"
#include "GPIO_cfg.h"

void MGPIO_voidSetPortDirection(u8 u8_PORT, u8 u8_PIN, u8 u8_MODE)
{

  switch (u8_PORT)
  {
  case GPIOA:
    if (u8_PIN < 8)
    {
      GPIOA_CRL &= ~(0b1111 << (u8_PIN * 4));

      GPIOA_CRL |= (u8_MODE << (u8_PIN * 4));
    }

    else if (u8_PIN < 16)
    {
      GPIOA_CRH &= ~(0b1111 << (u8_PIN * 4));

      GPIOA_CRH |= (u8_MODE << (u8_PIN * 4));
    }
    break;

  case GPIOB:
    if (u8_PIN < 8)
    {
      GPIOB_CRL &= ~(0b1111 << (u8_PIN * 4));

      GPIOB_CRL |= (u8_MODE << (u8_PIN * 4));
    }

    else if (u8_PIN < 16)
    {
      GPIOB_CRH &= ~(0b1111 << (u8_PIN * 4));

      GPIOB_CRH |= (u8_MODE << (u8_PIN * 4));
    }
    break;
  }
}

void MGPIO_voidSetPinValue(u8 u8_PORT, u8 u8_PIN, u8 u8_VALUE)
{
  Switch(u8_PORT)
  {
  case GPIOA:
    if (u8_VALUE == 1)
    {
      SET_BIT(GPIOA_ODR, u8_PIN);
    }

    else if (u8_VALUE == 0)
    {
      CLR_BIT(GPIOA_ODR, u8_PIN);
    }

    break;
  case GPIOB:
    if (u8_VALUE == 1)
    {
      SET_BIT(GPIOB_ODR, u8_PIN);
    }

    else if (u8_VALUE == 0)
    {
      CLR_BIT(GPIOB_ODR, u8_PIN);
    }

    break;
  }
}
