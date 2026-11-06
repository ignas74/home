#include "PIRSensor.h"

PIRSensor::PIRSensor()
    : outputPin(Config::OUTPUT_PIN),
      pirState(false),
      newDataAvailable(false)
{
}

void PIRSensor::begin()
{
    pinMode(outputPin, INPUT);
}

void PIRSensor::update()
{
    newDataAvailable = false;
    
    bool motionDetected = digitalRead(outputPin);

    if (motionDetected != pirState)
    {
        pirState = motionDetected;
        
        newDataAvailable = true;

        if (pirState)
        {
            Serial.println("Motion detected");
        }
        else
        {
            Serial.println("Motion ended");
        }
    }
}

bool PIRSensor::hasNewData()
{
    return newDataAvailable;
}

bool PIRSensor::getPirState()
{
    return pirState;
}


