#pragma once

#include <sstream>
#include "command.h"


class TestBrightnessCommand : public Command
{
  private:
    int brightness;
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss;
      ss << args.at(0);
      ss >> brightness;
      brightness = 255 - brightness;
    }
    bool noExecute(DMD3 *canvas) override { 
      canvas->setBrightness(brightness);
      return true; 
    }
    void execute(DMD3 *canvas)  override {
    }
};
