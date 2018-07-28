#ifndef LIGHTING_H
#define LIGHTING_H

#include "config.h"

typedef enum _eRGBType {
	E_TurnOff,
	E_Red,
	E_Green,
	E_Blue,
	E_Yellow,
	E_Purple,
	E_Cyan,
	E_White,
	E_RedGreen,
	E_BlueGreen,
	E_RedBlue,
	E_7Color,
	E_GradientRGB,
	E_Gradient7C,
	E_RGBTypeNum
}eRGBType;

void LightingInit(void);
void LightingScan(int ms);

#endif
