#pragma once

namespace Config
{
    // OLED Display
    constexpr int PIN_OLED_SDA = 18;
    constexpr int PIN_OLED_SCL = 19;

    // DHT11 Sensor
    constexpr int DHT_PIN = 4;
    constexpr int DHT_TYPE = 11;

    // HC-SR04 Ultrasonic Sensor
    constexpr int ECHO_PIN = 32;
    constexpr int TRIG_PIN = 33;

    constexpr int LEFT_BUTTON_PIN = 27;
    constexpr int RIGHT_BUTTON_PIN = 26;

    constexpr int OLED_SCREEN_WIDTH = 128;
    constexpr int OLED_SCREEN_HEIGHT = 64;
    constexpr int OLED_RESET = -1;

    constexpr int MENU_CURRENT_INDEX = 1;
    constexpr int MENU_PREVIOUS_INDEX = 0;
};