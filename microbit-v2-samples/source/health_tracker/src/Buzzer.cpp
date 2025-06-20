#include "Buzzer.h"

Buzzer::Buzzer(MicroBit &uBit) : microbit(uBit) {}

void Buzzer::trigger_alert() {
    // Play a 1kHz beep (1000 Hz frequency)
    microbit.audio.virtualOutputPin.setAnalogValue(512);       // Half-voltage
    microbit.audio.virtualOutputPin.setAnalogPeriodUs(1000);   // 1000 µs period = 1 kHz frequency
    microbit.sleep(500);  // Beep for 500 milliseconds

    microbit.audio.virtualOutputPin.setAnalogValue(0);  // Turn off the sound
    microbit.sleep(500);  // Optional pause after the beep

}