#include <Arduino.h>
#include <FunctionalInterrupt.h>

#define BUTTON1 D7
#define BUTTON2 D6

class Button
{
public:
    Button(uint8_t reqPin) : PIN(reqPin){
        numberKeyPresses = 0;
        attachInterrupt(PIN, std::bind(&Button::isr,this), FALLING);
        
    };
    ~Button() {
        detachInterrupt(PIN);
    }

    void destroy() {
      detachInterrupt(PIN);
    }

    void IRAM_ATTR isr() {
        numberKeyPresses += 1;
        pressed = true;
    }

    volatile uint32_t numberKeyPresses;

private:
    const uint8_t PIN;
    
    volatile bool pressed;
};

  Button b(BUTTON1);

void setup() {
  pinMode(BUTTON1, OUTPUT);
  digitalWrite(BUTTON1, LOW);
  delay(1000);

  analogWrite(BUTTON1, 1023/2);

}

void loop() {
  if (b.numberKeyPresses >= 16) {
    b.destroy();  
    digitalWrite(BUTTON1, LOW);
  }


}
