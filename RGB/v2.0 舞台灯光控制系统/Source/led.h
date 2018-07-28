#ifndef LED_H
#define LED_H

#include "config.h"

#define LED1  PG_OUT(7)
#define LED2  PG_OUT(8)
#define LED_R PE_OUT(9)
#define LED_G PE_OUT(11)
#define LED_B PE_OUT(13)

#define LED1_ON()  {LED1  = 0;}
#define LED2_ON()  {LED2  = 0;}
#define LED_R_ON() {LED_R = 0;}
#define LED_G_ON() {LED_G = 0;}
#define LED_B_ON() {LED_B = 0;}

#define LED1_OFF()  {LED1  = 1;}
#define LED2_OFF()  {LED2  = 1;}
#define LED_R_OFF() {LED_R = 1;}
#define LED_G_OFF() {LED_G = 1;}
#define LED_B_OFF() {LED_B = 1;}

void LedInit(void);
void LedShowColor(u8 red, u8 green, u8 blue);

#endif
