#include <U8glib.h>
#include "event_state.h"
#include "device_manager.h"
#include "device.h"

EventState::EventState(Event* event)
{
    m_event = event;
}

void EventState::draw_event(DRAW_HANDLER* u8g,
    char* summary, char* startTime, 
    char* endTime, char* location)
{
    const int BEGIN_POS_X = 2;
    const int BEGIN_POS_Y = 6;
    const int LINE_WIDTH = 21;
    const int LINE_HIGHT = 12;
    const int LOCATION_WIDTH = 16;
    int loop_len;
    int s_len = strlen(summary);
    int l_len = strlen(location);
    char s_buf[3][LINE_WIDTH+1] = {'\0'};
    char l_buf[LOCATION_WIDTH+1] = {'\0'};

    loop_len = s_len > 3*LINE_WIDTH ? 3*LINE_WIDTH : s_len;
    for (int i = 0; i < loop_len; ++i) {
        s_buf[i/LINE_WIDTH][i%LINE_WIDTH] = summary[i];
    }
    loop_len = l_len > LOCATION_WIDTH ? LOCATION_WIDTH : l_len;
    for (int i = 0; i < loop_len; ++i) {
        l_buf[i] = location[i];
    }

    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y, s_buf[0]);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 1 * LINE_HIGHT, s_buf[1]);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 2 * LINE_HIGHT, s_buf[2]);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 3 * LINE_HIGHT, "Time: [      -      ]");
    u8g->drawStr( BEGIN_POS_X + 47, BEGIN_POS_Y + 3 * LINE_HIGHT, startTime);
    u8g->drawStr( BEGIN_POS_X + 85, BEGIN_POS_Y + 3 * LINE_HIGHT, endTime);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 4 * LINE_HIGHT, "Loc:");
    u8g->drawStr( BEGIN_POS_X + 30, BEGIN_POS_Y + 4 * LINE_HIGHT, l_buf);
}

void EventState::EventState::draw(DRAW_HANDLER* u8g)
{
    draw_event(u8g, m_event->summary, m_event->startTime,
               m_event->endTime, m_event->location);
}

void EventState::process()
{

}

IState* EventState::nextState()
{
    return this;
}





















