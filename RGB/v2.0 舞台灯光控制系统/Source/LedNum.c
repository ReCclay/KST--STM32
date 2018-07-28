#include "LedNum.h"

u8 LedBuff[2] = {
	0xFF, 0xFF
};
u8 LedChar[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
    0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
};

void LedNumInit()
{
	GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  //使能GPIOE端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_15; //设置数码管位选引脚 LEDS1->PE12,LEDS2->PE15
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //设置输出速率为50MHz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //设置推挽输出模式
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化GPIOE端口
    GPIO_ResetBits(GPIOE, GPIO_Pin_12 | GPIO_Pin_15);      //设置输出高电平，数码管位选初始化为关闭

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3
                                 |GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; //设置数码管段选引脚 D0~D7->PE0~7
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //设置输出速率为50MHz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //设置推挽输出模式
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化GPIOG端口
    GPIO_SetBits(GPIOE, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3
                       |GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7); //设置PE0~7输出高电平，数码管段选初始化为关闭
}

void LedNumScan()
{
	u16 tmp;
	static u8 i = 0;
	
	LedNum0_Off();
	LedNum1_Off();
	
	tmp = GPIO_ReadOutputData(GPIOE) & 0xFF00;
	GPIO_Write(GPIOE, tmp | LedBuff[i]);
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
