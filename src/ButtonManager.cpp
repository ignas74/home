#include "ButtonManager.h"

/*
State – current state. Event – specific event about which other classes is informed

1. read GPIO
   digitalRead() returns LOW

2. check for change
   save the time to lastDebounceTime

3. waiting
    check if debounceDelay time has passed

4. confirm state
   stableState switched to LOW

5. register an event
   pressedEvent = true

6. isLeftPressed() or isRightPressed() returns true
*/

ButtonManager::ButtonManager()
{
    leftButton.pin = Config::LEFT_BUTTON_PIN;
    rightButton.pin = Config::RIGHT_BUTTON_PIN;
}

void ButtonManager::initButtons()
{
    /*
    INPUT_PULLUP reverse button logic to activate internal resistor which keeps GPIO at HIGH state until
    the button is not touching(pressed) GND. to prevent floating signal

    INPUT_PULLUP is reverse logic. pressed button = 0, released button = 1
    */

    pinMode(leftButton.pin, INPUT_PULLUP);
    pinMode(rightButton.pin, INPUT_PULLUP);

    /*
    lastReading	        previously readed state (signal)
    stableState	        confirms button state (signal)
    pressedEvent	    IS there a new registered event?
    lastDebounceTime	when was the last electrical state change
    */

    leftButton.lastReading = HIGH;
    leftButton.stableState = HIGH;
    leftButton.pressedEvent = false;
    leftButton.lastDebounceTime = 0;

    rightButton.lastReading = HIGH;
    rightButton.stableState = HIGH;
    rightButton.pressedEvent = false;
    rightButton.lastDebounceTime = 0;
}

/*
Button &button reference to an existing object

updateButton() checks if the signal has changed and if it stays same long enough
other words check: CONTACT BOUNCE
*/

void ButtonManager::updateButton(Button &button)
{
    /*
    digitalRead()   = read GPIO state
    button.pin      = which GPIO to read
    reading         == HIGH || LOW   ( 1 || 0 )
    */

    bool reading = digitalRead(button.pin);

    /*
    reading == HIGH -> button is NOT pressed.
    reading == LOW  -> button IS pressed.

    if the current reading differs from the previous reading:
        save the current time (millis)
        update lastReading with the new state

    detects a signal change and resets the debounce timer.
    it does not confirm a button press.
    */

    if (reading != button.lastReading)
    {
        button.lastDebounceTime = millis();
        button.lastReading = reading;
    }

    /*
    checks whether the signal has remained unchanged
    for at least debounceDelay milliseconds.

    for example debounceDelay = 50
    since the last change = 20. therefore function won't continue
    */

    if (millis() - button.lastDebounceTime >= debounceDelay)
    {
        if (reading != button.stableState)
        {
            // update the confirmed button state after debounce period.

            button.stableState = reading;

            // THERE. register a new event (pressed)

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
