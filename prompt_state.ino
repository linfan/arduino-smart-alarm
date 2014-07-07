#include "prompt_state.h"

int IPromptState::drawEventSummary(DRAW_HANDLER* u8g, int posX, int posY,
                                 int lines, char* summary)
{
    int len = strlen(summary);
    char buf[3][LINE_WIDTH+1] = {'\0'};
    int loop_len = len > 3*LINE_WIDTH ? 3*LINE_WIDTH : len;
    for (int i = 0; i < loop_len; ++i) {
        buf[i/LINE_WIDTH][i%LINE_WIDTH] = summary[i];
    }
    for (int i = 0; i < lines; ++i) {
        u8g->drawStr( posX, posY + i * LINE_HIGHT, buf[i]);
    }
    return (len / LINE_WIDTH) < lines ? (len / LINE_WIDTH) : lines;
}

void IPromptState::drawStartEndTime(DRAW_HANDLER* u8g, int posX, int posY,
                                  char* startDateTime, char* endDateTime)
{
    char startTime[6] = {'\0'}, endTime[6] = {'\0'};
    for (int i = 0; i < 6; ++i) {
        startTime[i] = startDateTime[i+11];
        endTime[i] = endDateTime[i+11];
    }
    u8g->drawStr( posX, posY, "Time: [      -      ]");
    u8g->drawStr( posX + 47, posY, startTime);
    u8g->drawStr( posX + 85, posY, endTime);
}

void IPromptState::drawWith4CharactersPrefix(DRAW_HANDLER* u8g, int posX, int posY,
                                       const char* prefix, char* source)
{
    int len = strlen(source);
    char buf[LINE_4_CHAR_PREFIX_WIDTH+1] = {'\0'};
    int loop_len = len > LINE_4_CHAR_PREFIX_WIDTH ? LINE_4_CHAR_PREFIX_WIDTH : len;
    for (int i = 0; i < loop_len; ++i) {
        buf[i] = source[i];
    }
    u8g->drawStr( posX, posY, prefix);
    u8g->drawStr( posX + 30, posY, buf);
}

void IPromptState::drawLocation(DRAW_HANDLER* u8g, int posX, int posY, char* location)
{
    drawWith4CharactersPrefix(u8g, posX, posY, "Loc:", location);
}

void IPromptState::drawOrganizer(DRAW_HANDLER* u8g, int posX, int posY, char* organizer)
{
    drawWith4CharactersPrefix(u8g, posX, posY, "Orz:", organizer);
}

