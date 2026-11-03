#pragma once

#include <Arduino.h>
#include <DHT.h>
#include "Config.h"

class TemperatureSensor
{
private:
    DHT dht;
    float currentTemperature;
    float currentHumidity;
    unsigned long lastMillis;
    const unsigned long interval = 2000; // update every 2 seconds
    bool newDataAvailable;

public:
    TemperatureSensor();
    ~TemperatureSensor();

    void begin();
    void update();

    bool hasNewData();

    float readTemperature();
    float readHumidity();

    float getTemperature() const;
    float getHumidity() const;

    void printTemperatureAndHumidity(); 
};
