#include "oled_device.h"

OledDevice::OledDevice()
{
    u8g = new DRAW_HANDLER(D0_PIN, D1_PIN,CS_PIN, DC_PIN, RST_PIN);
}

void OledDevice::init()
{ 
    //u8g->setRot180();  // flip screen, if required
    pinMode(RST_PIN, OUTPUT);           
    digitalWrite(RST_PIN, HIGH);
    u8g->setFont(u8g_font_6x10);
    u8g->setFontRefHeightExtendedText();
    u8g->setDefaultForegroundColor();
    u8g->setFontPosTop();
}

void OledDevice::show(IDrawable* drawable)
{
    u8g->firstPage();  
    do {
        drawable->draw(u8g);
    } while( u8g->nextPage() );
}















