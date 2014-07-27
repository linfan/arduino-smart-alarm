#include "json_parser.h"
#include "utility.h"
#include <string.h>

void JsonParser::extractValue(char* text, char* key, char* val)
{
    val[0] = '\0';
    debugPPrint(">> Extracting [");
    debugPrint(key)
    char* keyBeginPos = strstr(text, key);
    if (keyBeginPos) {
        //debugPPrint("Get key begin pos: ");
        //debugLog(keyBeginPos - text);
        int keyLength = strlen(key);
        char* keyEndPos = keyBeginPos + keyLength + 1;
        char* valueBeginPos = strstr(keyEndPos, "\"") + 1;
        if (valueBeginPos) {
            //debugPPrint("Get value begin pos: ");
            //debugLog(valueBeginPos - text);
            char* valueEndPos = strstr(valueBeginPos, "\"");
            if (valueEndPos) {
                //debugPPrint("Get value end pos: ");
                //debugLog(valueEndPos - text);
                int valueLength = valueEndPos - valueBeginPos;
                strncpy(val, valueBeginPos, valueLength);
                val[valueLength] = '\0';
                //debugPLog("String copied.");
            }
        }
    }
    debugPPrint("] get [");
    debugPrint(val);
    debugPLog("]");
}

