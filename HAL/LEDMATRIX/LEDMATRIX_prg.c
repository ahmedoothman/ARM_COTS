/*
 * LEDMATRIX_prg.c
 *
 *  Created on: May 5, 2023
 *      Author: Dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEDMATRIX_int.h"
#include "LEDMATRIX_cfg.h"
#include "LEDMATRIX_pri.h"

#include "GPIO_int.h"
#include "STK_int.h"
/************************************************************************************/
/* Description: This function is used to initialize the LED Matrix                  */
/* Input      : void                                                                */
/* Output     : void                                                                */
/************************************************************************************/
void LEDMATRIX_voidInit(void)
{
    /* Set Columns pins as output */
    GPIO_voidSetPinDirection(LEDMATRIX_COL0_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL1_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL2_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL3_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL4_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL5_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL6_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_COL7_PIN, PUSH_PULL_2MHZ);

    /* Set Rows pins as output */
    GPIO_voidSetPinDirection(LEDMATRIX_ROW0_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW1_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW2_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW3_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW4_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW5_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW6_PIN, PUSH_PULL_2MHZ);
    GPIO_voidSetPinDirection(LEDMATRIX_ROW7_PIN, PUSH_PULL_2MHZ);
}
/************************************************************************************/
/* Description: This function is used to display the data                           */
/* Input      : void                                                                */
/* Output     : void                                                                */
/************************************************************************************/
void LEDMATRIX_voidDisplay(u8 *Copy_u8Data)
{
    while (1)
    {
        // Column 0
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[0]);
        GPIO_voidSetPinValue(LEDMATRIX_COL0_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 1
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[1]);
        GPIO_voidSetPinValue(LEDMATRIX_COL1_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 2
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[2]);
        GPIO_voidSetPinValue(LEDMATRIX_COL2_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 3
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[3]);
        GPIO_voidSetPinValue(LEDMATRIX_COL3_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 4
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[4]);
        GPIO_voidSetPinValue(LEDMATRIX_COL4_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 5
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[5]);
        GPIO_voidSetPinValue(LEDMATRIX_COL5_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 6
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[6]);
        GPIO_voidSetPinValue(LEDMATRIX_COL6_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);

        // Column 7
        LEDMATRIX_voidDisableAllCols();
        setRowValues(Copy_u8Data[7]);
        GPIO_voidSetPinValue(LEDMATRIX_COL7_PIN, GPIO_HIGH);
        STK_voidSetBusyWait(2500);
    }
}
//:::::::::::::::::::::::  NOT Sure :::::::::::::::::::::::
/************************************************************************************/
/* Description: This function is used to display the data                           */
/* Input      : void                                                                */
/* Output     : void                                                                */
/************************************************************************************/
void LEDMATRIX_voidDisplayAnimation(u8 *Copy_u8Data)
{
    u8 Local_u8Counter = 0;
    while (1)
    {
        for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
        {
            // Column 0
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter]);
            GPIO_voidSetPinValue(LEDMATRIX_COL0_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 1
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 1]);
            GPIO_voidSetPinValue(LEDMATRIX_COL1_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 2
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 2]);
            GPIO_voidSetPinValue(LEDMATRIX_COL2_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 3
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 3]);
            GPIO_voidSetPinValue(LEDMATRIX_COL3_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 4
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 4]);
            GPIO_voidSetPinValue(LEDMATRIX_COL4_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 5
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 5]);
            GPIO_voidSetPinValue(LEDMATRIX_COL5_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 6
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 6]);
            GPIO_voidSetPinValue(LEDMATRIX_COL6_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 7
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 7]);
            GPIO_voidSetPinValue(LEDMATRIX_COL7_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);
        }
    }
}

/************************************************************************************/
/* Description: This function is used to disable all rows of the LED Matrix          */
/* Input      : void                                                                 */
/* Output     : void                                                                 */
/************************************************************************************/
static void LEDMATRIX_voidDisableAllCols()
{

    GPIO_voidSetPinValue(LEDMATRIX_COL0_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL1_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL2_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL3_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL4_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL5_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL6_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_COL7_PIN, GPIO_LOW);
}

/************************************************************************************/
/* Description: This function is used to disable all rows of the LED Matrix          */
/* Input      : void                                                                 */
/* Output     : void                                                                 */
/************************************************************************************/
static void LEDMATRIX_voidDisableAllRows()
{

    GPIO_voidSetPinValue(LEDMATRIX_ROW0_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW1_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW2_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW3_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW4_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW5_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW6_PIN, GPIO_LOW);
    GPIO_voidSetPinValue(LEDMATRIX_ROW7_PIN, GPIO_LOW);
}

/************************************************************************************/
/* Description: This function is used show DATA ON ROW                              */
/* Input      : void                                                                */
/* Output     : void                                                                */
/************************************************************************************/
static void setRowValues(u8 Copy_u8Value)
{
    u8 Local_u8Bit;

    Local_u8Bit = GET_BIT(Copy_u8Value, 0);
    GPIO_voidSetPinValue(LEDMATRIX_ROW0_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 1);
    GPIO_voidSetPinValue(LEDMATRIX_ROW1_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 2);
    GPIO_voidSetPinValue(LEDMATRIX_ROW2_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 3);
    GPIO_voidSetPinValue(LEDMATRIX_ROW3_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 4);
    GPIO_voidSetPinValue(LEDMATRIX_ROW4_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 5);
    GPIO_voidSetPinValue(LEDMATRIX_ROW5_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 6);
    GPIO_voidSetPinValue(LEDMATRIX_ROW6_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 7);
    GPIO_voidSetPinValue(LEDMATRIX_ROW7_PIN, Local_u8Bit);
}

/************************************************************************************/
/* Description: This function is used to display the data                           */
/* Input      : void                                                                */
/* Output     : void                                                                */
/************************************************************************************/
void LEDMATRIX_voidDisplayAnimation(u8 *Copy_u8Data)
{
    u8 Local_u8Counter = 0;
    while (1)
    {
        for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
        {
            // Column 0
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter]);
            GPIO_voidSetPinValue(LEDMATRIX_COL0_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 1
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 1]);
            GPIO_voidSetPinValue(LEDMATRIX_COL1_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 2
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 2]);
            GPIO_voidSetPinValue(LEDMATRIX_COL2_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 3
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 3]);
            GPIO_voidSetPinValue(LEDMATRIX_COL3_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 4
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 4]);
            GPIO_voidSetPinValue(LEDMATRIX_COL4_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 5
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 5]);
            GPIO_voidSetPinValue(LEDMATRIX_COL5_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 6
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 6]);
            GPIO_voidSetPinValue(LEDMATRIX_COL6_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);

            // Column 7
            LEDMATRIX_voidDisableAllCols();
            setRowValues(Copy_u8Data[Local_u8Counter + 7]);
            GPIO_voidSetPinValue(LEDMATRIX_COL7_PIN, GPIO_HIGH);
            STK_voidSetBusyWait(2500);
        }
    }
}
