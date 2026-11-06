#pragma once

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

  void begin();
  void update();

  bool hasNewData();

  float getTemperature() const;
  float getHumidity() const;

  // float readTemperature();
  // float readHumidity();

  // void printTemperatureAndHumidity();
};
