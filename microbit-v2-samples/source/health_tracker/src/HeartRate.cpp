#include "HeartRate.h"
#include "MicroBit.h"

HeartRate::HeartRate(MicroBit &microbit) : HealthSensor(microbit), current_heart_rate(70) {  // Initialize with default HR
}

int HeartRate::calculate_heart_rate() {
    // Simulate heart rate changes based on button presses:
    if (uBit.buttonA.isPressed()) {
        current_heart_rate += 5;  // Increase HR when Button A is pressed
    } 
    else if (uBit.buttonB.isPressed()) {
        current_heart_rate -= 5;  // Decrease HR when Button B is pressed
    } 
    else {
        // No button pressed: heart rate gradually stabilizes toward 70 bpm (resting)
        if (current_heart_rate > 70) {
            current_heart_rate -= 1;
        } else if (current_heart_rate < 70) {
            current_heart_rate += 1;
        }
    }

    if (current_heart_rate < 50) current_heart_rate = 50;
    if (current_heart_rate > 180) current_heart_rate = 180;

    return current_heart_rate;
}

void HeartRate::update() {
    current_heart_rate = calculate_heart_rate();  // Update heart rate
    uBit.display.scroll(current_heart_rate);  // Display the heart rate
}