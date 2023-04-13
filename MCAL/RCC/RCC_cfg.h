/*
 * RCC_cfg.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Ahmed Othman
 */

#ifndef MCAL_RCC_RCC_CFG_H_
#define MCAL_RCC_RCC_CFG_H_

/* Clock Options:
                RCC_HSE_CRYSTAL
                  RCC_HSE_RC
                  RCC_HSI
                  RCC_PLL*/
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL

/* PLL Options:
                RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
                RCC_PLL_IN_HSE */
#define RCC_PLL_INPUT RCC_PLL_IN_HSE_DIV_2

/*
    * PLL MUL Options:
                    RCC_PLL_MUL_2
                    RCC_PLL_MUL_3
                    RCC_PLL_MUL_4
                    RCC_PLL_MUL_5
                    RCC_PLL_MUL_6
                    RCC_PLL_MUL_7
                    RCC_PLL_MUL_8
                    RCC_PLL_MUL_9
                    RCC_PLL_MUL_10
                    RCC_PLL_MUL_11
                    RCC_PLL_MUL_12
                    RCC_PLL_MUL_13
                    RCC_PLL_MUL_14
                    RCC_PLL_MUL_15
                    RCC_PLL_MUL_16
    */
/* Note: Select value only if you have PLL as input clock source */
#define RCC_PLL_MUL_VAL RCC_PLL_MUL_2

#endif /* MCAL_RCC_RCC_CFG_H_ */
