#include <U8glib.h>
#include <string.h>
U8GLIB_SSD1306_132X64* u8g = new U8GLIB_SSD1306_132X64(10, 9, 12, 11, 13);
                                                    // D0, D1,CS, DC, RST

void initSerialForDebug()
{
    Serial.begin(9600);   // Initialize Serial
}
void debugLog(char* str)
{
    Serial.print(str);
    Serial.print('\n');
    Serial.flush();
}

void OledDevice_init()
{
    //u8g->setRot180();  // flip screen, if required
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    u8g->setFont(u8g_font_6x10);
    u8g->setFontRefHeightExtendedText();
    u8g->setDefaultForegroundColor();
    u8g->setFontPosTop();
}

void OledDevice_draw(void (*method)(void))
{
    u8g->firstPage();
    do {
        method();
    } while ( u8g->nextPage() );
}

#define SET_DRAW_SPPED_AND_DURATION(SPEED, DURATION) \
    static uint8_t step = 0, speed = 0; \
    speed++; \
    if ( speed >= SPEED ) \
    { \
        speed = 0; step++; \
        if ( step >= DURATION ) step = 0; \
    }

void draw_welcome_page()
{
    SET_DRAW_SPPED_AND_DURATION(16, 10)

    u8g->drawStr( 2, 8, "Welcome ^_^   (v0.1)");
    u8g->setScale2x2();
    u8g->drawStr( 3, 4 + step, "I Have ");
    u8g->drawStr( 24, 12 + step, "A Date");
    u8g->undoScale();
}

void draw_event(char* summary, char* startTime, char* endTime, char* location)
{
    const int BEGIN_POS_X = 2;
    const int BEGIN_POS_Y = 6;
    const int LINE_WIDTH = 21;
    const int LINE_HIGHT = 12;
    const int LOCATION_WIDTH = 16;
    int loop_len;
    int s_len = strlen(summary);
    int l_len = strlen(location);
    char s_buf[3][LINE_WIDTH+1] = {'\0'};
    char l_buf[LOCATION_WIDTH+1] = {'\0'};

    loop_len = s_len > 3*LINE_WIDTH ? 3*LINE_WIDTH : s_len;
    for (int i = 0; i < loop_len; ++i) {
        s_buf[i/LINE_WIDTH][i%LINE_WIDTH] = summary[i];
    }
    loop_len = l_len > LOCATION_WIDTH ? LOCATION_WIDTH : l_len;
    for (int i = 0; i < loop_len; ++i) {
        l_buf[i] = location[i];
    }

    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y, s_buf[0]);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 1 * LINE_HIGHT, s_buf[1]);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 2 * LINE_HIGHT, s_buf[2]);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 3 * LINE_HIGHT, "Time: [      -      ]");
    u8g->drawStr( BEGIN_POS_X + 47, BEGIN_POS_Y + 3 * LINE_HIGHT, startTime);
    u8g->drawStr( BEGIN_POS_X + 85, BEGIN_POS_Y + 3 * LINE_HIGHT, endTime);
    u8g->drawStr( BEGIN_POS_X, BEGIN_POS_Y + 4 * LINE_HIGHT, "Loc:");
    u8g->drawStr( BEGIN_POS_X + 30, BEGIN_POS_Y + 4 * LINE_HIGHT, l_buf);
}

void draw_text()
{
    draw_event("A_123456789_B_123456789_C_123456789_D_123456789_E_123456789_F_123456789_G_123456789", "12:12", "22:22", "ABCDEFGHIJKLMGOPQRSTUVWXZY");
}

void setup(void) {
    initSerialForDebug();
    OledDevice_init();
}

void loop(void) {
    // picture loop
    //OledDevice_draw(draw_text);
    OledDevice_draw(draw_welcome_page);

    // rebuild the picture after some delay
    delay(150);
}


