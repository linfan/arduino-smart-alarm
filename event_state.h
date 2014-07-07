#ifndef __SMART_ALARM_EVENT_STATE_H__
#define __SMART_ALARM_EVENT_STATE_H__

#include "prompt_state.h"
#include "event.h"
#include "config.h"

class EventState : public IPromptState
{
private:
    Event* m_event;
    IState* m_nextState;
public:
    EventState(Event* event);
    ~EventState();
    void draw(DRAW_HANDLER*);
    void process();
    IState* nextState();
};

#endif

