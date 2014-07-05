#include <U8glib.h>
#include "error_state.h"
#include "device_manager.h"
#include "device.h"

ErrorState::ErrorState(char* error)
{
    m_error = error;    
}

void ErrorState::draw(DRAW_HANDLER* u8g)
{
    const int BEGIN_POS_X = 2;
    const int BEGIN_POS_Y = 6;
    const int LINE_WIDTH = 21;
    const int LINE_HIGHT = 12;

    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y, "[[ Error ]]");
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 1 * LINE_HIGHT, "====================");
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 2 * LINE_HIGHT, m_error);
}

void ErrorState::process()
{
}

IState* ErrorState::nextState()
{
    return this;
}




















