#include "clock.h"
#include "assert.h"

TEST_CASE_FILE

void test_clock()
{
    TEST_CASE_BEGIN
    
    char* strtime = "2014-07-04T16:00:00+08:00";
    unsigned long time = Clock::Ins()->ToNumericTime(strtime);
    Assert::equal(time, 457804800UL);

    char new_strtime[26];
    Clock::Ins()->ToStandardTime(time, new_strtime);
    Assert::str_equal(strtime, new_strtime);

    Clock::Ins()->setTime(time);
    Clock::Ins()->increaseTime(60);
    Assert::equal(Clock::Ins()->getTime(), time + 60);
}

