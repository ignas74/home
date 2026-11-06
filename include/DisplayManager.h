#pragma once

#include <Adafruit_SH110X.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>

#include "Config.h"
#include "TemperatureSensor.h"
#include "UltrasonicSensor.h"
#include "PIRSensor.h"
#include "FaceAnimation.h"

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
    PIRSensor &pirSensor;
    Adafruit_SH1106G display;
    FaceAnimation faceAnimation;

public:
    DisplayManager(TemperatureSensor &tempSensor, UltrasonicSensor &ultraSensor, PIRSensor &pirSensor); // constructor with reference to TemperatureSensor

    void initDisplay();
    void firstWindow();
    void secondWindow();
    void thirdWindow();
};
