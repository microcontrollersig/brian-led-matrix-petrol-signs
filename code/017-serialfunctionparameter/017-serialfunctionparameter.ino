

void passSerialObjectAsParam(Stream &serial) 
{
  serial.println("This works just fine.");
}


void setup() {
  Serial.begin(115200);  
  delay(5000);
  passSerialObjectAsParam(Serial); 
}

void loop() {
  

}
