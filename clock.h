#ifndef __SMART_ALARM_CLOCK_H__
#define __SMART_ALARM_CLOCK_H__

class Clock
{
private:
    Clock();
    unsigned long m_nowTime;

    static unsigned long getSecondsBeforeSpecifiedMonth(unsigned long month, bool isLeapYear);
    static unsigned long getSecondsBeforeSpecifiedYear(unsigned long year);
    static bool isLeapYear(unsigned long year);
    static unsigned long baseYear;
    static unsigned int dayInMonth[12];
public:
    static Clock* Ins() {
        static Clock* instance = new Clock();
        return instance;
    }

    static void ToStandardTime(unsigned long numTime, char* strTime);
    static unsigned long ToNumericTime(const char* formatedTime);

    void increaseTime(unsigned long delta);
    void setTime(unsigned long time);
    unsigned long getTime();
};

#endif





