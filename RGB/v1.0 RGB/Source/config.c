#include "config.h"

/*΢����ʱ������us-��ʱʱ��*/
void delay_us(u16 us)
{
	u8 i;	
	while (us--)
	{
		for(i=8;i>0;i--);		
	}
}

/*������ʱ������ms-��ʱʱ��*/
void delay_ms(u16 nms)
{ 	
	while (nms--)
	{
		delay_us(960);
	}            
}


