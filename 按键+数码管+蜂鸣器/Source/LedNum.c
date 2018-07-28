#include "LedNum.h"

u8 LedBuff[2] = {0xFF, 0xFF};
const u8 LedChar[] = { 
0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
}; 

void LedNumInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	GPIO_SetBits(GPIOE, GPIO_Pin_15|GPIO_Pin_12);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	GPIO_SetBits(GPIOE, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
}

void LedNumScan(void)
{
	u16 tmp;
	static u8 i = 0;
	
	LedNum0_Off();//ÏûÒþ
	LedNum1_Off();
	tmp = GPIOE->ODR & 0xFF00;
	GPIOE->ODR = tmp | LedBuff[i];
	
	if(i == 0)
	{
		LedNum0_On();
		i++;
	}
	else
	{
		LedNum1_On();
		i = 0;
	}
}

void LedNumShowDec(u8 num)
{
	u8 tmp;
	
	LedBuff[0] = LedChar[num%10];
	tmp = (num/10) % 10;
	if(tmp != 0)
	{
		LedBuff[1] = LedChar[tmp];
	}
	else
	{
		LedBuff[1] = 0xFF;
	}
	
}
