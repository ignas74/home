#include <Arduino.h>

/*
- Reference – man būtinai reikia šio objekto.
- Pointer – galiu turėti šį objektą, bet galiu jo ir neturėti, arba norėti keisti, į kurį objektą rodau.
Dar viena detalė: pointeris nėra savaime blogesnis ar mažiau saugus. Jis tiesiog suteikia daugiau lankstumo, o kartu ir daugiau atsakomybės.
*/

#include "DisplayManager.h"
#include "ButtonManager.h"
#include "MenuManager.h"
#include "TemperatureSensor.h"
#include "UltrasonicSensor.h"
#include "PIRSensor.h"

ButtonManager buttonManager;
TemperatureSensor temperatureSensor;
UltrasonicSensor ultrasonicSensor;
PIRSensor pirSensor;
DisplayManager displayManager(temperatureSensor, ultrasonicSensor, pirSensor);
MenuManager menuManager(displayManager, buttonManager);

void setup()
{
  Serial.begin(115200);

  displayManager.initDisplay();
  displayManager.firstWindow();
  buttonManager.initButtons();
  temperatureSensor.begin();
  ultrasonicSensor.begin();
  pirSensor.begin();
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

  


  ultrasonicSensor.update();

  if (ultrasonicSensor.hasNewData())
  {
    if (menuManager.getCurrentIndex() == 2) // check if the current menu index is 1
    {
      displayManager.secondWindow(); // update the display with the latest temperature reading
    }
  }

  // Serial.println(ultrasonicSensor.measureDistance());


  pirSensor.update();

  if (menuManager.getCurrentIndex() == 3)
  {
      displayManager.thirdWindow();
  }


  // pirSensor.update();

  // if (pirSensor.hasNewData())
  // {
  //   if (menuManager.getCurrentIndex() == 3)
  //   {
  //     displayManager.thirdWindow();
  //   }
  // }
}
