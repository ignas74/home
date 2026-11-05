#pragma once

#include <Arduino.h>
#include "Config.h"

class UltrasonicSensor
{
private:
    int trigPin;
    int echoPin;
    unsigned long lastMillis;
    const unsigned long interval = 200; // atnaujinimo intervalas (ms)
    bool newDataAvailable;
    long currentDistance;

public:
    UltrasonicSensor();
    ~UltrasonicSensor();

    void begin();
    void update();
    bool hasNewData() const;
    long getDistance() const;
};