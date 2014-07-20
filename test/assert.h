#ifndef __SMART_ALARM_ASSERT_H__
#define __SMART_ALARM_ASSERT_H__

#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define TEST_CASE_BEGIN \
    { \
        string __case_name = __FILE__; \
        __case_name.erase(find(__case_name.begin(), __case_name.end(), '.'), __case_name.end()); \
        cout << "==== Runing test case : " << __case_name << " ====" << endl; \
    }

void assert_str_equal(char* left, char* right)
{
    if (strcmp(left, right) != 0)
        cout << "[NOK] \"" << left << "\" and \"" << right << "\" is NOT euqal" << endl;
    else
        cout << "[OK]  Pass: " << left << endl;
}

template <class T>
void assert_equal(T left, T right)
{
    if (left != right)
        cout << "[NOK] \"" << left << "\" and \"" << right << "\" is NOT euqal" << endl;
    else
        cout << "[OK]  Pass: " << left << endl;
}

#endif
