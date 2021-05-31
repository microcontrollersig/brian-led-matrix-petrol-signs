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

DNSServer dnsServer;
AsyncWebServer server(80);


class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {
    
    server.on("/wificredentials", HTTP_POST, [](AsyncWebServerRequest *request){
      int params = request->params();
      AsyncWebParameter *ssid = request->getParam(0);
      AsyncWebParameter *wifipassword = request->getParam(1);
      Serial.print("Number of params: ");
      Serial.println(params);
      Serial.print("SSID: ");
      Serial.println(ssid->value().c_str());
      Serial.print("Wifi password: ");
      Serial.println(wifipassword->value().c_str());
      AsyncWebServerResponse* response = request->beginResponse(LittleFS, "/captiverestart.htm", "text/html");
      request->send(response);
    });
      
  }
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    //request->addInterestingHeader("ANY");
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    //AsyncResponseStream *response = request->beginResponseStream("text/html");

    

    request->send(LittleFS,  "/captiveportal.htm", "text/html");
    
    /*
    response->print("<!DOCTYPE html><html><head><title>Captive Portal</title></head><body>");
    response->print("<p>This is out captive portal front page.</p>");
    response->printf("<p>You were trying to reach: http://%s%s</p>", request->host().c_str(), request->url().c_str());
    response->printf("<p>Try opening <a href='http://%s'>this link</a> instead</p>", WiFi.softAPIP().toString().c_str());
    response->print("</body></html>");
    */
    //request->send(response);
  }
};


void setup(){
  Serial.begin(115200);
  delay(5000);
  // Initialize SPIFFS
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  Serial.println("Starting...");

  Dir dir = LittleFS.openDir ("");
  while (dir.next ()) {
    Serial.println (dir.fileName ());
    //Serial.println (dir.fileSize ());
  }

  WiFi.softAP("brianLEDPanels");
  dnsServer.start(53, "*", WiFi.softAPIP());


  
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  server.begin();
}

void loop(){
  dnsServer.processNextRequest();
}
