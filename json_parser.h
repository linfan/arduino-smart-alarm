#ifndef __SMART_ALARM_JSON_PARSER_H__
#define __SMART_ALARM_JSON_PARSER_H__

class JsonParser
{
private:
    JsonParser() {}
public:
    static JsonParser* Ins() {
        static JsonParser* instance = new JsonParser();
        return instance;
    }
    void extractValue(char* text, char* key, char* val);
};

#endif

