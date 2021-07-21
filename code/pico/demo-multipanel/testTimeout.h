#pragma once

#include <sstream>
#include "command.h"


class TestTimeoutCommand : public Command
{
  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss;
      ss << args.at(0);
      ss >> TIMEOUT;
      //Serial.println(TIMEOUT);
      //Serial.println(ss.str().c_str());
    }
    bool noExecute(DMD3 *canvas) override { return true; }
    void execute(DMD3 *canvas)  override {
    }
};
