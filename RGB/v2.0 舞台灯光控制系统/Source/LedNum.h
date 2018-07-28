#ifndef LEDNUM_H
#define LEDNUM_H


#include "config.h"

#define LedNum0 PE_OUT(15)
#define LedNum1 PE_OUT(12)

#define LedNum0_On() {LedNum0 = 0;}
#define LedNum1_On() {LedNum1 = 0;}
#define LedNum0_Off() {LedNum0 = 1;}
#define LedNum1_Off() {LedNum1 = 1;}

void LedNumInit(void);
void LedNumScan(void);
void LedNumShowDec(u8 num);

#endif
