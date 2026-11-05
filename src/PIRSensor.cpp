#include "PIRSensor.h"

PIRSensor::PIRSensor(/* args */)
    : outputPin(Config::OUTPUT_PIN)
{
}

PIRSensor::~PIRSensor()
{
}

void PIRSensor::begin()
{
    pinMode(outputPin, INPUT);
}

// void PIRSensor::readSensor()
// {
//     Serial.println(digitalRead(outputPin));
//     delay(500);
// }

void PIRSensor::readSensor()
{
    bool motionDetected = digitalRead(outputPin);

    if (motionDetected != pirState)
    {
        pirState = motionDetected;

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
