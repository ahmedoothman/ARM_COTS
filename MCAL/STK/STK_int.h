/*
 * STK_int.h
 *
 *  Created on: May 4, 2023
 *      Author: Dell
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_

//  init
void STK_voidInit(void);
// set busy wait
void STK_voidSetBusyWait(u32 Copy_u32Ticks);
// set single wait
void STK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
// set periodic wait
void STK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
// stop timer
void STK_voidStopTimer(void);
// get elapsed time
u32 STK_u32GetElapsedTime(void);
// get remaining time
u32 STK_u32GetRemainingTime(void);

#endif /* MCAL_STK_STK_INT_H_ */
