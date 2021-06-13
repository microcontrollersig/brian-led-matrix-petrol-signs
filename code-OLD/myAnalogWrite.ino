#pragma once
#include <Arduino.h>

#include "pins_arduino.h"
#include "pinDefinitions.h"



void myAnalogWrite(pin_size_t pin, int val)
{
    int write_resolution = 8;
    mbed::PwmOut* pwm = new mbed::PwmOut(digitalPinToPinName(pin));
    //pwm->period_ms(2); //500Hz
    pwm->period_us(10); //100kHz
    float percent = (float)val/(float)((1 << write_resolution)-1);
    pwm->write(percent);
}

void setup() {
  delay(1000);
  pinMode(2, OUTPUT);
  myAnalogWrite(2, 127);
}

void loop() {
  delay(500);
}
