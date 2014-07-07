#include <U8glib.h>
#include <string.h>
#include "init_state.h"
#include "state_switcher.h"
#include "error_state.h"
#include "idle_state.h"
#include "device_manager.h"
#include "device.h"
#include "clock.h"
#include "utility.h"

#define print_current_time() \
    char strTime[26]; \
    Clock::ToStandardTime(Clock::Ins()->getTime(), strTime); \
    debugLog(strTime);

InitState::InitState()
{
    m_animationFinished = false;
    m_nextState = this;
}

void InitState::draw(DRAW_HANDLER* u8g)
{
    // draw welcome page
    const int MAX_STEP = 10;
    SET_DRAW_DURATION_AND_MAX_STEP(16, MAX_STEP, false)

    u8g->drawStr( 2, 8, "Welcome ^_^   (v0.1)");
    u8g->setScale2x2();
    u8g->drawStr( 3, 4 + step, "I Have ");
    u8g->drawStr( 24, 12 + step, "A Date");
    u8g->undoScale();

    if (step == MAX_STEP - 1)
        m_animationFinished = true;
}

void InitState::process()
{
    if (!m_animationFinished)
        return;

    static bool neverAgain = false;
    if (neverAgain)
        return;
    neverAgain = true;

    INetworkDevice* d_network = DeviceManager::Ins()->getNetworkDevice();
    char* strTime = new char[26];
    d_network->getNetworkTime(strTime);
    if (strlen(strTime) == 0)
    {
        m_nextState = new ErrorState("Cannot connect to internet !");
    }
    else
    {
        Clock::Ins()->setTime(Clock::ToNumericTime(strTime));
        ITimerDevice* d_timer = DeviceManager::Ins()->getTimerDevice();
        d_timer->stopTimer();
        d_timer->setInterval(5000000); // 5 seconds
        d_timer->setInterruptCallback(InitState::tick);
        d_timer->startTimer();
        m_nextState = new IdleState;
    }
    delete[] strTime;
}

void InitState::tick()
{
    Clock::Ins()->increaseTime(5);
    //print_current_time();
}

IState* InitState::nextState()
{
    return m_nextState;
}

