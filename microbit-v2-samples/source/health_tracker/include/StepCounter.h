#ifndef STEPCOUNTER_H
#define STEPCOUNTER_H

#include "HealthSensor.h"
#include "MicroBitThermometer.h"
#include <cstdint>

class StepCounter : public HealthSensor {
public:
    StepCounter(MicroBit &microbit);
    void calculate_steps();
    int get_steps();
    void update();
private:
    uint32_t step_count;
    int last_magnitude;
    static const int STEP_THRESHOLD = 1000;
    bool detect_step(int magnitude);
};

#endif