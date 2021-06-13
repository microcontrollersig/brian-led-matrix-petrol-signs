#pragma once

#include <Arduino.h>
#include "command.h"
#include "commandlist.h"

class Dispatcher
{
  static const byte RECEIVED_SERIAL_SIZE = 32;

  private:
    std::vector<Command*> commands;
    char receivedChars[Dispatcher::RECEIVED_SERIAL_SIZE];  
    bool recvInProgress = false;
    uint8_t ndx = 0;
    char startMarker = '{';
    char endMarker = '}';
    bool newData = false;
    

  public:
    Dispatcher();
    void dispatch(uint8_t command);
    void handleSerialInput();
    void updatePanels();
};
