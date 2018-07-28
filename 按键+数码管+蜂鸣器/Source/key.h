#ifndef KEY_H
#define KEY_H

#include "config.h"

#define KEY1 GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_4)
#define KEY2 GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_5)
#define KEY3 GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_6)
#define WKUP GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

void KeyInit(void);
void KeyScan(void);
void KeyDriver(void);


#endif

