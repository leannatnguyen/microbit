#ifndef HEALTHTRACKER_H
#define HEALTHTRACKER_H

#include "MicroBit.h"
#include "StepCounter.h"
#include "HeartRate.h"
#include "TempSensor.h"
#include "DisplayManager.h"
#include "Buzzer.h"

class HealthTracker {
public:
HealthTracker(MicroBit &uBit, HeartRate &heart_rate);
    void monitor();
    int get_heart_rate() { return heart_rate.get_heart_rate(); }
    int get_step_count() { return step_counter.get_steps(); }
    int get_temperature() { return temp_sensor.get_temp(); }
private:
    MicroBit &uBit;
    HeartRate &heart_rate;
    StepCounter step_counter;
    TempSensor temp_sensor;
    Buzzer buzzer;
};
#endif