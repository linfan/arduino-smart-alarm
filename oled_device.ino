// 1.3" OLED
#include "oled_device.h"
#include "U8glib.h"

U8GLIB_SSD1306_132X64 u8g(D0_PIN, D1_PIN,CS_PIN, DC_PIN, RST_PIN);

void OledDevice::init()
{ 
    //u8g.setRot180();  // flip screen, if required
    pinMode(8, OUTPUT);           
    digitalWrite(8, HIGH);
    u8g.setFont(u8g_font_6x10);
    u8g.setFontRefHeightExtendedText();
    u8g.setDefaultForegroundColor();
    u8g.setFontPosTop();
}

void OledDevice::draw(void (*method)(void))
{
    u8g.firstPage();  
    do {
        method();
    } while( u8g.nextPage() );
}

