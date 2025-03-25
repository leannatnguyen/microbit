#include "DisplayManager.h"

DisplayManager::DisplayManager(MicroBit &uBit) : microbit(uBit) {}

void DisplayManager::update(int steps, int heartRate) {
    // Scroll the step count first
    microbit.display.scroll("Steps: ");
    microbit.display.scroll(steps);

    // Then scroll the heart rate
    microbit.display.scroll("HR: ");
    microbit.display.scroll(heartRate);
}