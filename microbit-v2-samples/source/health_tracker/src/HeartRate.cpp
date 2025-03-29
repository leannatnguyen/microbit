#include "HeartRate.h"
#include "MicroBit.h"

HeartRate::HeartRate(MicroBit &microbit) : HealthSensor(microbit), current_heart_rate(70) {}

void HeartRate::calculate_heart_rate() {
    if (uBit.buttonA.isPressed()) {
        current_heart_rate += 5;
    } 
    if (uBit.buttonB.isPressed()) {
        current_heart_rate -= 5;
    }

    if (current_heart_rate < 50) current_heart_rate = 50;
    if (current_heart_rate > 180) current_heart_rate = 180;
}

int HeartRate::get_heart_rate() {
    return current_heart_rate;
}

void HeartRate::update() {
    calculate_heart_rate();
}