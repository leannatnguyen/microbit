#include "HeartRate.h"
#include "MicroBit.h"

HeartRate::HeartRate(MicroBit &microbit) : HealthSensor(microbit), current_heart_rate(70) {
    microbit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, this, &HeartRate::onButtonA);
    microbit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, this, &HeartRate::onButtonB);
}

HeartRate::~HeartRate() {
    uBit.display.scroll("HR Destroyed");
}

void HeartRate::onButtonA(MicroBitEvent e) {
    current_heart_rate += 5;
}

void HeartRate::onButtonB(MicroBitEvent e) {
    current_heart_rate -= 5;
}

int HeartRate::get_heart_rate() {
    return current_heart_rate;
}

void HeartRate::update() {
    // calculate_heart_rate();
}