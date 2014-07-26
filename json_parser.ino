#include "json_parser.h"
#include "utility.h"
#include <string.h>

void JsonParser::extractValue(char* text, char* key, char* val)
{
    val[0] = '\0';
    debugPrint(">> Extracting [");
    debugPrint(key)
    debugPrint("] from [");
    debugPrint(text)
    debugLog("]");
    char* keyBeginPos = strstr(text, key);
    if (keyBeginPos) {
        debugPrint("Get key begin pos: ");
        debugLog(keyBeginPos - text);
        int keyLength = strlen(key);
        char* keyEndPos = keyBeginPos + keyLength + 1;
        char* valueBeginPos = strstr(keyEndPos, "\"") + 1;
        if (valueBeginPos) {
            debugPrint("Get value begin pos: ");
            debugLog(valueBeginPos - text);
            char* valueEndPos = strstr(valueBeginPos, "\"");
            if (valueEndPos) {
                debugPrint("Get value end pos: ");
                debugLog(valueEndPos - text);
                int valueLength = valueEndPos - valueBeginPos;
                strncpy(val, valueBeginPos, valueLength);
                val[valueLength] = '\0';
                debugLog("String copied.");
            }
        }
    }
    debugPrint("Get [");
    debugPrint(val);
    debugLog("]");
}

