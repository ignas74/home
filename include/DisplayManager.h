#pragma once

#include <Wire.h>
#include <Config.h>
#include <Adafruit_GFX.h>
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

public:
    DisplayManager(); // No need parameters as we are going to use Config.h
    ~DisplayManager();

    void initDisplay();
    void firstWindow();
    void secondWindow();
    void thirdWindow();
};