#pragma once

#include "command.h"

class TestDebugCommand : public Command
{  
  public:
    void parseArgs(std::vector<std::string> args) override {
      char c = args.at(0)[0];
      DEBUG = c - '0';
    }
    bool noExecute(DMD3 *canvas) override { return true; }
    void execute(DMD3 *canvas)  override {
    }
};
