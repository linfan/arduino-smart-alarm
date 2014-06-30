void initSerialForDebug()
{
#if DEBUG
    // Initialize Serial
    Serial.begin(9600);
    // Wait until a Serial Monitor is connected.
    //while (!Serial);
#endif
}

void debugLog(char* str)
{
#if DEBUG
    Serial.print(str);
    Serial.print('\n');
    Serial.flush();
#endif
}

void initLedOnPin13()
{
    pinMode(13, OUTPUT);
}

void debugLedOn()
{
    digitalWrite(13, HIGH); 
}

void debugLedOff()
{
    digitalWrite(13, LOW);
}













