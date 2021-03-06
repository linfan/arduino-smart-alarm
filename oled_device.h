#ifndef __SMART_ALARM_OLED_DEVICE_H__
#define __SMART_ALARM_OLED_DEVICE_H__

#include "device.h"
#include "event.h"
#include "notification.h"

#define BEGIN_POS_X   2
#define BEGIN_POS_Y   6
#define LINE_WIDTH    21
#define LINE_HIGHT    12

class U8GLIB_SSD1306_132X64;
#define DRAW_HANDLER U8GLIB_SSD1306_132X64
typedef void (*DRAW_METHOD)(DRAW_HANDLER*);

#define LINE_4_CHAR_PREFIX_WIDTH 16

enum OledState
{
    OLED_IDLE,
    OELD_SHOW_ERROR,
    OLED_SHOW_WELCOME_SCREEN,
    OLED_SHOW_NEXT_EVENT,
    OLED_SHOW_EVENT_DETAIL,
    OLED_SHOW_UPDATING,
    OLED_WAIT
};

// 1.3" OLED
class OledDevice : public IDevice
{
    DRAW_HANDLER* u8g;
    OledState m_oledState;
    Event* m_event_to_show;
    const char* m_error_string;

    void drawWith4CharactersPrefix(DRAW_HANDLER*, int, int, const char*, char*);
    int drawEventSummary(DRAW_HANDLER*, int, int, int, char*);
    void drawStartEndTime(DRAW_HANDLER*, int, int, char*, char*);
    void drawLocation(DRAW_HANDLER*, int, int, char*);
    void drawOrganizer(DRAW_HANDLER*, int, int, char*);
    void drawStartTime(DRAW_HANDLER*, int, int, char*);

    void drawWelcomeScreen();
    void drawNextEvent();
    void drawEventDetail();
    void drawErrorScreen();
    void drawTime();
    void drawUpdating();
public:
    OledDevice();
    
    void init();
    void step();
    void notify(Notification*);
};

#endif

