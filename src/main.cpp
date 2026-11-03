#include <Arduino.h>

#include "DisplayManager.h"
#include "ButtonManager.h"
#include "MenuManager.h"
#include "TemperatureSensor.h"

ButtonManager buttonManager;
TemperatureSensor temperatureSensor;
DisplayManager displayManager(temperatureSensor);
MenuManager menuManager(displayManager, buttonManager);

void setup()
{
  Serial.begin(115200);
  
  displayManager.initDisplay();
  displayManager.firstWindow();
  buttonManager.initButtons();
  temperatureSensor.begin(); 

}


void loop()
{
  // update button states and handle menu navigation
  buttonManager.update();
  menuManager.slide();

  // update temperature sensor readings
  temperatureSensor.update();

  // if new temperature data is available, update the display and print to Serial
  if (temperatureSensor.hasNewData())
  {
      displayManager.firstWindow(); // update the display with the latest temperature reading
      // temperatureSensor.printTemperatureAndHumidity(); 
  }
}