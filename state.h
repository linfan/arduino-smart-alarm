#ifndef __SMART_ALARM_STATE_H__
#define __SMART_ALARM_STATE_H__

#include "drawable.h"

#define SET_DRAW_DURATION_AND_MAX_STEP(DURATION, STEP, REPEAT) \
    static uint8_t step = 0, druation = 0; \
    ++druation; \
    if ( druation >= DURATION ) { \
        druation = 0; ++step; \
        if ( step >= STEP ) { \
            if (REPEAT) { \
                step = 0; \
            } else { \
                --step; \
            } \
        } \
    }

class IState : public IDrawable
{
public:
    virtual void draw(DRAW_HANDLER*) = 0;
    virtual void process() = 0;
    virtual IState* nextState() = 0;
};

#endif






















