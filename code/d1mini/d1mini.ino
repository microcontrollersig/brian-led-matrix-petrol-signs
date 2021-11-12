#include <DNSServer.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
//#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESPAsyncTCP.h>
//#include <ESP8266mDNS.h>
#endif
#include "ESPAsyncWebServer.h"
#include <LittleFS.h>
#include <Ticker.h>
#include <AsyncJson.h>
#include <ArduinoJson.h>
#define WIFI_TIMEOUT 15000


//#define DEBUG 0
#define DEBUG 1 

#define debug_print(val) do { if (DEBUG) Serial.print(val); } while(0)
#define debug_println(val) do { if (DEBUG) Serial.println(val); } while(0)
#define update_ledmatrix_ipaddress(val) do { Serial.print("{I`"); Serial.print(val);Serial.println("}"); } while(0)
#define update_ledmatrix_command(val) do { Serial.print("{"); Serial.print(val);Serial.println("}"); } while(0)
#define update_ledmatrix_command_with_arg(command, arg1) do {Serial.print("{"); Serial.print(command);Serial.print("`");Serial.print(arg1);Serial.println("}"); } while(0)


DNSServer dnsServer;
AsyncWebServer server(80);
bool restartESP = false;
Ticker ticker;
ESP8266WiFiMulti wifiMulti;

void restartESPCallback() 
{
  ESP.restart();
}

class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {

   server.serveStatic("/css/", LittleFS, "/css/");
   server.serveStatic("/js/", LittleFS, "/js/");
   server.serveStatic("/fonts/", LittleFS, "/fonts/");
   server.serveStatic("/favicon.ico", LittleFS, "/favicon.ico");
   server.serveStatic("/games/", LittleFS, "/games/").setDefaultFile("index.html");
    
    server.on("/wificredentials", HTTP_POST, [](AsyncWebServerRequest *request){
      int params = request->params();
      AsyncWebParameter *ssid = request->getParam(0);
      AsyncWebParameter *wifipassword = request->getParam(1);
      AsyncWebParameter *ssid2 = request->getParam(2);
      AsyncWebParameter *wifipassword2 = request->getParam(3);
            
      debug_print("Number of params: ");
      debug_println(params);
      debug_print("SSID: ");
      debug_println(ssid->value().c_str());
      debug_print("Wifi password: ");
      debug_println(wifipassword->value().c_str());
      debug_print("SSID2: ");
      debug_println(ssid2->value().c_str());
      debug_print("Wifi password2: ");
      debug_println(wifipassword2->value().c_str());      
            
      File file = LittleFS.open("wifi.cfg", "w");
      file.print(ssid->value().c_str());
      file.print('\n');
      file.print(wifipassword->value().c_str());
      file.print('\n');  
      file.print(ssid2->value().c_str());
      file.print('\n');
      file.print(wifipassword2->value().c_str());
      file.print('\n');  
      file.close();        
      /*
      file.print(ssid->value().c_str());  
      file.print(',');
      file.print(wifipassword->value().c_str());       
      file.close();
      */
      
      AsyncWebServerResponse* response = request->beginResponse(LittleFS, "/captiverestart.htm", "text/html");
      request->send(response);
      ticker.attach(5, restartESPCallback);
    });

   server.on("/main", HTTP_GET, [](AsyncWebServerRequest *request){
         request->send(LittleFS,  "/index.htm", "text/html");
   });

   server.on("/command", HTTP_POST, [](AsyncWebServerRequest *request){
         int params = request->params();
         AsyncWebParameter *c = request->getParam(0);
         char command[100];
         strcpy(command,  c->value().c_str());
                
         debug_print("{");
         debug_print(*command);
 
         for (int i=1; i<params; i++) {
           debug_print("`");
           
           AsyncWebParameter *d = request->getParam(i);
           debug_print(d->value().c_str());
         }
     
         debug_print("}");
         debug_println();
    

         request->send(204);        
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
  // brightness
  update_ledmatrix_command_with_arg('B', brightness);
  update_ledmatrix_ipaddress("192.168.4.1"); 
}

void startWebServer() 
{
   server.serveStatic("/css/", LittleFS, "/css/");
   server.serveStatic("/js/", LittleFS, "/js/");
   server.serveStatic("/fonts/", LittleFS, "/fonts/");
   server.serveStatic("/favicon.ico", LittleFS, "/favicon.ico");
   server.serveStatic("/games/", LittleFS, "/games/").setDefaultFile("index.html");
  
   server.on("/command", HTTP_POST, [](AsyncWebServerRequest *request){
         int params = request->params();
         AsyncWebParameter *c = request->getParam(0);
         char command[100];
         strcpy(command,  c->value().c_str());
                
         debug_print("{");
         debug_print(*command);
 
         for (int i=1; i<params; i++) {
           debug_print("`");
           
           AsyncWebParameter *d = request->getParam(i);
           debug_print(d->value().c_str());
         }
     
         debug_print("}");
         debug_println();
    

         request->send(204);        
   });

   AsyncCallbackJsonWebHandler* handler = new AsyncCallbackJsonWebHandler("/homeassistant", [](AsyncWebServerRequest *request, JsonVariant &json) {
     { //scope JsonDocument so it releases its buffer
      JsonObject jsonObj = json.as<JsonObject>();  
      const char *command = jsonObj["command"];
      int argumentCount = jsonObj["argumentCount"];
      
      Serial.print("{");
      Serial.print(command);
      for (int i=0; i < argumentCount; i++) {
        const char *argument = jsonObj["arguments"][i];
        Serial.print("`");
        Serial.print(argument);
      }
      Serial.print("}");
      Serial.println();
      request->send(200);
     } 
   });
   server.addHandler(handler);
     
AsyncCallbackJsonWebHandler* settingsSubmitHandler = new AsyncCallbackJsonWebHandler("/settingsSubmit", [](AsyncWebServerRequest *request, JsonVariant &json) {
  
  
  if (request->method() == HTTP_POST) {
       DynamicJsonDocument doc(2048);
       doc["brightness"] = json["brightness"];
       doc["bootcommand"] = json["bootcommand"];
       doc["bootcommanddescription"] = json["bootcommanddescription"];

       String brightness = json["brightness"];
       update_ledmatrix_command_with_arg('B', brightness);
      
       File settingsFile = LittleFS.open("/settings.json", "w");
       serializeJson(json, settingsFile);
       request->send(200);  
       settingsFile.close();     
  }

  
  
});
   
   server.addHandler(settingsSubmitHandler);

   server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
     File settingsFile = LittleFS.open("/settings.json", "r");
     request->send(200, "application/json", settingsFile.readString());
     settingsFile.close();
   });

