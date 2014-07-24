#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "clock.h"
#include "utility.h"

unsigned long Clock::baseYear = 2000;
unsigned int Clock::dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Clock::isLeapYear(unsigned long year)
{
    return ( ((year%4)==0 && (year%100)!=0) || (year%400)==0 );
}

unsigned long Clock::getSecondsBeforeSpecifiedMonth(unsigned long month, bool isLeapYear)
{   
    unsigned long totalDays = 0;
    for (int i = 1; i < month; ++i)
    {
        totalDays += dayInMonth[i-1];
    }
    if (month > 2)
        totalDays += isLeapYear ? 1 : 0;
    return 60L * 60L * 24L * totalDays;
}

unsigned long Clock::getSecondsBeforeSpecifiedYear(unsigned long year)
{
    unsigned int leapAdjust;
    if (isLeapYear(year))
        leapAdjust = 0;
    else if (isLeapYear(year + 1))
        leapAdjust = 1;
    else if (isLeapYear(year + 2))
        leapAdjust = 2;
    else //if (isLeapYear(year + 3))
        leapAdjust = 3;
    return 60L * 60L * 24L * (((year - baseYear) * 365) +
           ((year - baseYear) / 4) +
           (((year - baseYear) % 4) > leapAdjust ? 1 : 0));
}

void Clock::ToStandardTime(unsigned long numTime, char* strTime)
{
    //strTime should be a char[26]
    unsigned long year = baseYear;
    while (getSecondsBeforeSpecifiedYear(year) <= numTime)
        ++year;
    numTime -= getSecondsBeforeSpecifiedYear(--year);

    unsigned long month = 1;
    while (getSecondsBeforeSpecifiedMonth(month, isLeapYear(year)) <= numTime)
        ++month;
    numTime -= getSecondsBeforeSpecifiedMonth(--month, isLeapYear(year));

    unsigned long day = numTime / (60L * 60L * 24L);
    numTime -= (day * 60L * 60L * 24L);

    unsigned long hour = numTime / (60L * 60L);
    numTime -= (hour * 60L * 60L);

    unsigned long minute = numTime / 60L;
    numTime -= (minute * 60L);

    unsigned long second = numTime;

    sprintf(strTime, "%04lu-%02lu-%02luT%02lu:%02lu:%02lu+08:00", year, month, day, hour, minute, second);
}

unsigned long Clock::ToNumericTime(const char* formatedTime)
{
    //2014-07-04T16:00:00+08:00
    char strTime[26] = {'\0'};
    strcpy(strTime, formatedTime);
    strTime[4] = '\0';
    unsigned long year = atoi(strTime);
    strTime[7] = '\0';
    unsigned long month = atoi(strTime + 5);
    strTime[10] = '\0';
    unsigned long day = atoi(strTime + 8);
    strTime[13] = '\0';
    unsigned long hour = atoi(strTime + 11);
    strTime[16] = '\0';
    unsigned long minute = atoi(strTime + 14);
    strTime[19] = '\0';
    unsigned long second = atoi(strTime + 17);
    return getSecondsBeforeSpecifiedYear(year) +
            getSecondsBeforeSpecifiedMonth(month, isLeapYear(year)) +
            day * (60L * 60L * 24L) +
            hour * (60L * 60L) +
            minute * (60L) +
            second;
}

void Clock::increaseTime(unsigned long delta)
{
    m_nowTime += delta;
}

void Clock::setTime(unsigned long time)
{
    m_nowTime = time;
}

unsigned long Clock::getTime()
{
    return m_nowTime;
}

