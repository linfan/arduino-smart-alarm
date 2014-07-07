#ifndef __SMART_ALARM_IDLE_STATE_H__
#define __SMART_ALARM_IDLE_STATE_H__

#include "prompt_state.h"
#include "config.h"
#include "event.h"

#define CHECK_EVENT_INTERVAL 10
#define REMIND_AHEAD_TIME_IN_SECOND (5 * 60)

class IdleState : public IPromptState
{
private:
    Event* m_nextEvent;
    unsigned long m_lastCheckTime;
    bool m_showNextEvent;
    IState* m_nextState;
public:
    IdleState();
    void draw(DRAW_HANDLER*);
    void process();
    IState* nextState();
};

#endif

