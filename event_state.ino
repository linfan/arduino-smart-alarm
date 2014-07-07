#include <U8glib.h>
#include "event_state.h"
#include "idle_state.h"
#include "device_manager.h"
#include "device.h"
#include "oled_device.h"

EventState::EventState(Event* event)
{
    m_event = event;
    m_nextState = this;
}

EventState::~EventState()
{
    delete m_event;
}

void EventState::draw(DRAW_HANDLER* u8g)
{
    int summaryLines = drawEventSummary(u8g, BEGIN_POS_X, BEGIN_POS_Y, 3, m_event->summary);
    if (summaryLines < 3) {
        drawOrganizer(u8g, BEGIN_POS_X, BEGIN_POS_Y + 2 * LINE_HIGHT, m_event->organizer);
    }
    drawStartEndTime(u8g, BEGIN_POS_X, BEGIN_POS_Y + 3 * LINE_HIGHT,
                     m_event->startTime, m_event->endTime);
    drawLocation(u8g, BEGIN_POS_X, BEGIN_POS_Y + 4 * LINE_HIGHT, m_event->location);
}

void EventState::process()
{
    unsigned long nowTime = Clock::Ins()->getTime();
    unsigned long eventStartTime = Clock::ToNumericTime(m_event->startTime);
    if (eventStartTime > nowTime)
    {
        m_nextState = new IdleState;
    }
}

IState* EventState::nextState()
{
    return m_nextState;
}

