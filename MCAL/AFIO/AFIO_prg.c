/*
 * AFIO_prg.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_int.h"
#include "AFIO_cfg.h"
#include "AFIO_pri.h"
#include "AFIO_reg.h"

/*************************************************************************/
/* Name       : AFIO_voidSetEXTIConfiguration
/* Input      : u8 Copy_u8Line, u8 Copy_u8PortMap
/* Output     : void
/* Description: This function is used to set the EXTI configuration
/*************************************************************************/
void AFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
    u8 Local_u8RegIndex = 0;

    if (Copy_u8Line <= 3)
    {
        Local_u8RegIndex = 0;
    }
    else if (Copy_u8Line <= 7)
    {
        Local_u8RegIndex = 1;
        Copy_u8Line -= 4;
    }
    else if (Copy_u8Line <= 11)
    {
        Local_u8RegIndex = 2;
        Copy_u8Line -= 8;
    }
    else if (Copy_u8Line <= 15)
    {
        Local_u8RegIndex = 3;
        Copy_u8Line -= 12;
    }
    else
    {
        /* Return Error */
    }

    AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO->EXTICR[Local_u8RegIndex] |= ((Copy_u8PortMap) << (Copy_u8Line * 4));
}