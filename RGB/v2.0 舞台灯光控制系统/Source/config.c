#include "config.h"

/*微秒延时函数，us-延时时间*/
void delay_us(u16 us)
{
	u8 i;	
	while (us--)
	{
		for(i=8;i>0;i--);		
	}
}

/*毫秒延时函数，ms-延时时间*/
void delay_ms(u16 nms)
{ 	
	while (nms--)
	{
		delay_us(960);
	}            
}


