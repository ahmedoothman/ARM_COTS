/*
 * RCC_prg.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Ahmed Othman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_reg.h"
#include "RCC_int.h"
#include "RCC_pri.h"
#include "RCC_cfg.h"

/*************************************************************************/
/*
Name       : RCC_voidEnableClock
Input      : u8 Copy_u8BusId, u8 Copy_u8PerId
Output     : void
Description: This function is used to enable the peripheral clock
*/
/*************************************************************************/

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_u8PerId);
            break;
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}

/*************************************************************************/
/*
Name       : RCC_voidDisableClock
Input      : u8 Copy_u8BusId, u8 Copy_u8PerId
Output     : void
Description: This function is used to disable the peripheral clock
*/
/*************************************************************************/

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_u8PerId);
            break;
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}

void RCC_voidInitSysClock(void)
{
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
    RCC_CR = 0x00010000; /* Enable HSE with no bypass */
    RCC_CFGR = 0x00000001;
#elif RCC_CLOCK_TYPE == RCC_HSE_RC
    RCC_CR = 0x00050000; /* Enable HSE with bypass */
    RCC_CFGR = 0x00000001;
#elif RCC_CLOCK_TYPE == RCC_HSI
    RCC_CR = 0x00000081; /* Enable HSI + Trimming = 0 */
    RCC_CFGR = 0x00000000;
#elif RCC_CLOCK_TYPE == RCC_PLL
// We must put the config of PLL before enabling it in RCC_CR
#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
    RCC_CFGR = 0x00000002;
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
    RCC_CFGR = 0x00030002;
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
    RCC_CFGR = 0x00010002;
#endif
#if RCC_PLL_MUL_VAL == RCC_PLL_MUL_2
    RCC_CFGR |= 0x00000000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_3
    RCC_CFGR |= 0x00040000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_4
    RCC_CFGR |= 0x00080000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_5
    RCC_CFGR |= 0x000C0000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_6
    RCC_CFGR |= 0x00100000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_7
    RCC_CFGR |= 0x00140000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_8
    RCC_CFGR |= 0x00180000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_9
    RCC_CFGR |= 0x001C0000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_10
    RCC_CFGR |= 0x00200000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_11
    RCC_CFGR |= 0x00240000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_12
    RCC_CFGR |= 0x00280000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_13
    RCC_CFGR |= 0x002C0000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_14
    RCC_CFGR |= 0x00300000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_15
    RCC_CFGR |= 0x00340000;
#elif RCC_PLL_MUL_VAL == RCC_PLL_MUL_16
    RCC_CFGR |= 0x00380000;
#endif
    RCC_CR = 0x01000000; /* Enable PLL */
#else
#error("You Chose Wrong Clock Type")
#endif
}
