#include "DisplayManager.h"

DisplayManager::DisplayManager()
    : SDA_PIN(Config::PIN_OLED_SDA),
      SCL_PIN(Config::PIN_OLED_SCL),
      SCREEN_WIDTH(Config::OLED_SCREEN_WIDTH),
      SCREEN_HEIGHT(Config::OLED_SCREEN_HEIGHT),
      OLED_RESET(Config::OLED_RESET),
      display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) // Pass
{
}

void DisplayManager::initDisplay()
{
    Wire.begin(SDA_PIN, SCL_PIN);

    if (!display.begin(0x3C, true))
    {
        Serial.println("OLED did not launch");
        while (true)
            ;
    }
}

void DisplayManager::firstWindow()
{
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("1");
    display.display();
}

void DisplayManager::secondWindow()
{
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);

    display.println("2");
    
    display.display();
}

void DisplayManager::thirdWindow()
{
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("3");
    display.display();
}

/*
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Reset pin not used with I2C

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  Serial.println("SH1106 OLED Test");

  if(!display.begin(0x3C, true)) { // Address 0x3C for most modules
    Serial.println("SH1106 allocation failed");
    for(;;);
  }

  display.display(); // Push buffer to the screen
}

*/

DisplayManager::~DisplayManager()
{
}

// void clearDisplay()
// {
//     display.clearDisplay();
// }

// void setTextColor()
// {
//     display.setTextColor(SH110X_WHITE);
// }

// void showInfoInDisplay(float distance)
// {
//     display.clearDisplay();

//     display.setTextSize(1);
//     display.setCursor(0, 0);
//     display.println("distance:");

//     display.setTextSize(3);
//     display.setCursor(0, 20);
//     display.print(distance, 1);
//     // display.println(" cm");

//     display.display();
// }

// void DisplayManager::set_SDA_PIN(int a)
// {
//     SDA_PIN = a;
// }

// int DisplayManager::get_SDA_PIN() const
// {
//     return SDA_PIN;
// }s s