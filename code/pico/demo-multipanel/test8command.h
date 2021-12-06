#pragma once

#include "command.h"
#include "FlashIAPBlockDevice.h"
#include "KVStore.h"
#include "TDBStore.h"

class Test8Command : public Command
{  
  private:
    unsigned long timeStart = 0UL;
  
  public:
   void testing() {
      FlashIAPBlockDevice bd(XIP_BASE + 1024*1024, 1024*512);
      mbed::TDBStore eeprom(&bd);
      //char* data = "quitealongstring";
      int data[24];
      data[0] = 12;
      data[1] = 1;
      eeprom.init();
      mbed::KVStore::info_t info;
      int ram_buffer[24];
      int width;
      int height;
      const char* keystorename = "mydata4";

  if (eeprom.get_info(keystorename, &info) != MBED_ERROR_ITEM_NOT_FOUND) {
    Serial.println("Key size: " + String(info.size));
        eeprom.get(keystorename, ram_buffer, info.size);
        width = ram_buffer[0];
        height = ram_buffer[1];
    Serial.print("Width: ");
    Serial.println(width);
    Serial.print("Height: ");
    Serial.println(height);    
    //Serial.println((char*)ram_buffer);
  } else {
    Serial.println("Setting data.");
    eeprom.reset();
    eeprom.set(keystorename, data, sizeof(data), 0);
  }    
   }

    void displayPanelSize() {
      FlashIAPBlockDevice bd(XIP_BASE + 1024*1024, 1024*512);
      mbed::TDBStore eeprom(&bd);
      eeprom.init();
      mbed::KVStore::info_t info;
      int ram_buffer[24];
      int width;
      int height;
      const char* keystorename = "panelsize";

  if (eeprom.get_info(keystorename, &info) != MBED_ERROR_ITEM_NOT_FOUND) {
    Serial.println("Key size: " + String(info.size));
        eeprom.get(keystorename, ram_buffer, info.size);
        width = ram_buffer[0];
        height = ram_buffer[1];
    Serial.print("Width: ");
    Serial.println(width);
    Serial.print("Height: ");
    Serial.println(height);    

  } else {
    Serial.println("Panel size not set in emulated EEPROM");
  }    
      
    }
  
    void execute(DMD3 *canvas)  override {
      if (millis() - timeStart > 5000) {
      //clearSerialMonitor();
      Serial.print("DEBUG:");
      Serial.print(DEBUG);
      Serial.print(" TIMEOUT:");
      Serial.print(TIMEOUT);
      Serial.print(" BRIGHTNESS:");
      Serial.print(canvas->getBrightness());            
      Serial.println();
      displayPanelSize();
      //testing();
      //canvas->clear();
      //printCanvas(canvas);
      //canvas->update();
      timeStart = millis();
      }
    }
};
