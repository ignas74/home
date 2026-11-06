#include "MenuManager.h"

MenuManager::MenuManager(DisplayManager &displayInstance, ButtonManager &buttonInstance)
    : display(displayInstance),
      buttonManager(buttonInstance),
      currentIndex(Config::MENU_CURRENT_INDEX),
      previousIndex(Config::MENU_PREVIOUS_INDEX)
{
}

int MenuManager::getCurrentIndex() const
{
  return currentIndex;
}

void MenuManager::slide()
{
  // buttons state from ButtonManager
  bool isLeftPressed = buttonManager.isLeftPressed();
  bool isRightPressed = buttonManager.isRightPressed();

  // if (isLeftPressed || isRightPressed)
  // {
  //   Serial.print("LEFT: ");
  //   Serial.print(isLeftPressed);

  //   Serial.print(" | RIGHT: ");
  //   Serial.print(isRightPressed);

  //   Serial.print(" | INDEX BEFORE: ");
  //   Serial.println(currentIndex);
  // }

  /*
  tracks where we are in the menu
  if we are at the last menu and press right -> show 1st window and vice versa
  */

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

  // tracks changes and updates index

  if (previousIndex != currentIndex)
  {
    if (currentIndex == 1)
    {
      display.firstWindow();
      previousIndex = 1;
    }
    else if (currentIndex == 2)
    {
      display.secondWindow();
      previousIndex = 2;
    }
    else if (currentIndex == 3)
    {
      display.thirdWindow();
      previousIndex = 3;
    }
  }

  // if (isLeftPressed || isRightPressed)
  // {
  //   Serial.print("INDEX AFTER: ");
  //   Serial.println(currentIndex);
  // }
}