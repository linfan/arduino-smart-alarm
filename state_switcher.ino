#include "state_switcher.h"
#include "utility.h"

StateSwitcher::StateSwitcher()
{
    m_curState = 0;
}

void StateSwitcher::switchTo(IState* newState)
{
    if (m_curState && m_curState != newState)
    {
        delete m_curState;
    }
    m_curState = newState;
}

IState* StateSwitcher::getCurState()
{
    return m_curState;
}


























