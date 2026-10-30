#include <Arduino.h>

#include "DisplayManager.h"
#include "ButtonManager.h"


DisplayManager displayManager;
ButtonManager buttonManager;

void setup()
{
  Serial.begin(115200);
  displayManager.initDisplay();
  displayManager.firstWindow();
  buttonManager.initButtons();
}

int currentIndex = 1;
int previousIndex;

void loop()
{
  buttonManager.update();

  bool isLeftPressed = buttonManager.isLeftPressed();
  bool isRightPressed = buttonManager.isRightPressed();

  if (isLeftPressed || isRightPressed)
{
    Serial.print("LEFT: ");
    Serial.print(isLeftPressed);

    Serial.print(" | RIGHT: ");
    Serial.print(isRightPressed);

    Serial.print(" | INDEX BEFORE: ");
    Serial.println(currentIndex);
}

  if (isLeftPressed)
  {
    currentIndex--;

    if (currentIndex < 1)
    {
      currentIndex = 3;
    }
  }
  else if (isRightPressed)
  {
    currentIndex++;

    if (currentIndex > 3)
    {
      currentIndex = 1;
    }
  }

  if (previousIndex != currentIndex)
  {
    if (currentIndex == 1)
    {
      displayManager.firstWindow();
      previousIndex = 1;
    }
    else if (currentIndex == 2)
    {
      displayManager.secondWindow();
      previousIndex = 2;
    }
    else if (currentIndex == 3)
    {
      displayManager.thirdWindow();
      previousIndex = 3;
    }
  }

  if (isLeftPressed || isRightPressed)
{
    Serial.print("INDEX AFTER: ");
    Serial.println(currentIndex);
}

  // delay(1000);
}
