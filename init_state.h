#ifndef __SMART_ALARM_INIT_STATE_H__
#define __SMART_ALARM_INIT_STATE_H__

#include "state.h"
#include "config.h"

class InitState : public IState
{
private:
    bool m_animationFinished;
    IState* m_nextState;
public:
    InitState();
    void draw(DRAW_HANDLER*);
    void process();
    IState* nextState();
    static void tick();
};

#endif






















