#pragma once

#include <Arduino.h>

class ButtonManager
{
private:
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
    ButtonManager(int left_pin, int right_pin);

    void initButtons();
    void update();

    bool isLeftPressed();
    bool isRightPressed();
};
