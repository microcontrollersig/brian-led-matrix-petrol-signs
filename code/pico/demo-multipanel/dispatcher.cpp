#pragma once
#include "dispatcher.h"

Dispatcher::Dispatcher(DMD3 *dmd)
{
  canvas = dmd;
  CommandList cl;
  commands = cl.registerCommands();
}

void Dispatcher::handleSerialInput(Stream& serial)
{
  char rc;
  
  while (serial.available() > 0 && newData == false) {
    rc = serial.read();

    if (recvInProgress) {
      if (rc != endMarker) {
          receivedChars[ndx] = rc;
          ndx++;
          if (ndx >= Dispatcher::RECEIVED_SERIAL_SIZE) 
            ndx = Dispatcher::RECEIVED_SERIAL_SIZE - 1;
                
        }
        else {
          receivedChars[ndx] = '\0'; // terminate the string
          recvInProgress = false;
          receivedCharsCount = ndx;
          ndx = 0;
          newData = true;
        }        
      }
      else if (rc == startMarker) {
        recvInProgress = true;
      }
  }

   if (newData == true) {
        newData = false;
        parseSerialInput();
   }

   
   else if (currentCommand > 0 ) {
        dispatch(currentCommand);      
   } 
    
  
}

std::vector<std::string> Dispatcher::split(const std::string &s, char delim)
{
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while ( getline(ss, item, delim) ) 
    result.push_back(item);

  return result;
}

void Dispatcher::parseSerialInput()
{
  char command = receivedChars[0];  
  //currentCommand = (int)command;
  if (receivedCharsCount >= 2) {
    std::vector<std::string> v = split(std::string(receivedChars), '`');
    v.erase(v.begin());
    int len = v.size();
    //Serial.println((size_t) len);
    commands[command]->parseArgs(v);
  }

  receivedCharsCount = 0;  
  dispatch(command);
  //commands[command]->execute(canvas);
}

void Dispatcher::dispatch(uint8_t command)
{
  if (commands[command]->noExecute(canvas)) 
    return;
    
  currentCommand = (int)command;
  commands[command]->execute(canvas);  
}
