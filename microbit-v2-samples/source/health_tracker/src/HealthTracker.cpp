#include "HealthTracker.h"

HealthTracker::HealthTracker(MicroBit &uBit)
    : step_counter(uBit), temp_sensor(uBit),
    buzzer(uBit), uBit(uBit) {}

void HealthTracker::monitor() {
    step_counter.update();
    temp_sensor.update();
    if (heart_rate.get_heart_rate() > 180) {
        buzzer.trigger_alert();
    }
}
