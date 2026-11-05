#pragma once

#include <Adafruit_SH110X.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>

#include <Config.h>
#include "TemperatureSensor.h"
#include "UltrasonicSensor.h"

class DisplayManager
{
private:
    int sdaPin;
    int sclPin;
    int screenWidth;
    int screenHeight;
    int oledReset;
    TemperatureSensor &temperatureSensor; // reference to the TemperatureSensor instance
    UltrasonicSensor &ultrasonicSensor;
    Adafruit_SH1106G display;

public:
    DisplayManager(TemperatureSensor &tempSensor, UltrasonicSensor &ultraSensor); // constructor with reference to TemperatureSensor
    ~DisplayManager();

    void initDisplay();
    void firstWindow();
    void secondWindow();
    void thirdWindow();

    // int getCurrentWindowIndex() const;
    // int setCurrentWindowIndex(int index);
};
