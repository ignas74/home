#pragma once

#include <Arduino.h>

#include "Config.h"

class ButtonManager
{
private:
    // struct because left and right buttons share the same variables.
    // i could do leftPin, rightPin. but there's consider 4-5 buttons
    
    struct Button
    {
        int pin;

        bool lastReading;
        bool stableState;
        bool pressedEvent;

        unsigned long lastDebounceTime;
    };

    Button leftButton;
    Button rightButton;

    const unsigned long debounceDelay = 50;

    void updateButton(Button &button);

public:
    ButtonManager();

    void initButtons();
    void update();

    bool isLeftPressed();
    bool isRightPressed();
};
