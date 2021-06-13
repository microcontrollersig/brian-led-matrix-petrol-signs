#pragma once
#include "dispatcher.h"

Dispatcher::Dispatcher(DMD3 *dmd)
{
  canvas = dmd;
  CommandList cl;
  commands = cl.registerCommands();
}

void Dispatcher::handleSerialInput()
{
  char rc;
  
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

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
  
}

void Dispatcher::parseSerialInput()
{
  char command = receivedChars[0];
  commands[command]->execute(canvas);
}

void Dispatcher::dispatch(uint8_t command)
{
  commands[command]->execute(canvas);  
}
