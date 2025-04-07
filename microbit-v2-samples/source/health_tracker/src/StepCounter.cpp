#include "StepCounter.h"
#include "MicroBit.h"

// takes reference to Microbit instance, passes to base class (HealthSensor), init step count and last magnitude
// to 0
StepCounter::StepCounter(MicroBit &microbit) : HealthSensor(microbit), step_count(0), last_magnitude(0) {}

void StepCounter::calculate_steps() {
    // Read accelerometer values (x, y, z) using the MicroBit object from the base class
    int x = uBit.accelerometer.getX();
    int y = uBit.accelerometer.getY();
    int z = uBit.accelerometer.getZ();

    // Calculate magnitude of motion vector (x^2 + y^2 + z^2)
    int magnitude = x * x + y * y + z * z;

    // Check if this motion indicates a step (if change in magnitude is large enough
    // to count as a step)
    if (detect_step(magnitude)) {
        step_count++;  // Increment step count
    }

    last_magnitude = magnitude;  // Update last magnitude
}

int StepCounter::get_steps() {
    int steps = static_cast<int>(step_count);
    return steps;
}

void StepCounter::update() {
    calculate_steps();                 // Update current step count
}

bool StepCounter::detect_step(int magnitude) {
    return (magnitude - last_magnitude) > STEP_THRESHOLD;
}