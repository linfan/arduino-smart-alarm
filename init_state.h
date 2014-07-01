#ifndef __SMART_ALARM_INIT_STATE_H__
#define __SMART_ALARM_INIT_STATE_H__

#include "state.h"
#include "config.h"

class InitState : public IState
{
public:
    void draw(DRAW_HANDLER*);
    void process();
};

#endif
















