/*
 * NVIC_prg.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_int.h"
#include "NVIC_reg.h"
#include "NVIC_cfg.h"
#include "NVIC_pri.h"

/*************************************************************************/
/*
Name       : NVIC_voidEnableInterrupt
Input      : u8 Copy_u8IntNumber
Output     : void
Description: This function is used to enable the interrupt
*/
/*************************************************************************/
void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
    {
        NVIC_ISER0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        /* 59 bcz that is the end in the vector table */
        Copy_u8IntNumber -= 32;
        NVIC_ISER1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}
/*************************************************************************/
/*
Name       : NVIC_voidDisableInterrupt
Input      : u8 Copy_u8IntNumber
Output     : void
Description: This function is used to disable the interrupt
*/
/*************************************************************************/
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
    {
        NVIC_ICER0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        /* 59 bcz that is the end in the vector table */
        Copy_u8IntNumber -= 32;
        NVIC_ICER1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

/*************************************************************************/
/*
Name       : NVIC_voidSetPendingFlag
Input      : u8 Copy_u8IntNumber
Output     : void
Description: This function is used to set the pending flag
*/
/*************************************************************************/

void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{

    if (Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
    {
        NVIC_ISPR0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        /* 59 bcz that is the end in the vector table */
        Copy_u8IntNumber -= 32;
        NVIC_ISPR1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

/*************************************************************************/
/*
Name       : NVIC_voidClearPendingFlag
Input      : u8 Copy_u8IntNumber
Output     : void
Description: This function is used to clear the pending flag
*/
/*************************************************************************/
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{

    if (Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
    {
        NVIC_ICPR0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        /* 59 bcz that is the end in the vector table */
        Copy_u8IntNumber -= 32;
        NVIC_ICPR1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}
/*************************************************************************/
/*
Name       : NVIC_u8GetActiveFlag
Input      : u8 Copy_u8IntNumber
Output     : u8 Local_u8Result
Description: This function is used to get the active flag
*/
/*************************************************************************/
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
    u8 Local_u8Result;
    if (Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        /* 59 bcz that is the end in the vector table */
        Copy_u8IntNumber -= 32;
        Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
    return Local_u8Result;
}
/*************************************************************************/
/*
Name       : NVIC_voidSetPriority
Input      : u8 Copy_u8IntNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority
Output     : void
Description: This function is used to set the priority
*/
/*************************************************************************/
void NVIC_voidSetPriority(u8 Copy_u8IntNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
    u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((NVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300) / 256));
    /* Core Peripheral */
    if (Copy_u8IntNumber < 60)
    {
        NVIC_IPR[Copy_u8IntNumber] = Local_u8Priority << 4;
    }
    /* External Peripheral */
    else
    {
        /* Return Error */
    }

    /* Set Priority Distribution */
    SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}