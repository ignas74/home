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
    //   currentWindowIndex(0)
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

    display.println(ultrasonicSensor.getDistance());

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
