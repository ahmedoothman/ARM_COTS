/*
 * EXTI_prg.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "EXTI_pri.h"
#include "EXTI_reg.h"

// call back
static void (*EXTI_CallBack[16])(void);

/*************************************************************************/
/* Name       : EXTI_voidEnableEXTI
/* Input      : u8 Copy_u8Line, u8 Copy_u8Mode
/* Output     : void
/* Description: This function is used to enable the external interrupt and set the mode
/*************************************************************************/

void EXTI_voidEnableEXTI(u8 Copy_u8Line, u8 Copy_u8Mode)
{
    // enable the external interrupt LINE
    SET_BIT(EXTI->IMR, Copy_u8Line);
    // set the mode
    switch (Copy_u8Mode)
    {
    case EXTI_RISING_EDGE:
        SET_BIT(EXTI->RTSR, Copy_u8Line);
        break;
    case EXTI_FALLING_EDGE:
        SET_BIT(EXTI->FTSR, Copy_u8Line);
        break;
    case EXTI_ON_CHANGE:
        SET_BIT(EXTI->RTSR, Copy_u8Line);
        SET_BIT(EXTI->FTSR, Copy_u8Line);
        break;
    }
}
/*************************************************************************/
/* Name       : EXTI_voidDisableEXTI
/* Input      : u8 Copy_u8Line
/* Output     : void
/* Description: This function is used to disable the external interrupt
/*************************************************************************/
void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(EXTI->IMR, Copy_u8Line);
}
/*************************************************************************/
/* Name       : EXTI_voidSwTrigger
/* Input      : u8 Copy_u8Line
/* Output     : void
/* Description: This function is used to trigger the external interrupt
/*************************************************************************/
void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT(EXTI->SWIER, Copy_u8Line);
}
/*************************************************************************/
/* Name       : EXTI_voidSetSignalLatch
/* Input      : u8 Copy_u8Line, u8 Copy_u8Mode
/* Output     : void
/* Description: This function is used to set the mode of the external interrupt
/*************************************************************************/
void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case EXTI_RISING_EDGE:
        SET_BIT(EXTI->RTSR, Copy_u8Line);
        break;
    case EXTI_FALLING_EDGE:
        SET_BIT(EXTI->FTSR, Copy_u8Line);
        break;
    case EXTI_ON_CHANGE:
        SET_BIT(EXTI->RTSR, Copy_u8Line);
        SET_BIT(EXTI->FTSR, Copy_u8Line);
        break;
    }
}

/*************************************************************************/
/* Name       : EXTI_voidSetCallBack
/* Input      : void (*ptr)(void)
/* Output     : void
/* Description: This function is used to set the call back function
/*************************************************************************/
void EXTI_voidSetCallBack(u8 Copy_u8Line, void (*ptr)(void))
{
    EXTI_CallBack[Copy_u8Line] = ptr;
}

/*************************************************************************/
/* Name       : EXTI0_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI0
/*************************************************************************/
void EXTI0_IRQHandler(void)
{
    EXTI_CallBack[0]();
    // clear pending bit
    SET_BIT(EXTI->PR, 0);
}
/*************************************************************************/
/* Name       : EXTI1_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI1
/*************************************************************************/
void EXTI1_IRQHandler(void)
{
    EXTI_CallBack[1]();
    // clear pending bit
    SET_BIT(EXTI->PR, 1);
}
/*************************************************************************/
/* Name       : EXTI2_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI2
/*************************************************************************/
void EXTI2_IRQHandler(void)
{
    EXTI_CallBack[2]();
    // clear pending bit
    SET_BIT(EXTI->PR, 2);
}
/*************************************************************************/
/* Name       : EXTI3_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI3
/*************************************************************************/
void EXTI3_IRQHandler(void)
{
    EXTI_CallBack[3]();
    // clear pending bit
    SET_BIT(EXTI->PR, 3);
}
/*************************************************************************/
/* Name       : EXTI4_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI4
/*************************************************************************/
void EXTI4_IRQHandler(void)
{
    EXTI_CallBack[4]();
    // clear pending bit
    SET_BIT(EXTI->PR, 4);
}
/*************************************************************************/
/* Name       : EXTI9_5_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI5:9
/*************************************************************************/
void EXTI9_5_IRQHandler(void)
{
    if (READ_BIT(EXTI->PR, 5))
    {
        EXTI_CallBack[5]();
        // clear pending bit
        SET_BIT(EXTI->PR, 5);
    }
    else if (READ_BIT(EXTI->PR, 6))
    {
        EXTI_CallBack[6]();
        // clear pending bit
        SET_BIT(EXTI->PR, 6);
    }
    else if (READ_BIT(EXTI->PR, 7))
    {
        EXTI_CallBack[7]();
        // clear pending bit
        SET_BIT(EXTI->PR, 7);
    }
    else if (READ_BIT(EXTI->PR, 8))
    {
        EXTI_CallBack[8]();
        // clear pending bit
        SET_BIT(EXTI->PR, 8);
    }
    else if (READ_BIT(EXTI->PR, 9))
    {
        EXTI_CallBack[9]();
        // clear pending bit
        SET_BIT(EXTI->PR, 9);
    }
}
/*************************************************************************/
/* Name       : EXTI15_10_IRQHandler
/* Input      : void
/* Output     : void
/* Description: This function is the interrupt handler of EXTI10:15
/*************************************************************************/

void EXTI15_10_IRQHandler(void)
{
    if (READ_BIT(EXTI->PR, 10))
    {
        EXTI_CallBack[10]();
        // clear pending bit
        SET_BIT(EXTI->PR, 10);
    }
    else if (READ_BIT(EXTI->PR, 11))
    {
        EXTI_CallBack[11]();
        // clear pending bit
        SET_BIT(EXTI->PR, 11);
    }
    else if (READ_BIT(EXTI->PR, 12))
    {
        EXTI_CallBack[12]();
        // clear pending bit
        SET_BIT(EXTI->PR, 12);
    }
    else if (READ_BIT(EXTI->PR, 13))
    {
        EXTI_CallBack[13]();
        // clear pending bit
        SET_BIT(EXTI->PR, 13);
    }
    else if (READ_BIT(EXTI->PR, 14))
    {
        EXTI_CallBack[14]();
        // clear pending bit
        SET_BIT(EXTI->PR, 14);
    }
    else if (READ_BIT(EXTI->PR, 15))
    {
        EXTI_CallBack[15]();
        // clear pending bit
        SET_BIT(EXTI->PR, 15);
    }
}
