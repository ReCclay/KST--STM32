#include "config.h"
#include "key.h"
#include "led.h"
#include "LedNum.h"
#include "timer.h"
#include "lighting.h"

int main(void)
{
	LedInit(); //LED �� RGB ���ų�ʼ��
	LedNumInit(); //��������ų�ʼ��
	KeyInit(); //�������ų�ʼ��
	LightingInit(); //�ƹ�Ч����ʼ��
	TIM5Init(); //���� TIM5 ���Կ��� RGB ˢ��
	TIM6Init(2000, 72); //���� TIM6 ��ʱ 2ms
	
	while(1)
	{
		KeyDriver();
	}		
	
}

