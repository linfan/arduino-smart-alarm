#ifndef __SMART_ALARM_STATE_H__
#define __SMART_ALARM_STATE_H__

class IState
{
public:
    IState();
    ~IState();
    
    virtual void show() = 0;
    virtual void process() = 0;
};

#endif
