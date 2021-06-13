#pragma once

#include <Arduino.h>
#include "DMD3.h"

class Command
{
  public:
    virtual void execute(DMD3 *canvas) = 0;
    void clearSerialMonitor() { Serial.print("\033[2J\033[H\033[?25l"); }
    void printCanvas(DMD3 *canvas)
    {
      char buf[100];
      for (int i=0; i < 16; i++) {
      canvas->debugPixelLine(i, buf);
      Serial.println(buf);    
      }
    }
};

class NullCommand : public Command
{
  public:
    void execute(DMD3 *canvas) override { Serial.println("Running null command..."); }
};
