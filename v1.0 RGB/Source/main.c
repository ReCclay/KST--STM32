#include "config.h"
#include "led.h"
#include "timer.h"


int main(void)
{
	
	LedInit();
	TIM5Init();
	TIM6Init(50000, 72);//50ms
	
	while(1)
	{

	}		
	
}

