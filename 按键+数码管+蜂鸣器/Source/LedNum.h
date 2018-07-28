#ifndef LEDNUM_H
#define LEDNUM_H

#include "config.h"

#define LedNum0_On() GPIO_ResetBits(GPIOE, GPIO_Pin_15)
#define LedNum0_Off() GPIO_SetBits(GPIOE, GPIO_Pin_15)
#define LedNum1_On() GPIO_ResetBits(GPIOE, GPIO_Pin_12)
#define LedNum1_Off() GPIO_SetBits(GPIOE, GPIO_Pin_12)

void LedNumInit(void);
void LedNumScan(void);
void LedNumShowDec(u8 num);

#endif
