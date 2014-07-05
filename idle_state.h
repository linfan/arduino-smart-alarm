#ifndef __SMART_ALARM_IDLE_STATE_H__
#define __SMART_ALARM_IDLE_STATE_H__

#include "state.h"
#include "config.h"
#include "event.h"

class IdleState : public IState
{
public:
    void draw(DRAW_HANDLER*);
    void process();
    IState* nextState();
};

#endif






















