#ifndef __SMART_ALARM_STATE_SWITCHER_H__
#define __SMART_ALARM_STATE_SWITCHER_H__

#include "state.h"

class StateSwitcher
{
    IState* m_curState;
 
public:
    StateSwitcher() {}
    ~StateSwitcher() {}
    
    static StateSwitcher* Ins() {
        static StateSwitcher* instance = new StateSwitcher();
        return instance;
    }   

    void switchTo(IState*);
    IState* getCurState();
};

#endif













