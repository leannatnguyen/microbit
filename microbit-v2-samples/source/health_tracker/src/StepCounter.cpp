#include "StepCounter.h"
#include "MicroBit.h"

StepCounter::StepCounter(MicroBit &microbit) : HealthSensor(microbit), step_count(0), last_magnitude(0) {}

uint32_t StepCounter::get_steps() {
    // Read accelerometer values (x, y, z) using the MicroBit object from the base class
    int x = uBit.accelerometer.getX();
    int y = uBit.accelerometer.getY();
    int z = uBit.accelerometer.getZ();

    // Calculate magnitude of motion vector
    int magnitude = x * x + y * y + z * z;

    // Check if this motion indicates a step
    if (detect_step(magnitude)) {
        step_count++;  // Increment step count
    }

    last_magnitude = magnitude;  // Update last magnitude
    return step_count;
}


void StepCounter::update() {
    uint32_t steps = get_steps();                 // Update and fetch the current step count
    int display_step_count = static_cast<int>(steps);  // Safely cast to int (assuming steps stay within int range)

    if (steps % 10 == 0) {                             // Only display after every 10 steps
        uBit.display.scroll(display_step_count);
    }

}

bool StepCounter::detect_step(int magnitude) {
    return (magnitude - last_magnitude) > STEP_THRESHOLD;
}