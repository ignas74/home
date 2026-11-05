#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
    : dht(Config::DHT_PIN, Config::DHT_TYPE),
      currentTemperature(0.0),
      currentHumidity(0.0),
      lastMillis(0),
      newDataAvailable(false)
{
}

TemperatureSensor::~TemperatureSensor()
{
}

void TemperatureSensor::begin()
{
    dht.begin();
}

void TemperatureSensor::update()
{
    newDataAvailable = false; // reset the flag at the start of each update cycle
    unsigned long currentMillis = millis();

    if (currentMillis - lastMillis >= interval)
    {
        lastMillis = currentMillis;

        float temp = dht.readTemperature();
        float hum = dht.readHumidity();

        if (!isnan(temp))
        {
            currentTemperature = temp;
            newDataAvailable = true; // set flag
        }
        if (!isnan(hum))
        {
            currentHumidity = hum;
        }
    }
}

bool TemperatureSensor::hasNewData()
{
    return newDataAvailable;
}

float TemperatureSensor::getTemperature() const
{
    return currentTemperature;
}

float TemperatureSensor::getHumidity() const
{
    return currentHumidity;
}

float TemperatureSensor::readTemperature()
{
    return dht.readTemperature();
}

float TemperatureSensor::readHumidity()
{
    return dht.readHumidity();
}

// void TemperatureSensor::printTemperatureAndHumidity()
// {
//     float temperature = readTemperature();
//     float humidity = readHumidity();

//     if (isnan(temperature) || isnan(humidity))
//     {
//         Serial.println("DHT11 failed to launch");
//         return;
//     }

//     Serial.print("Temperature: ");
//     Serial.print(temperature);
//     Serial.print(" C   |   Humidity: ");
//     Serial.print(humidity);
//     Serial.println(" %");
// }