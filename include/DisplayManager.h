#pragma once
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

class DisplayManager
{
    private:
    int SDA_PIN; // 18
    int SCL_PIN; // 19
    int SCREEN_WIDTH = 128;
    int SCREEN_HEIGHT = 64;
    int OLED_RESET = -1;
    Adafruit_SH1106G display;
public:
    DisplayManager(int sda_pin, int scl_pin); // for starter variables
    ~DisplayManager();

    // void set_SDA_PIN(int a);
    // int get_SDA_PIN() const;

    void initDisplay();
    void firstWindow();
    void secondWindow();
    void thirdWindow();
};