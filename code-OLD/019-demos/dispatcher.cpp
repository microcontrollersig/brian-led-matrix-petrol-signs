#pragma once
#include "dispatcher.h"

Dispatcher::Dispatcher(DMD3 *dmd)
{
  canvas = dmd;
  CommandList cl;
  commands = cl.registerCommands();
  movingcommands = cl.registerMovingCommands();
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
      bool *m = movingcommands + currentCommand;
      if (m != NULL && *m) {
        //Serial.print("Dispatch command:...");
        //Serial.println(currentCommand);
        dispatch(currentCommand);
      }
      //dispatch(currentCommand);
      //Serial.print("Dispatch command:...");
      //Serial.println(currentCommand);
   } 
    
  
}

void Dispatcher::parseSerialInput()
{
  char command = receivedChars[0];
  currentCommand = (int)command;
  commands[command]->execute(canvas);
}

void Dispatcher::dispatch(uint8_t command)
{
  commands[command]->execute(canvas);  
}
