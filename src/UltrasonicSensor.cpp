#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor()
    : trigPin(Config::TRIG_PIN),
      echoPin(Config::ECHO_PIN),
      lastMillis(0),
      newDataAvailable(false),
      currentDistance(0)
{
}

UltrasonicSensor::~UltrasonicSensor()
{
}

void UltrasonicSensor::begin()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void UltrasonicSensor::update()
{
    newDataAvailable = false;
    unsigned long currentMillis = millis();

    if (currentMillis - lastMillis >= interval)
    {
        lastMillis = currentMillis;

        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        long duration = pulseIn(echoPin, HIGH);
        currentDistance = duration * 0.034 / 2;

        newDataAvailable = true;
    }
}

bool UltrasonicSensor::hasNewData() const
{
    return newDataAvailable;
}

long UltrasonicSensor::getDistance() const
{
    return currentDistance;
}