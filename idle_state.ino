#include <U8glib.h>
#include "idle_state.h"
#include "device_manager.h"
#include "device.h"
#include "utility.h"
#include "event_state.h"
#include "oled_device.h"

IdleState::IdleState()
{
    m_nextEvent = NULL;
    m_lastCheckTime = Clock::Ins()->getTime();
    m_showNextEvent = true;
    m_nextState = this;
}

void IdleState::draw(DRAW_HANDLER* u8g)
{
    if (m_showNextEvent)
    {
        u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y, "[[ Next Event ]]");
        u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 1 * LINE_HIGHT, "====================");
        drawStartEndTime(u8g, BEGIN_POS_X, BEGIN_POS_Y + 2 * LINE_HIGHT,
                         m_nextEvent->startTime, m_nextEvent->endTime);
        drawLocation(u8g, BEGIN_POS_X, BEGIN_POS_Y + 3 * LINE_HIGHT, m_nextEvent->location);
        drawEventSummary(u8g, BEGIN_POS_X, BEGIN_POS_Y + 4 * LINE_HIGHT, 1, m_nextEvent->summary);
    }
    else
    {
        // Empty here, light goes out
    }
}

void IdleState::process()
{
    unsigned long nowTime = Clock::Ins()->getTime();
    if (nowTime - m_lastCheckTime >= 60 * CHECK_EVENT_INTERVAL)
    {
        m_lastCheckTime = nowTime;
        INetworkDevice* d_network = DeviceManager::Ins()->getNetworkDevice();
        if (m_nextEvent)
            delete m_nextEvent;
        m_nextEvent = new Event;
        d_network->getNthEvent(0, m_nextEvent);
    }
    if (Clock::ToNumericTime(m_nextEvent->startTime) - nowTime < REMIND_AHEAD_TIME_IN_SECOND)
    {
        m_nextState = new EventState(m_nextEvent);
    }
}

IState* IdleState::nextState()
{
    return m_nextState;
}

