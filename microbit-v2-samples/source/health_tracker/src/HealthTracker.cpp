#include "HealthTracker.h"

HealthTracker::HealthTracker(MicroBit &uBit)
    : step_counter(uBit), heart_rate(uBit), display_manager(uBit), 
    buzzer(uBit), microbit(uBit) {}

void HealthTracker::monitor() {
    int steps = step_counter.get_steps();        // Get updated step count
    int heartRateValue = heart_rate.calculate_heart_rate();  // Get updated heart rate

    display_manager.update(steps, heartRateValue);    // Display the latest values

    // Check if heart rate is dangerously high (e.g., >150 bpm)
    if (heartRateValue > 150) {
        buzzer.trigger_alert();                 // Trigger buzzer alert
    }

    microbit.sleep(1000);  // Monitor every second
}
