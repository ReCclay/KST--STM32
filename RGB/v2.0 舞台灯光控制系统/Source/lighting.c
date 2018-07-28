#include "lighting.h"
#include "led.h"
#include "LedNum.h"

eRGBType LightType = E_TurnOff;
int LightStep = 0;//��������
int LightTimer = 0;//������ʱ��
int LightSpeed = 3;//�����ٶȵȼ�

const int SpeedTable[] = {
	50, 100, 200, 300, 400, 500, 600, 800, 1000, 1500, 2000, 3000, 5000
};

void LightingInit()
{
	LedNumShowDec(LightType);
}

void KeyAction(int code)
{
	switch(code)
	{
	case 1://����1���л���ʾ����
		LightType++;
		if(LightType >= E_RGBTypeNum)
		{
			LightType = E_TurnOff;
		}
		LedNumShowDec(LightType);
		break;
	case 2:
		if(LightSpeed > 0)
		{
			LightSpeed--;
		}
		break;
	case 3:
		if(LightSpeed < (sizeof(SpeedTable)/sizeof(SpeedTable[0]) - 1))
		{
			LightSpeed++;
		}
		break;
	default:
		break;
	}
	
	//ʵ�ֱ��θı����´��ж�������ˢ�£�
	LightStep = 0;
	LightTimer = 0;
}

void LightingScan(int ms)
{
	u8 r, g, b;
	int sel, level;
	
	if(LightTimer == 0)
	{
		switch(LightType)
		{
		case E_TurnOff:
			LedShowColor(0, 0, 0);
			break;
		case E_Red:
			LedShowColor((LightStep==0)?100:0, 0, 0);
			LightStep = !LightStep;
			break;
		case E_Green:
			LedShowColor(0, (LightStep==0)?100:0, 0);
			LightStep = !LightStep;
			break;
		case E_Blue:
			LedShowColor(0, 0, (LightStep==0)?100:0);
			LightStep = !LightStep;
			break;
		case E_Yellow: //��ɫ������˸
			LedShowColor((LightStep==0)?100:0, (LightStep==0)?100:0, 0);
			LightStep = !LightStep;
			break;
		case E_Purple: //��ɫ������˸
			LedShowColor((LightStep==0)?100:0, 0, (LightStep==0)?100:0);
			LightStep = !LightStep;
			break;
		case E_Cyan: //��ɫ������˸
			LedShowColor(0, (LightStep==0)?100:0, (LightStep==0)?100:0);	
			LightStep = !LightStep;
			break;
		case E_White: //��ɫ������˸
			(LightStep==0) ? LedShowColor(100,100,100) : LedShowColor(0,0,0);
			LightStep = !LightStep;
			break;
		case E_RedGreen: //���̽�����˸
			LedShowColor((LightStep==0)?100:0, (LightStep!=0)?100:0, 0);
			LightStep = !LightStep;
			break;
		case E_BlueGreen: //���̽�����˸
			LedShowColor(0, (LightStep!=0)?100:0, (LightStep==0)?100:0);
			LightStep = !LightStep;
			break;
		case E_RedBlue: //����������˸
			LedShowColor((LightStep==0)?100:0, 0, (LightStep!=0)?100:0);
			LightStep = !LightStep;
			break;
		case E_7Color: //��ɫ������˸
			LightStep++;
			LedShowColor(((LightStep&0x1)!=0)?100:0, ((LightStep&0x2)!=0)?100:0,
			((LightStep&0x4)!=0)?100:0);
			if (LightStep >= 7)
			{
				LightStep = 0;
			}
			break;
		case E_GradientRGB: //���������潥��
			LightStep++;
			r = (LightStep<=20) ? (LightStep*5) : 0;
			g = (LightStep>20 && LightStep<=40) ? ((LightStep-20)*5) : 0;
			b = (LightStep>40 && LightStep<=60) ? ((LightStep-40)*5) : 0;
			LedShowColor(r, g, b);
			if (LightStep >= 60)
			{
				LightStep = 0;
			}
			break;
		case E_Gradient7C: //��ɫ���潥��
			sel = LightStep / 20 + 1;
			level = LightStep % 20 + 1;
			r = ((sel&0x1) != 0) ? (level*5) : 0; //sel �� 0 λ���ƺ�Ƶ�ѡͨ
			g = ((sel&0x2) != 0) ? (level*5) : 0; //sel �� 1 λ�����̵Ƶ�ѡͨ
			b = ((sel&0x4) != 0) ? (level*5) : 0; //sel �� 2 λ�������Ƶ�ѡͨ
			LedShowColor(r, g, b);
			if (++LightStep >= 20*7)
			{
				LightStep = 0;
			}
			break;
		default:
			break;
		}
	}
	LightTimer += ms;
	if (LightTimer >= SpeedTable[LightSpeed])
	{
		LightTimer = 0;
	}
}

