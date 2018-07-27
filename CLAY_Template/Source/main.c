#include "config.h"
#include "timer.h"
#include "beep.h"
#include "key.h"
#include "LedNum.h"

int main(void)
{
	
	KeyInit();
	LedNumInit();
	BeepInit();
	TIM6Init(2000, 72);
	
	while(1)
	{
		KeyDriver();
	}		
}

void KeyAction(int code)
{
	static u8 num = 0;
	
	switch(code)
	{
		case 1:
			if(num < 99)
			{
				num++;
			}
			Beep(100);
			break;
		case 2:
			if(num > 0)
			{
				num --;
			}
			Beep(-1);
			break;
		case 3:
			num = 0;
			Beep(0);
			break;
	}
	
	LedNumShowDec(num);
}

