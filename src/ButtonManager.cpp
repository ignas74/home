#include "ButtonManager.h"

/*
lastReading	        last readed state
stableState	        confirms button state
pressedEvent	    is there a new registered event
lastDebounceTime	when was the last electrical state change
*/

// ButtonManager::ButtonManager(int left_pin, int right_pin)
// {
//     leftButton.pin = left_pin;
//     rightButton.pin = right_pin;
// }

ButtonManager::ButtonManager()
{
    leftButton.pin = Config::LEFT_BUTTON_PIN;   // Priskiriame reikšmę tiesiogiai į struktūros vidų
    rightButton.pin = Config::RIGHT_BUTTON_PIN; // Lygiai taip pat kairiam/dešiniam
}

void ButtonManager::initButtons()
{
    pinMode(leftButton.pin, INPUT_PULLUP);
    pinMode(rightButton.pin, INPUT_PULLUP);

    leftButton.lastReading = HIGH;
    leftButton.stableState = HIGH;
    leftButton.pressedEvent = false;
    leftButton.lastDebounceTime = 0;

    rightButton.lastReading = HIGH;
    rightButton.stableState = HIGH;
    rightButton.pressedEvent = false;
    rightButton.lastDebounceTime = 0;
}

void ButtonManager::updateButton(Button &button)
{
    bool reading = digitalRead(button.pin);

    if (reading != button.lastReading)
    {
        button.lastDebounceTime = millis();
        button.lastReading = reading;
    }

    if (millis() - button.lastDebounceTime >= debounceDelay)
    {
        if (reading != button.stableState)
        {
            button.stableState = reading;

            if (button.stableState == LOW)
            {
                button.pressedEvent = true;
            }
        }
    }
}

void ButtonManager::update()
{
    updateButton(leftButton);
    updateButton(rightButton);
}

bool ButtonManager::isLeftPressed()
{
    if (leftButton.pressedEvent)
    {
        leftButton.pressedEvent = false;
        return true;
    }

    return false;
}

bool ButtonManager::isRightPressed()
{
    if (rightButton.pressedEvent)
    {
        rightButton.pressedEvent = false;
        return true;
    }

    return false;
}

// ButtonManager::~ButtonManager() {} 
