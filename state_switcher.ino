#include "state_switcher.h"

void StateSwitcher::switchTo(IState* newState)
{
    if (m_curState)
        delete m_curState;
    m_curState = newState;
}

IState* StateSwitcher::getCurState()
{
    return m_curState;
}
















