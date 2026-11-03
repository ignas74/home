#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor()
    : TRIG_PIN(Config::TRIG_PIN),
      ECHO_PIN(Config::ECHO_PIN)
{
}

UltrasonicSensor::~UltrasonicSensor()
{
}

void UltrasonicSensor::begin()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

long UltrasonicSensor::measureDistance()
{
    // send a 10 microsecond pulse to the trigger pin
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // read the echo pin and calculate the distance
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2; // convert to centimeters

    return distance;
}
