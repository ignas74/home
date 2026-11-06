#pragma once

#include "Config.h"
#include "ButtonManager.h"
#include "DisplayManager.h"

class MenuManager
{
private:
    DisplayManager& display;
    ButtonManager& buttonManager; 
    int currentIndex;
    int previousIndex;

public:
    MenuManager(DisplayManager& displayInstance, ButtonManager& buttonInstance);

    int getCurrentIndex() const;
    void slide();
};