#include "dispatcher.h"

Dispatcher::Dispatcher()
{
  Command *nothingCommand = new NullCommand();
  
  for (int i=0; i<255; i++) {
    commands.push_back(nothingCommand);
  }
  
  Test1Command *test1 = new Test1Command();
  commands['0'] = test1;
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
}

void Dispatcher::updatePanels()
{
   if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

void Dispatcher::dispatch(uint8_t command)
{
  commands[command]->execute();  
}
