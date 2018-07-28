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

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  //ʹ��GPIOE�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_15; //���������λѡ���� LEDS1->PE12,LEDS2->PE15
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�����������Ϊ50MHz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //�����������ģʽ
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //��ʼ��GPIOE�˿�
    GPIO_ResetBits(GPIOE, GPIO_Pin_12 | GPIO_Pin_15);      //��������ߵ�ƽ�������λѡ��ʼ��Ϊ�ر�

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3
                                 |GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; //��������ܶ�ѡ���� D0~D7->PE0~7
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�����������Ϊ50MHz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //�����������ģʽ
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //��ʼ��GPIOG�˿�
    GPIO_SetBits(GPIOE, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3
                       |GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7); //����PE0~7����ߵ�ƽ������ܶ�ѡ��ʼ��Ϊ�ر�
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
