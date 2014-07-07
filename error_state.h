#ifndef __SMART_ALARM_ERROR_STATE_H__
#define __SMART_ALARM_ERROR_STATE_H__

#include "state.h"
#include "config.h"

class ErrorState : public IState
{
    char* m_error;
public:
    ErrorState(char* error);
    void draw(DRAW_HANDLER*);
    void process();
    IState* nextState();
};

#endif

