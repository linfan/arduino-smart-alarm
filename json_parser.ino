#include "json_parser.h"
#include <string.h>

void JsonParser::extractValue(char* text, char* key, char* val)
{
    val[0] = '\0';
    char* keyBeginPos = strstr(text, key);
    if (keyBeginPos) {
        int keyLength = strlen(key);
        char* keyEndPos = keyBeginPos + keyLength + 1;
        char* valueBeginPos = strstr(keyEndPos, "\"") + 1;
        if (valueBeginPos) {
            char* valueEndPos = strstr(valueBeginPos, "\"");
            if (valueEndPos) {
                int valueLength = valueEndPos - valueBeginPos;
                strncpy(val, valueBeginPos, valueLength);
                val[valueLength] = '\0';
            }
        }
    }
}

