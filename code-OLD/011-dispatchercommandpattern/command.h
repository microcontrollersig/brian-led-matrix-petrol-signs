#pragma once

#include <Arduino.h>

class Command
{
  public:
    virtual void execute() = 0;
    void clearSerialMonitor() { Serial.print("\033[2J\033[H\033[?25l"); }
};

class NullCommand : public Command
{
  public:
    void execute() override { Serial.println("Running null command..."); }
};
