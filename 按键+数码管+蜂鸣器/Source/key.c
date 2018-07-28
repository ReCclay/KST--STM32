#include "key.h"

u8 KeySta[4] = {1, 1, 1, 1};
extern void KeyAction(int code);

void KeyInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

void KeyScan(void)
{
	int i;
	static u8 keybuf[4] = {0xFF, 0xFF, 0xFF, 0xFF};
	
	keybuf[0] = (keybuf[0]<<1) | KEY1;
	keybuf[1] = (keybuf[1]<<1) | KEY2;
	keybuf[2] = (keybuf[2]<<1) | KEY3;
	keybuf[3] = (keybuf[3]<<1) | (!WKUP);
	
	for(i=0; i<4; i++)
	{
		if(keybuf[i] == 0x00)
		{
			KeySta[i] = 0;
		}
		else if(keybuf[i] == 0xFF)
		{
			KeySta[i] = 1;
		}
	}
}

void KeyDriver(void)
{
	int i;
	static u8 backup[4] = {1,1,1,1};
	
	for(i=0; i<4; i++)
	{
		if(backup[i] != KeySta[i])
		{
			if(backup[i] != 0)
			{
				KeyAction(i+1);
			}
			backup[i] = KeySta[i];
		}
	}
}
