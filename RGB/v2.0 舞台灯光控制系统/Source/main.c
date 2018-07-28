#include "config.h"
#include "key.h"
#include "led.h"
#include "LedNum.h"
#include "timer.h"
#include "lighting.h"

int main(void)
{
	LedInit(); //LED 及 RGB 引脚初始化
	LedNumInit(); //数码管引脚初始化
	KeyInit(); //按键引脚初始化
	LightingInit(); //灯光效果初始化
	TIM5Init(); //配置 TIM5 用以控制 RGB 刷新
	TIM6Init(2000, 72); //配置 TIM6 定时 2ms
	
	while(1)
	{
		KeyDriver();
	}		
	
}

