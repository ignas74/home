#include "DisplayManager.h"

DisplayManager::DisplayManager(TemperatureSensor &tempSensor)
    : SDA_PIN(Config::PIN_OLED_SDA),
      SCL_PIN(Config::PIN_OLED_SCL),
      SCREEN_WIDTH(Config::OLED_SCREEN_WIDTH),
      SCREEN_HEIGHT(Config::OLED_SCREEN_HEIGHT),
      OLED_RESET(Config::OLED_RESET),
      temperatureSensor(tempSensor),
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

    display.setTextColor(SH110X_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Temperature:");
    display.setTextSize(2);
    display.print(temperatureSensor.readTemperature());
    display.setTextSize(1);
    display.println(" C");

    display.setTextSize(1);
    display.setCursor(0, 30);
    display.println("Humidity:");
    display.setTextSize(2);
    display.print(temperatureSensor.readHumidity());
    display.setTextSize(1);
    display.println(" %");

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

DisplayManager::~DisplayManager()
{
}
