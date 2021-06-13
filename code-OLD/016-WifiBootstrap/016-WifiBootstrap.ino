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
#include <Ticker.h>
#define WIFI_TIMEOUT 10000

DNSServer dnsServer;
AsyncWebServer server(80);
bool restartESP = false;
Ticker ticker;

void restartESPCallback() 
{
  ESP.restart();
}

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
      File file = LittleFS.open("wifi.cfg", "w");
      
      file.print(ssid->value().c_str());  
      file.print(',');
      file.print(wifipassword->value().c_str());
       
      file.close();
      AsyncWebServerResponse* response = request->beginResponse(LittleFS, "/captiverestart.htm", "text/html");
      request->send(response);
      ticker.attach(5, restartESPCallback);
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
    // Captive portal is at: 192.168.4.1
    //request->send(response);
  }
};



void startCaptiveWebServer()
{
  WiFi.softAP("brianLEDPanels");
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  server.begin();  
}

void startWebServer() 
{
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
         request->send(LittleFS,  "/index.htm", "text/html");
   });
   
   server.begin();
}

void parseWifiCfg(char *ssid, char *password)
{
  File f = LittleFS.open("wifi.cfg", "r");
  if (f.available() > 0) {
     f.readBytesUntil(',', ssid, 100);
 
  }
  int i;
  for (i=0; f.available() > 0 ; i++) {
    password[i] = f.read();
  }
  password[i] = 0;
  f.close();
}

void wificonfig() 
{
  Dir dir = LittleFS.openDir ("");
  while (dir.next()) {
    if (dir.fileName() == "wifi.cfg"){
      if (dir.fileSize() == 0) {
        Serial.println("Starting captive portal...");
        startCaptiveWebServer();        
      }

      else {
        char ssid[100], password[100];
        Serial.println("Attempting to parse wifi.cfg ...");
        parseWifiCfg(ssid, password);
        Serial.print("SSID retrieved from wifi.cfg:");
        Serial.println(ssid);
        Serial.print("password retrieved from wifi.cfg:");
        Serial.println(password);
        Serial.println("Attempting to connect to wifi...");
        WiFi.begin(ssid,password);
        WiFi.waitForConnectResult(WIFI_TIMEOUT);
        if (WiFi.status() == WL_CONNECTED) {
          Serial.println("Successfully connected to wifi.");
          Serial.print("IP Address: ");
          Serial.println(WiFi.localIP());
          startWebServer();
        }

        else {
          Serial.println("Couldn't connect to wifi. Starting Soft AP.");
          startCaptiveWebServer();
        } 
               
      }
    }
  }
}


void setup(){
  Serial.begin(115200);
  delay(5000);
  Serial.println("begin wifi route...");
  // Initialize SPIFFS
  if(!LittleFS.begin()){
    delay(5000);
    Serial.println("An Error has occurred while mounting LittleFS. Did you forget to upload fs using ESP8266 LittleFS Data upload?");
    return;
  }

  if (!LittleFS.exists("wifi.cfg"))
  {
   delay(5000);
   Serial.println("wifi.cfg doest not exist. Did you forget to upload fs using ESP8266 LittleFS Data upload?"); 
    return;
  }

  wificonfig();
}

void loop(){
  if (restartESP) {
    restartESP = false;
    ESP.restart();  
  }
  dnsServer.processNextRequest();
}
