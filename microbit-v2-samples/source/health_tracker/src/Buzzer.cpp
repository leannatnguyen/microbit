#include "Buzzer.h"

Buzzer::Buzzer(MicroBit &uBit) : microbit(uBit) {}

void Buzzer::trigger_alert() {
    // Simulate a buzzer alert by toggling pin P0 for a brief sound
    microbit.io.P0.setAnalogValue(512);  // Set P0 to half voltage (buzzer sound on)
    microbit.sleep(500);                 // Keep the buzzer on for 500 ms
    microbit.io.P0.setAnalogValue(0);    // Turn the buzzer off
}