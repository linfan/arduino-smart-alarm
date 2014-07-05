#ifndef __SMART_ALARM_EVENT_STATE_H__
#define __SMART_ALARM_EVENT_STATE_H__

#include "state.h"
#include "event.h"
#include "config.h"

class EventState : public IState
{
    void draw_event(DRAW_HANDLER*,
                    char* summary, char* startTime,
                    char* endTime, char* location);
    Event* m_event;

public:
    EventState(Event* event);
    void draw(DRAW_HANDLER*);
    void process();
    IState* nextState();
};

#endif






















