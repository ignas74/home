#pragma once

#include <Arduino.h>

#include "Config.h"

class PIRSensor
{
private:
    int outputPin;
    bool pirState = false;

public:
    PIRSensor(/* args */);
    ~PIRSensor();

    void begin();
    void readSensor();
};

/*
int ledPin = D7;                 // Argon's onboard LED
int inputPin = D2;               // Sensor input
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      Serial.println("Motion detected!"); // Only show message on change
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      Serial.println("Motion ended!");   // Only show message on change
      pirState = LOW;
    }
  }
}
*/