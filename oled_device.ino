#include "oled_device.h"
#include "device_manager.h"
#include "notification.h"

#define SET_DRAW_DURATION_AND_MAX_STEP(DURATION, STEP, REPEAT) \
    static uint8_t step = 0, druation = 0; \
    ++druation; \
    if ( druation >= DURATION ) { \
        druation = 0; ++step; \
        if ( step >= STEP ) { \
            if (REPEAT) { \
                step = 0; \
            } else { \
                --step; \
            } \
        } \
    }
    
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

void OledDevice::step()
{
    // draw welcome page
    const int MAX_STEP = 10;
    SET_DRAW_DURATION_AND_MAX_STEP(16, MAX_STEP, false)

    u8g->drawStr( 2, 8, "Welcome ^_^   (v1.0)");
    u8g->setScale2x2();
    u8g->drawStr( 3, 4 + step, "I Have ");
    u8g->drawStr( 24, 12 + step, "A Date");
    u8g->undoScale();

    if (step == MAX_STEP - 1) {
        DeviceManager::Ins()->notify(new Notification(WELCOME_SCREEN_DONE, NULL));
    }
}

void OledDevice::show(IDrawable* drawable)
{
    u8g->firstPage();  
    do {
        drawable->draw(u8g);
    } while( u8g->nextPage() );
}

void OledDevice::notify(Notification*)
{

}

