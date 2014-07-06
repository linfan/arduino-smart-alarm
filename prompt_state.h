#ifndef __SMART_ALARM_PROMPT_STATE_H__
#define __SMART_ALARM_PROMPT_STATE_H__

#include "state.h"
#include "config.h"

#define LINE_4_CHAR_PREFIX_WIDTH 16

class IPromptState : public IState
{
private:
    void drawWith4CharactersPrefix(DRAW_HANDLER* u8g, int posX, int posY,
                               const char* prefix, char* source);
protected:
    int drawEventSummary(DRAW_HANDLER* u8g, int posX, int posY, 
                        int lines, char* summary);
    void drawStartEndTime(DRAW_HANDLER* u8g, int posX, int posY,
                          char* startDateTime, char* endDateTime);
    void drawLocation(DRAW_HANDLER* u8g, int posX, int posY, char* location);
    void drawOrganizer(DRAW_HANDLER* u8g, int posX, int posY, char* organizer);;
};

#endif




