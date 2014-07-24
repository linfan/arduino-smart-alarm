#include "json_parser.h"
#include "assert.h"

TEST_CASE_FILE

void test_json_parser()
{
    TEST_CASE_BEGIN

    char* json_str = "{\"status\": \"OK\", \"events\": [{\"start\": \"2014-07-07T16:30:00+08:00\", \"organizer\": \"Lanying Wu\", \"end\": \"2014-07-07T17:30:00+08:00\", \"location\": \"Ping Pang Room\", \"summary\": \"AWS training (2) - workshop\"}]}";
    char value[60];

    JsonParser::Ins()->extractValue(json_str, "summary", value);
    Assert::str_equal(value, "AWS training (2) - workshop");
    
    JsonParser::Ins()->extractValue(json_str, "start", value);
    Assert::str_equal(value, "2014-07-07T16:30:00+08:00");

    JsonParser::Ins()->extractValue(json_str, "end", value);
    Assert::str_equal(value, "2014-07-07T17:30:00+08:00");

    JsonParser::Ins()->extractValue(json_str, "organizer", value);
    Assert::str_equal(value, "Lanying Wu");

    JsonParser::Ins()->extractValue(json_str, "location", value);
    Assert::str_equal(value, "Ping Pang Room");

    JsonParser::Ins()->extractValue(json_str, "no_exist_key", value);
    Assert::str_equal(value, "");

}

