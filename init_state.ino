#include <U8glib.h>
#include "init_state.h"

void InitState::draw_welcome_page(DRAW_HANDLER* u8g)
{
    SET_DRAW_SPPED_AND_DURATION(16, 10)

    u8g->drawStr( 2, 8, "Welcome ^_^   (v0.1)");
    u8g->setScale2x2();
    u8g->drawStr( 3, 4 + step, "I Have ");
    u8g->drawStr( 24, 12 + step, "A Date");
    u8g->undoScale();
}

void InitState::draw(DRAW_HANDLER* u8g)
{
    draw_welcome_page(u8g);
}

void InitState::process()
{

}











