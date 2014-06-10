#ifndef __SMART_ALARM_OLED_H__
#define __SMART_ALARM_OLED_H__

#define D0_PIN   10
#define D1_PIN   9
#define CS_PIN   12
#define DC_PIN   11
#define RST_PIN  8

void initOledScreen();
void draw(void (*method)(void));

#endif
