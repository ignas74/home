#pragma once

#include <Arduino.h>
#include "Config.h"

class UltrasonicSensor
{
private:
    int TRIG_PIN;
    int ECHO_PIN;
public:
    UltrasonicSensor();
    ~UltrasonicSensor();
    void begin();
    // long getDistance();
    long measureDistance();
};
