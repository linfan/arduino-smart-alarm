#include "assert.h"

TEST_MAIN_FILE

typedef void (*TEST_CASE_FUNC)();
vector<TEST_CASE_FUNC> test_case_list;

extern void test_clock();
extern void test_json_parser();
extern void test_device_list();

void run_test_case()
{
    vector<TEST_CASE_FUNC>::iterator iter = test_case_list.begin();
    for (; iter != test_case_list.end(); iter++) (*iter)();
}

void add_test_case(TEST_CASE_FUNC case_test_func_name)
{
    test_case_list.push_back(case_test_func_name);
}

int main()
{
    add_test_case(test_clock);
    add_test_case(test_json_parser);
    add_test_case(test_device_list);
    run_test_case();
    return 0;
}
