#ifndef __SMART_ALARM_ASSERT_H__
#define __SMART_ALARM_ASSERT_H__

#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define TEST_MAIN_FILE \
    int __case_num = 1;

#define TEST_CASE_FILE \
    extern int __case_num;

#define TEST_CASE_BEGIN \
    cout << "==== Runing test case (" << __case_num << ") " << __FUNCTION__ << " ====" << endl; \
    ++__case_num;

class Assert
{
private:
    Assert();
public:
    static void str_equal(char* left, char* right)
    {
        if (strcmp(left, right) != 0)
            cout << "[NOK] \"" << left << "\" and \"" << right << "\" is NOT euqal" << endl;
        else
            cout << "[OK]  Pass: " << left << endl;
    }

    template <class T>
    static void equal(T left, T right)
    {
        if (left != right)
            cout << "[NOK] \"" << left << "\" and \"" << right << "\" is NOT euqal" << endl;
        else
            cout << "[OK]  Pass: " << left << endl;
    }
};

#endif
