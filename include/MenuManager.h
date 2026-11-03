#pragma once

#include "ButtonManager.h"
#include "DisplayManager.h"
#include "Config.h"

class MenuManager
{
private:
    DisplayManager& display;
    ButtonManager& buttonManager; 
    int currentIndex;
    int previousIndex;

public:
    MenuManager(DisplayManager& displayInstance, ButtonManager& buttonInstance);
    ~MenuManager();

    void slide();
};