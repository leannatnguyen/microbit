#include "step_counter.hpp"
#include <MicroBit.h>

extern MicroBit uBit; // Access the global MicroBit instance

StepCounter::StepCounter() : stepCount(0) {}

int StepCounter::read_data() {
    // Read accelerometer and determine step count logic
    return stepCount;
}
