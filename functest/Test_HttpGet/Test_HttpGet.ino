#include <SoftwareSerial.h>

SoftwareSerial wifiSerial(2, 3); // RX, TX

void setup()
{
    Serial.begin(9600);
    Serial.write("Go !\n");
    
    wifiSerial.begin(4800);

    doGet();
    for(int i = 0 ; i = 10; ++i) {
        delay(100);
        while (wifiSerial.available())
            Serial.write(wifiSerial.read());
    }
}

void loop()
{}

void doGet()
{
     //wifiSerial.println("GET /event/list?user=1 HTTP/1.0");
     wifiSerial.println("GET /time HTTP/1.0");
     wifiSerial.println("");
     wifiSerial.println("Connection: close");
     wifiSerial.println("Host: the-1.net:9999");
     wifiSerial.println();
     Serial.println("send >>");
}

