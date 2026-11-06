#pragma once

#include <Adafruit_SH110X.h>

class FaceAnimation
{
private:
    uint16_t frameIdx;
    unsigned long lastMs;
    Adafruit_SH1106G &display;

public:
    FaceAnimation(Adafruit_SH1106G &display);

    void update();
};