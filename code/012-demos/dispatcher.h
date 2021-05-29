#pragma once

#include <Arduino.h>
#include "command.h"
#include "commandlist.h"
#include "DMD3.h"

class Dispatcher
{
  static const byte RECEIVED_SERIAL_SIZE = 32;

  private:
    std::vector<Command*> commands;
    bool *movingcommands;
    char receivedChars[Dispatcher::RECEIVED_SERIAL_SIZE];  
    bool recvInProgress = false;
    uint8_t ndx = 0;
    char startMarker = '{';
    char endMarker = '}';
    bool newData = false;
    DMD3 *canvas;
    int currentCommand = -1;

  public:
    Dispatcher(DMD3 *dmd);
    void dispatch(uint8_t command);
    void handleSerialInput();
    void parseSerialInput();
    void updatePanels();
};
