#include <Arduino.h>

#include "DisplayManager.h"
#include "ButtonManager.h"
#include "MenuManager.h"

DisplayManager displayManager;
ButtonManager buttonManager;
MenuManager menuManager(displayManager, buttonManager);

void setup()
{
  Serial.begin(115200);
  
  displayManager.initDisplay();
  displayManager.firstWindow();
  
  buttonManager.initButtons();
}

void loop()
{
  // update buttons state
  buttonManager.update();

  // check for button presses and slide the menu accordingly
  menuManager.slide();
}