#pragma once

#include "TemperatureSensor.h"
// #include <Wire.h>
#include <Config.h>
// #include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

class DisplayManager
{
private:
    int SDA_PIN;
    int SCL_PIN;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int OLED_RESET;
    Adafruit_SH1106G display;
    TemperatureSensor &temperatureSensor; // reference to the TemperatureSensor instance

    /*
    

    REIKES I MENUMANAGER
    // int currentWindowIndex = 0; // track the current window index
    
    */

public:
    DisplayManager(TemperatureSensor &tempSensor); // constructor with reference to TemperatureSensor
    ~DisplayManager();

    void initDisplay();
    void firstWindow();
    void secondWindow();
    void thirdWindow();
};