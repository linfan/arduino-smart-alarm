#include <U8glib.h>
#include "oled_device.h"
#include "device_manager.h"
#include "config.h"
#include "event.h"

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

#define SHOW(CODE) \
    u8g->firstPage(); \  
    do { \
        CODE \
    } while( u8g->nextPage() );

OledDevice::OledDevice()
{
    u8g = new DRAW_HANDLER(D0_PIN, D1_PIN,CS_PIN, DC_PIN, RST_PIN);
    m_state = IDLE;
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

int OledDevice::drawEventSummary(DRAW_HANDLER* u8g, int posX, int posY,
                                 int lines, char* summary)
{
    int len = strlen(summary);
    char buf[3][LINE_WIDTH+1] = {'\0'};
    int loop_len = len > 3*LINE_WIDTH ? 3*LINE_WIDTH : len;
    for (int i = 0; i < loop_len; ++i) {
        buf[i/LINE_WIDTH][i%LINE_WIDTH] = summary[i];
    }
    for (int i = 0; i < lines; ++i) {
        u8g->drawStr( posX, posY + i * LINE_HIGHT, buf[i]);
    }
    return (len / LINE_WIDTH) < lines ? (len / LINE_WIDTH) : lines;
}

void OledDevice::drawStartEndTime(DRAW_HANDLER* u8g, int posX, int posY,
                                  char* startDateTime, char* endDateTime)
{
    char startTime[6] = {'\0'}, endTime[6] = {'\0'};
    for (int i = 0; i < 6; ++i) {
        startTime[i] = startDateTime[i+11];
        endTime[i] = endDateTime[i+11];
    }
    u8g->drawStr( posX, posY, "Time: [      -      ]");
    u8g->drawStr( posX + 47, posY, startTime);
    u8g->drawStr( posX + 85, posY, endTime);
}

void OledDevice::drawWith4CharactersPrefix(DRAW_HANDLER* u8g, int posX, int posY,
                                       const char* prefix, char* source)
{
    int len = strlen(source);
    char buf[LINE_4_CHAR_PREFIX_WIDTH+1] = {'\0'};
    int loop_len = len > LINE_4_CHAR_PREFIX_WIDTH ? LINE_4_CHAR_PREFIX_WIDTH : len;
    for (int i = 0; i < loop_len; ++i) {
        buf[i] = source[i];
    }
    u8g->drawStr( posX, posY, prefix);
    u8g->drawStr( posX + 30, posY, buf);
}

void OledDevice::drawLocation(DRAW_HANDLER* u8g, int posX, int posY, char* location)
{
    drawWith4CharactersPrefix(u8g, posX, posY, "Loc:", location);
}

void OledDevice::drawOrganizer(DRAW_HANDLER* u8g, int posX, int posY, char* organizer)
{
    drawWith4CharactersPrefix(u8g, posX, posY, "Orz:", organizer);
}

void OledDevice::drawNextEvent()
{
    SHOW(
        u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y, "[[ Next Event ]]");
        u8g->drawStr( BEGIN_POS_X, 
            BEGIN_POS_Y + 1 * LINE_HIGHT, "====================");
        drawStartEndTime(u8g, BEGIN_POS_X, BEGIN_POS_Y + 2 * LINE_HIGHT,
                         m_event_to_show->startTime, m_event_to_show->endTime);
        drawLocation(u8g, BEGIN_POS_X, BEGIN_POS_Y + 3 * LINE_HIGHT, 
            m_event_to_show->location);
        drawEventSummary(u8g, BEGIN_POS_X, BEGIN_POS_Y + 4 * LINE_HIGHT, 1, 
            m_event_to_show->summary);
    )
}

void OledDevice::drawEventDetail()
{
    SHOW(
        int summaryLines = drawEventSummary(u8g, 
            BEGIN_POS_X, BEGIN_POS_Y, 3, m_event_to_show->summary);
        if (summaryLines < 3) {
            drawOrganizer(u8g, BEGIN_POS_X, 
                BEGIN_POS_Y + 2 * LINE_HIGHT, m_event_to_show->organizer);
        }
        drawStartEndTime(u8g, BEGIN_POS_X, BEGIN_POS_Y + 3 * LINE_HIGHT,
                         m_event_to_show->startTime, m_event_to_show->endTime);
        drawLocation(u8g, BEGIN_POS_X, BEGIN_POS_Y + 4 * LINE_HIGHT, 
            m_event_to_show->location);
    )
}

void OledDevice::drawWelcomeScreen()
{
    const int MAX_STEP = 10;
    SET_DRAW_DURATION_AND_MAX_STEP(16, MAX_STEP, false)
    SHOW(
        u8g->drawStr( 2, 8, "Welcome ^_^   (v1.0)");
        u8g->setScale2x2();
        u8g->drawStr( 3, 4 + step, "I Have ");
        u8g->drawStr( 24, 12 + step, "A Date");
        u8g->undoScale();
    )
    if (step == MAX_STEP - 1)
    {
        DeviceManager::Ins()->notify(new Notification(INIT_SCREEN_FINISH, NULL));
        m_state = IDLE;
    }
}

void OledDevice::step()
{
    switch (m_state)
    {
    case IDLE:
        break;
    case SHOW_WELCOME_SCREEN:
        drawWelcomeScreen();
        break;
    case SHOW_NEXT_EVENT:
        break;
    case SHOW_EVENT_DETAIL:
        break;
    }
}

void OledDevice::notify(Notification* noti)
{
    switch(noti->type)
    {
    case INIT_BEING:
        m_state = SHOW_WELCOME_SCREEN;
        break;
    }
}

