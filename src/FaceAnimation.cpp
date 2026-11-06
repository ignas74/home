#include "FaceAnimation.h"
#include "FaceFrames.h"
#include <Arduino.h>

FaceAnimation::FaceAnimation(Adafruit_SH1106G &display)
    : frameIdx(0),
      lastMs(0),
      display(display)
{
}

// Bitmap kadrų masyvas
const uint8_t *frames[] = {
    FaceFrames::frame0,
    FaceFrames::frame1,
    FaceFrames::frame2
};

const uint16_t numFrames = sizeof(frames) / sizeof(frames[0]);

void FaceAnimation::update()
{
    const unsigned long interval = 167;

    if (millis() - lastMs >= interval)
    {
        lastMs = millis();

        display.clearDisplay();

        display.drawBitmap(
            0,
            0,
            frames[frameIdx],
            128,
            64,
            SH110X_WHITE
        );

        display.display();

        frameIdx = (frameIdx + 1) % numFrames;
    }
}