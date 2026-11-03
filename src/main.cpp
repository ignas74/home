#include <Arduino.h>

#include "DisplayManager.h"
#include "ButtonManager.h"
#include "MenuManager.h"
#include "TemperatureSensor.h"
#include "UltrasonicSensor.h"

ButtonManager buttonManager;
TemperatureSensor temperatureSensor;
DisplayManager displayManager(temperatureSensor);
MenuManager menuManager(displayManager, buttonManager);
UltrasonicSensor ultrasonicSensor;

void setup()
{
  Serial.begin(115200);

  displayManager.initDisplay();
  displayManager.firstWindow();
  buttonManager.initButtons();
  temperatureSensor.begin();
  ultrasonicSensor.begin();
}

void loop()
{
  // update button states and handle menu navigation
  buttonManager.update();
  menuManager.slide();

  // update temperature sensor readings
  temperatureSensor.update();

  if (temperatureSensor.hasNewData())
  {
    if (menuManager.getCurrentIndex() == 1) // check if the current menu index is 1
    {
      displayManager.firstWindow(); // update the display with the latest temperature reading
    }
  }
}
