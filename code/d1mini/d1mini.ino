#include <DNSServer.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
//#include <ESP8266mDNS.h>
#endif
#include "ESPAsyncWebServer.h"
#include <LittleFS.h>
#include <Ticker.h>
#include <AsyncJson.h>
#include <ArduinoJson.h>
#define WIFI_TIMEOUT 10000


//#define DEBUG 0
#define DEBUG 1 

#define debug_print(val) do { if (DEBUG) Serial.print(val); } while(0)
#define debug_println(val) do { if (DEBUG) Serial.println(val); } while(0)
#define update_ledmatrix_text(val) do { Serial.print("{I`"); Serial.print(val);Serial.println("}"); } while(0)

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
            
      debug_print("Number of params: ");
      debug_println(params);
      debug_print("SSID: ");
      debug_println(ssid->value().c_str());
      debug_print("Wifi password: ");
      debug_println(wifipassword->value().c_str());
            
      File file = LittleFS.open("wifi.cfg", "w");      
      file.print(ssid->value().c_str());  
      file.print(',');
      file.print(wifipassword->value().c_str());       
      file.close();
      
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
  update_ledmatrix_text("192.168.4.1"); 
}

void startWebServer() 
{
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
   
   
   server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
     request->send(LittleFS,  "/settings.htm", "text/html");   
   });

   
   server.on("/settings", HTTP_POST, [](AsyncWebServerRequest *request) { 
      request->send(200);
   }, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {        
        if (index == 0) {
          request->_tempObject = new char[len + 1];
          char* tempObject = (char *)request->_tempObject;
          
          for (int i=0; i<len; i++) {
            tempObject[i] = (char)data[i];
          }

          tempObject[len] = '\0';
          
          //Serial.println(tempObject);
          DynamicJsonDocument doc(1024);
          deserializeJson(doc, tempObject);
          File settingsFile = LittleFS.open("/settings.json", "w");
          serializeJson(doc, settingsFile);
          settingsFile.close();
          
        }

        else {
          Serial.println("It gets here");
        }
  });
 
   /*
   AsyncCallbackJsonWebHandler* settingsHandler = new AsyncCallbackJsonWebHandler("/settings", [](AsyncWebServerRequest *request, JsonVariant &json) {
     debug_println("We got here!");
     if (request->method() == HTTP_GET) {
       request->send(LittleFS,  "/settings.htm", "text/html"); 
     }

     else if (request->method() == HTTP_POST) {
       File settingsFile = LittleFS.open("/settings.json", "w");
       serializeJson(json, settingsFile);
       settingsFile.close();
       request->send(200);     
     }
   });
   server.setMethod(HTTP_ANY);
   server.addHandler(settingsHandler);
   */

   server.on("/savedsettings", HTTP_GET, [](AsyncWebServerRequest *request) {
     File settingsFile = LittleFS.open("/settings.json", "r");
     request->send(settingsFile, "application/json", settingsFile.size());
     /*settingsFile.close();*/
     /*
  
     std::unique_ptr<char[]> buf(new char[settingsFileSize]);
     settingsFile.readBytes(buf.get(), settingsFileSize);
     settingsFile.close();
     request->send(200, "application/json", buf.get());
     */

     /*
     StaticJsonDocument<512> doc;
     deserializeJson(doc, settingsFile);
     settingsFile.close();
     */
     /*JsonObject root = doc.as<JsonObject>();*/
     
     /*
     AsyncJsonResponse * response = new AsyncJsonResponse();
     response->addHeader("Server","ESP Async Web Server");
     JsonVariant& jsonObj = response->getRoot();

     jsonObj["brightness"] = root["brightness"];
     jsonObj["bootcommand"] = root["bootcommand"];

     response->setLength();
     request->send(response);
     */
   });
  
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
     request->send(LittleFS,  "/index.htm", "text/html");
   });



   
   server.begin();

    debug_println("Web server started");
  

}

void parseWifiCfg(char *ssid, char *password)
{
  File f = LittleFS.open("wifi.cfg", "r");
  
  if (f.available() > 0) {
     size_t bytesRead = f.readBytesUntil(',', ssid, 100);
     ssid[bytesRead] = '\0';
     //debug_print("ssid byte count:");
     //debug_println(bytesRead);
  }
  
  int i;
  for (i=0; f.available() > 0 ; i++) {
    password[i] = f.read();
  }
  password[i] = '\0';
  f.close();
}

void wificonfig() 
{
  Dir dir = LittleFS.openDir ("");
  while (dir.next()) {
    if (dir.fileName() == "wifi.cfg"){
      if (dir.fileSize() == 0) {
        debug_println("Starting captive portal...");
        startCaptiveWebServer();        
      }

      else {
        char ssid[100], password[100];
        debug_println("Attempting to parse wifi.cfg ...");
        parseWifiCfg(ssid, password);
        debug_print("SSID retrieved from wifi.cfg:");
        debug_println(ssid);
        debug_print("password retrieved from wifi.cfg:");
        debug_println(password);
        debug_println("Attempting to connect to wifi...");
        WiFi.begin(ssid,password);
        WiFi.waitForConnectResult(WIFI_TIMEOUT);
        if (WiFi.status() == WL_CONNECTED) {
          debug_println("Successfully connected to wifi.");
          debug_print("IP Address: ");
          debug_println(WiFi.localIP());
          update_ledmatrix_text(WiFi.localIP().toString());
          startWebServer();
          /*
          if (!MDNS.begin("brian")) {
            debug_println("Error setting up MDNS responder!");
            while(1) {
              delay(1000);
            }
           }
          debug_println("mDNS responder started");
          // Add service to MDNS-SD
          MDNS.addService("http", "tcp", 80);
          */
        }

        else {
          debug_println("Couldn't connect to wifi. Starting Soft AP.");
          File file = LittleFS.open("wifi.cfg", "w");  
          file.close();
          startCaptiveWebServer();
        } 
               
      }
    }
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
  // Initialize SPIFFS
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

  wificonfig();
}

void loop(){
  if (restartESP) {
    restartESP = false;
    ESP.restart();  
  }
  dnsServer.processNextRequest();
}
