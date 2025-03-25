#ifndef HEALTHTRACKER_H
#define HEALTHTRACKER_H

#include "MicroBit.h"
#include "StepCounter.h"
#include "HeartRate.h"
#include "TempSensor.h"
#include "DisplayManager.h"
#include "Buzzer.h"

class HealthTracker {
private:
    StepCounter step_counter;
    HeartRate heart_rate;
    DisplayManager display_manager;
    Buzzer buzzer;
    MicroBit& microbit;

public:
    HealthTracker(MicroBit &uBit);

    void monitor();
};
#endif