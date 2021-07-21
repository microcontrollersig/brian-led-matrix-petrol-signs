#pragma once

#include <Arduino.h>
#include "DMD3.h"
#include "debug.h"
#include "customglcdfonts.h"
#include "timeout.h"
#include <vector>
#include <sstream>

class Command
{
  public:
    virtual void execute(DMD3 *canvas) = 0;
    void clearSerialMonitor() { 
      if (DEBUG)
        Serial.print("\033[2J\033[H\033[?25l");       
    }
    void printCanvas(DMD3 *canvas)
    {
      if (DEBUG)
      {
        char buf[100];
        for (int i=0; i < 32; i++) 
        {
          canvas->debugPixelLine(i, buf);
          Serial.println(buf);    
        }
      } 
    }
    virtual void parseArgs(std::vector<std::string> args) {}
    virtual bool noExecute(DMD3 *canvas = NULL) { return false; }
};

class NullCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas) override {
      if ( millis() - timeStart > 1000) {   
        Serial.println("Running null command...");
        timeStart = millis();
      } 
    }
};