   server.on("/savedsettings", HTTP_GET, [](AsyncWebServerRequest *request) {
     File settingsFile = LittleFS.open("/settings.json", "r");
     request->send(settingsFile, "application/json", settingsFile.size());
     settingsFile.close();
   });

   server.on("/wifisettings", HTTP_GET, [](AsyncWebServerRequest *request) {
     File wifiFile = LittleFS.open("/wifi.cfg", "r"); 
     String ssid1 = wifiFile.readStringUntil('\n');
     String password1 = wifiFile.readStringUntil('\n');
     String ssid2 = wifiFile.readStringUntil('\n');
     String password2 = wifiFile.readStringUntil('\n');
     wifiFile.close();
     
     AsyncJsonResponse * response = new AsyncJsonResponse();
     JsonVariant& root = response->getRoot();
     root["ssid1"] = ssid1.c_str();
     root["password1"] = password1.c_str();
     root["ssid2"] = ssid2.c_str();
     root["password2"] = password2.c_str();
     response->setLength();
     request->send(response);
   });

    server.on("/wifisettings", HTTP_POST, [](AsyncWebServerRequest *request) {
         AsyncWebParameter *ssid1 = request->getParam(0);
         AsyncWebParameter *password1 = request->getParam(1);
         AsyncWebParameter *ssid2 = request->getParam(2);
         AsyncWebParameter *password2 = request->getParam(3);

         File settingsFile = LittleFS.open("/wifi.cfg", "w");

         settingsFile.print(ssid1->value().c_str());
         settingsFile.print('\n');
         settingsFile.print(password1->value().c_str());
         settingsFile.print('\n');
         settingsFile.print(ssid2->value().c_str());
         settingsFile.print('\n');
         settingsFile.print(password2->value().c_str());
         settingsFile.print('\n');
         
         settingsFile.close();  
         request->send(204);               
    });
  
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
     request->send(LittleFS,  "/index.htm", "text/html");
   });



   
   server.begin();

    debug_println("Web server started");
  

}

bool attemptWifiConnection()
{
  File f = LittleFS.open("wifi.cfg", "r");
  
  if (f.available() > 0) {
     String ssid = f.readStringUntil('\n');
     String password = f.readStringUntil('\n');
     String ssid2 = f.readStringUntil('\n');
     String password2 = f.readStringUntil('\n');
     wifiMulti.addAP(ssid.c_str(), password.c_str());
     wifiMulti.addAP(ssid2.c_str(), password2.c_str());
     if (wifiMulti.run(WIFI_TIMEOUT) == WL_CONNECTED) {
       Serial.print("WiFi connected: ");
       Serial.print(WiFi.SSID());
       Serial.print(" ");
       Serial.println(WiFi.localIP());
       f.close();
       return true;
     } else {
       Serial.println("WiFi not connected!");
       f.close();
       return false;
     }         
  }

  return false;
  
}

void send_bootcommand(const String& ipaddress) {
  File settingsFile = LittleFS.open("/settings.json", "r");
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, settingsFile);
  JsonObject root = doc.as<JsonObject>();
  String bootcommand = root["bootcommand"];
  String brightness = root["brightness"];
  update_ledmatrix_command_with_arg("B", brightness);
  if (bootcommand == "") {
    debug_print("IP Address: ");
    debug_println(ipaddress);
    update_ledmatrix_ipaddress(ipaddress);
  }

  else {
    update_ledmatrix_command(bootcommand);
  }

  settingsFile.close();
}

void wificonfig() 
{
  bool successfulWifiConnection = attemptWifiConnection();
  
  if (successfulWifiConnection) {
    debug_println("Successfully connected to wifi.");
    send_bootcommand(WiFi.localIP().toString());    
    startWebServer();
  }

  else {
    debug_println("Starting captive portal...");
    startCaptiveWebServer();           
  }

}

void setup(){
  Serial.begin(115200);
  delay(5000);
  if (DEBUG)
    Serial.println("Debugging ON."); 
  else
    Serial.println("Debugging OFF.");
  debug_println("begin wifi route...");
  
  if(!LittleFS.begin()){
    delay(5000);
    debug_println("An Error has occurred while mounting LittleFS. Did you forget to upload fs using ESP8266 LittleFS Data upload?");
    return;
  }

  if (!LittleFS.exists("wifi.cfg"))
  {
    delay(5000);
    debug_println("wifi.cfg does not exist. Did you forget to upload fs using ESP8266 LittleFS Data upload?"); 
    return;
  }

  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);

  wificonfig();
}

void loop(){
  if (restartESP) {
    restartESP = false;
    ESP.restart();  
  }
  dnsServer.processNextRequest();
}
