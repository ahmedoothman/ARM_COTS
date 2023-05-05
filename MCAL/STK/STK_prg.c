/*
 * STK_prg.c
 *
 *  Created on: May 4, 2023
 *      Author: Dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_cfg.h"
#include "STK_int.h"
#include "STK_pri.h"

#include "STK_reg.h"
// call back
static void (*STK_CallBack)(void);
static u8 STK_u8ModeOfInterval;
/*************************************************************************/
/* NAME: STK_voidInit */
/* Input: void */
/* Output: void */
/* Description: This function is used to initialize the SysTick timer */
/*************************************************************************/
void STK_voidInit(void)
{
    // Disable timer while configuring
    CLR_BIT(STK->CTRL, STK_ENABLE);

// set clock source
#if STK_CLKSOURCE == STK_CLKSOURCE_AHB_DIV_8
    CLR_BIT(STK->CTRL, STK_CLKSOURCE);
#elif STK_CLKSOURCE == STK_CLKSOURCE_AHB
    SET_BIT(STK->CTRL, STK_CLKSOURCE);
#else
#error "Wrong STK_CLKSOURCE configuration"
#endif
    // config interrupt
#if STK_TICKINT == STK_TICKINT_ENABLE
    SET_BIT(STK->CTRL, STK_TICKINT);
#elif STK_TICKINT == STK_TICKINT_DISABLE
    CLR_BIT(STK->CTRL, STK_TICKINT);
#endif
    // Enable timer
    SET_BIT(STK->CTRL, STK_ENABLE);
}
// set busy wait
void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    // load ticks
    STK->LOAD = Copy_u32Ticks;

    // clear value register
    STK->VAL = 0;

    // wait for flag
    while (GET_BIT(STK->CTRL, STK_COUNTFLAG) == 0)
        ;
}
/*************************************************************************/
/* NAME: STK_voidSetSingleInterval */
/* Input: u32 Copy_u32Ticks, void (*Copy_ptr)(void) */
/* Output: void */
/* Description: This function is used to set single interval */
/*************************************************************************/
void STK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    // Disable timer while configuring
    CLR_BIT(STK->CTRL, STK_ENABLE);

    // load ticks
    STK->LOAD = Copy_u32Ticks;

    // clear value register
    STK->VAL = 0;
    // set callback
    STK_CallBack = Copy_ptr;
    // Enable timer
    SET_BIT(STK->CTRL, STK_ENABLE);
    // Enable interrupt
    SET_BIT(STK->CTRL, STK_TICKINT);

    // set mode
    STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
}
/*************************************************************************/
/* NAME: STK_voidSetPeriodicInterval */
/* Input: u32 Copy_u32Ticks, void (*Copy_ptr)(void) */
/* Output: void */
/* Description: This function is used to set periodic interval */
/*************************************************************************/
void STK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    // Disable timer while configuring
    CLR_BIT(STK->CTRL, STK_ENABLE);

    // load ticks
    STK->LOAD = Copy_u32Ticks;

    // clear value register
    STK->VAL = 0;
    // set callback
    STK_CallBack = Copy_ptr;
    // Enable timer
    SET_BIT(STK->CTRL, STK_ENABLE);
    // Enable interrupt
    SET_BIT(STK->CTRL, STK_TICKINT);

    // set mode
    STK_u8ModeOfInterval = STK_PERIODIC_INTERVAL;
}
/*************************************************************************/
/* NAME: STK_voidStopTimer */
/* Input: void */
/* Output: void */
/* Description: This function is used to stop timer */
/*************************************************************************/
void STK_voidStopTimer(void)
{
    // Disable timer
    CLR_BIT(STK->CTRL, STK_ENABLE);
    // Disable interrupt
    CLR_BIT(STK->CTRL, STK_TICKINT);
    // clear value register
    STK->VAL = 0;
}
/*************************************************************************/
/* NAME: STK_u32GetElapsedTime */
/* Input: void */
/* Output: u32 */
/* Description: This function is used to get elapsed time */
/*************************************************************************/
u32 STK_u32GetElapsedTime(void)
{
    // Get the current value of the SysTick timer
    u32 CurrentValue = STK->VAL;

    // Get the Reload Value from the SysTick timer
    u32 ReloadValue = STK->LOAD;

    // Calculate the elapsed time based on the current value and Reload Value
    u32 ElapsedTime = ReloadValue - CurrentValue;

    return ElapsedTime;
}
/*************************************************************************/
/* NAME: STK_u32GetRemainingTime */
/* Input: void */
/* Output: u32 */
/* Description: This function is used to get remaining time */
/*************************************************************************/
u32 STK_u32GetRemainingTime(void)
{
    // Get the current value of the SysTick timer
    u32 CurrentValue = STK->VAL;

    // Get the Reload Value from the SysTick timer
    u32 ReloadValue = STK->LOAD;

    // Calculate the remaining time based on the current value and Reload Value
    u32 RemainingTime = CurrentValue + 1;

    // Check if the SysTick timer has already overflowed
    if (RemainingTime >= ReloadValue)
    {
        // If the SysTick timer has overflowed, the remaining time is the difference
        // between the Reload Value and the Current Value plus 1 (to account for the
        // extra tick that has already occurred)
        RemainingTime = ReloadValue - CurrentValue - 1;
    }

    return RemainingTime;
}
/*************************************************************************/
/* NAME: SysTick_Handler */
/* Input: void */
/* Output: void */
/* Description: This function is used to handle interrupt */
/*************************************************************************/
void SysTick_Handler(void)
{
    if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
    {
        // Disable timer
        CLR_BIT(STK->CTRL, STK_ENABLE);
        // Disable interrupt
        CLR_BIT(STK->CTRL, STK_TICKINT);
        // clear value register
        STK->VAL = 0;
        // clear load register
        STK->LOAD = 0;
    }

    STK_CallBack();
}
