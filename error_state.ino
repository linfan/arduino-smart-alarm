#include <U8glib.h>
#include "error_state.h"
#include "device_manager.h"
#include "device.h"
#include "oled_device.h"

ErrorState::ErrorState(char* error)
{
    m_error = error;    
}

void ErrorState::draw(DRAW_HANDLER* u8g)
{
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

