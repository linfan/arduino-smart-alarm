#include <SoftwareSerial.h>

SoftwareSerial wifiSerial(2, 3); // RX, TX

void setup()
{
    Serial.begin(9600);
    Serial.write("Go !\n");
    
    wifiSerial.begin(4800);

    doGet("/event/list?user=1&lazy=1");
    //doGet("/time");
}

void loop()
{}

void doGet(char *url)
{
    Serial.println("send >>");
    wifiSerial.print("GET ");
    wifiSerial.print(url);
    wifiSerial.println(" HTTP/1.0");
    wifiSerial.println("");
    wifiSerial.println("Connection: close");
    wifiSerial.println();
    
    Serial.println("receive >>");
    for(int i = 0 ; i = 10; ++i) {
        delay(50);
        while (wifiSerial.available())
            Serial.write(wifiSerial.read());
    }
}

