#ifndef BEEP_H
#define BEEP_H

#include "config.h"

#define BeepOn() GPIO_SetBits(GPIOG, GPIO_Pin_9)
#define BeepOff() GPIO_ResetBits(GPIOG, GPIO_Pin_9)

void BeepInit(void);
void BeepScan(s32 ms);
void Beep(s32 time);

#endif

