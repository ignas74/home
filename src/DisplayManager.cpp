#include "DisplayManager.h"

DisplayManager::DisplayManager(TemperatureSensor &tempSensor, UltrasonicSensor &ultraSensor)
    : sdaPin(Config::PIN_OLED_SDA),
      sclPin(Config::PIN_OLED_SCL),
      screenWidth(Config::OLED_SCREEN_WIDTH),
      screenHeight(Config::OLED_SCREEN_HEIGHT),
      oledReset(Config::OLED_RESET),
      temperatureSensor(tempSensor),
      ultrasonicSensor(ultraSensor),
      display(screenWidth, screenHeight, &Wire, oledReset) // Pass
{
}

void DisplayManager::initDisplay()
{
    Wire.begin(sdaPin, sclPin);

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

    // temperature
    display.setTextColor(SH110X_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Temperature:");

    display.setTextSize(2);
    display.print(temperatureSensor.getTemperature());

    display.setTextSize(1);
    display.println(" C");

    // humidity 
    display.setTextSize(1);
    display.setCursor(0, 30);
    display.println("Humidity:");

    display.setTextSize(2);
    display.print(temperatureSensor.getHumidity());

    display.setTextSize(1);
    display.println(" %");

    display.display();
}

void DisplayManager::secondWindow()
{
    display.clearDisplay();

    display.setTextColor(SH110X_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Distance:");

    display.setTextSize(2);
    display.print(ultrasonicSensor.getDistance());

    display.setTextSize(1);
    display.println(" cm");

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
