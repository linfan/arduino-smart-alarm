#ifndef __SMART_ALARM_STATE_SWITCHER_H__
#define __SMART_ALARM_STATE_SWITCHER_H__

#include "state.h"

class StateSwitcher
{
    StateSwitcher() {}
    ~StateSwitcher() {}
    IState* m_curState;
 
public:
    static StateSwitcher* Ins() {
        static StateSwitcher* instance = new StateSwitcher();
        return instance;
    }   

    IState* getCurState();
};

#endif

