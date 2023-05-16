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
    CLR_BIT(STK->CTRL, ENABLE_PIN);

// set clock source
#if STK_CLKSOURCE == STK_CLKSOURCE_AHB_DIV_8
    CLR_BIT(STK->CTRL, CLKSOURCE_PIN);
#elif STK_CLKSOURCE == STK_CLKSOURCE_AHB
    SET_BIT(STK->CTRL, CLKSOURCE_PIN);
#else
#error "Wrong STK_CLKSOURCE configuration"
#endif
}
/*************************************************************************/
/* NAME:  STK_voidSetBusyWait */
/* Input: u32 Copy_u32Ticks */
/* Output: void */
/* Description: This function set busywait */
/*************************************************************************/
void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    // disable timer while configuring
    CLR_BIT(STK->CTRL, ENABLE_PIN);
    // disable interrupt
    CLR_BIT(STK->CTRL, TICKINT_PIN);
    // clear value register
    STK->VAL = 0;
    // load ticks
    STK->LOAD = Copy_u32Ticks;

    // Enable timer
    SET_BIT(STK->CTRL, ENABLE_PIN);
    // wait for flag
    while (READ_BIT(STK->CTRL, COUNTFLAG_PIN) == 0)
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
    CLR_BIT(STK->CTRL, ENABLE_PIN);

    // clear value register
    STK->VAL = 0;

    // load ticks
    STK->LOAD = Copy_u32Ticks;

    // set callback
    STK_CallBack = Copy_ptr;
    // Enable timer
    SET_BIT(STK->CTRL, ENABLE_PIN);
    // enable interrupt
    SET_BIT(STK->CTRL, TICKINT_PIN);
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
    CLR_BIT(STK->CTRL, ENABLE_PIN);

    // clear value register
    STK->VAL = 0;

    // load ticks
    STK->LOAD = Copy_u32Ticks;

    // set callback
    STK_CallBack = Copy_ptr;
    // Enable timer
    SET_BIT(STK->CTRL, ENABLE_PIN);
    // Enable interrupt
    SET_BIT(STK->CTRL, TICKINT_PIN);

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
    CLR_BIT(STK->CTRL, ENABLE_PIN);
    // Disable interrupt
    CLR_BIT(STK->CTRL, TICKINT_PIN);
    // clear value register
    STK->VAL = 0;
    // clear load register
    STK->LOAD = 0;
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
    STK_CallBack();
    if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
    {
        STK_voidStopTimer();
    }
    // clear value register
    // STK->VAL = 0;
    // clear flag
    // CLR_BIT(STK->CTRL, COUNTFLAG_PIN);
    SET_BIT(STK->CTRL, COUNTFLAG_PIN);
}
