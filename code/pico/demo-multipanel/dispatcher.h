#pragma once

#include <Arduino.h>
#include <vector>
#include <iostream>
#include <sstream>
#include "command.h"
#include "commandlist.h"
#include "DMD3.h"

class Dispatcher
{
  static const byte RECEIVED_SERIAL_SIZE = 200;

  private:
    std::vector<Command*> commands;
    char receivedChars[Dispatcher::RECEIVED_SERIAL_SIZE]; 
    int receivedCharsCount=0; 
    bool recvInProgress = false;
    uint8_t ndx = 0;
    char startMarker = '{';
    char endMarker = '}';
    bool newData = false;
    DMD3 *canvas;
    int currentCommand = -1;
    std::vector<std::string> split(const std::string &s, char delim);

  public:
    Dispatcher(DMD3 *dmd);
    void dispatch(uint8_t command);
    void handleSerialInput(Stream& s);
    void parseSerialInput();
    void updatePanels();
};
