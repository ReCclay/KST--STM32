#include "beep.h"

s32 BeepTimer = 0;

void BeepInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOG, GPIO_Pin_9);
}

void BeepScan(s32 ms)
{
	if(BeepTimer > 0)
	{
		BeepTimer -= ms;
		if(BeepTimer <= 0)
		{
			BeepOff();
			BeepTimer = 0;
		}
	}
}

void Beep(s32 time)
{
	BeepTimer = time;
	
	if(BeepTimer == 0)
	{
		BeepOff();
	}
	else
	{
		BeepOn();
	}
}

