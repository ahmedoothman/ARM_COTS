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
        default:
            /* Return Error */
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}