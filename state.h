#ifndef __SMART_ALARM_STATE_H__
#define __SMART_ALARM_STATE_H__

#include "drawable.h"

#define SET_DRAW_SPPED_AND_DURATION(SPEED, DURATION) \
    static uint8_t step = 0, speed = 0; \
    speed++; \
    if ( speed >= SPEED ) \
    { \
        speed = 0; step++; \
        if ( step >= DURATION ) step = 0; \
    }

class IState : public IDrawable
{
public:
    virtual void process() = 0;
};

#endif












