#include <DNSServer.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include "ESPAsyncWebServer.h"

#include <LittleFS.h>
#include "FS.h"

void setup() {
  Serial.begin(115200);
  delay(5000);

  if (!LittleFS.begin() ) {
   Serial.println("Little FS not found. FAIL!");
   return;  
  }

  Serial.println("Little FS found. Let's list files.");

    Dir dir = LittleFS.openDir ("");
  while (dir.next ()) {
    Serial.println (dir.fileName ());
    Serial.println (dir.fileSize ());
  }

}

void loop() {


}
