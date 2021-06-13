class Runner
{
  static const byte RECEIVED_SERIAL_SIZE = 32;

  private:
    char receivedChars[Runner::RECEIVED_SERIAL_SIZE];  
    bool recvInProgress = false;
    byte ndx = 0;
    char startMarker = '{';
    char endMarker = '}';
    bool newData = false;
    

  public:
    void handleSerialInput();
    void updatePanels();
};

void Runner::handleSerialInput()
{
  char rc;
  
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress) {
      if (rc != endMarker) {
          receivedChars[ndx] = rc;
          ndx++;
          if (ndx >= Runner::RECEIVED_SERIAL_SIZE) 
            ndx = Runner::RECEIVED_SERIAL_SIZE - 1;
                
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

void Runner::updatePanels()
{
   if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

Runner *runner;

void setup() {
  Serial.begin(115200);
  delay(5000);
  runner = new Runner();
}

void loop() {
  runner->handleSerialInput();
  runner->updatePanels();
}
