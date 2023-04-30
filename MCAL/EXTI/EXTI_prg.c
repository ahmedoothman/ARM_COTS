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

static void (*EXTI0_CallBack)(void) = NULL;
static void (*EXTI1_CallBack)(void) = NULL;
static void (*EXTI2_CallBack)(void) = NULL;
static void (*EXTI3_CallBack)(void) = NULL;
static void (*EXTI4_CallBack)(void) = NULL;
static void (*EXTI5_CallBack)(void) = NULL;
static void (*EXTI6_CallBack)(void) = NULL;
static void (*EXTI7_CallBack)(void) = NULL;
static void (*EXTI8_CallBack)(void) = NULL;
static void (*EXTI9_CallBack)(void) = NULL;
static void (*EXTI10_CallBack)(void) = NULL;
static void (*EXTI11_CallBack)(void) = NULL;
static void (*EXTI12_CallBack)(void) = NULL;
static void (*EXTI13_CallBack)(void) = NULL;
static void (*EXTI14_CallBack)(void) = NULL;
static void (*EXTI15_CallBack)(void) = NULL;

/*************************************************************************/
/*
Name       : EXTI_voidEnableEXTI
Input      : u8 Copy_u8Line, u8 Copy_u8Mode
Output     : void
Description: This function is used to enable the external interrupt and set the mode
*/
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
/*
Name       : EXTI_voidDisableEXTI
Input      : u8 Copy_u8Line
Output     : void
Description: This function is used to disable the external interrupt
*/
/*************************************************************************/
void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(EXTI->IMR, Copy_u8Line);
}
/*************************************************************************/
/*
Name       : EXTI_voidSwTrigger
Input      : u8 Copy_u8Line
Output     : void
Description: This function is used to trigger the external interrupt
*/
/*************************************************************************/
void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT(EXTI->SWIER, Copy_u8Line);
}
/*************************************************************************/
/*
Name       : EXTI_voidSetSignalLatch
Input      : u8 Copy_u8Line, u8 Copy_u8Mode
Output     : void
Description: This function is used to set the mode of the external interrupt
*/
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
/*
Name       : EXTI_voidSetCallBack
Input      : u8 Copy_u8Line, void (*Copy_ptr)(void)
Output     : void
Description: This function is used to set the callback function for the external interrupt
*/
/*************************************************************************/
void EXTI_voidSetCallBack(u8 Copy_u8Line, void (*Copy_ptr)(void))
{
    switch (Copy_u8Line)
    {
    case EXTI_LINE0:
        EXTI0_CallBack = Copy_ptr;
        break;
    case EXTI_LINE1:
        EXTI1_CallBack = Copy_ptr;
        break;
    case EXTI_LINE2:
        EXTI2_CallBack = Copy_ptr;
        break;
    case EXTI_LINE3:
        EXTI3_CallBack = Copy_ptr;
        break;
    case EXTI_LINE4:
        EXTI4_CallBack = Copy_ptr;
        break;
    case EXTI_LINE5:
        EXTI5_CallBack = Copy_ptr;
        break;
    case EXTI_LINE6:
        EXTI6_CallBack = Copy_ptr;
        break;
    case EXTI_LINE7:
        EXTI7_CallBack = Copy_ptr;
        break;
    case EXTI_LINE8:
        EXTI8_CallBack = Copy_ptr;
        break;
    case EXTI_LINE9:
        EXTI9_CallBack = Copy_ptr;
        break;
    case EXTI_LINE10:
        EXTI10_CallBack = Copy_ptr;
        break;
    case EXTI_LINE11:
        EXTI11_CallBack = Copy_ptr;
        break;
    case EXTI_LINE12:
        EXTI12_CallBack = Copy_ptr;
        break;
    case EXTI_LINE13:
        EXTI13_CallBack = Copy_ptr;
        break;
    case EXTI_LINE14:
        EXTI14_CallBack = Copy_ptr;
        break;
    case EXTI_LINE15:
        EXTI15_CallBack = Copy_ptr;
        break;
    }
}
