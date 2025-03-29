#include "HealthTracker.h"

HealthTracker::HealthTracker(MicroBit &uBit)
    : step_counter(uBit), heart_rate(uBit), temp_sensor(uBit), display_manager(uBit),
    buzzer(uBit), uBit(uBit) {}

void HealthTracker::monitor() {
    int displayCycle = 0;  // Used to rotate between displaying different readings
    
    while (true) {
        // 1. Step Counter Update: Display every 3rd cycle
        if (displayCycle % 3 == 0) {
            step_counter.update();  // Update step count and display it
        }

        // 2. Heart Rate Update: Display every cycle
        heart_rate.update();  // Update and display heart rate
        
        // 3. Check Heart Rate and Trigger Buzzer if Out of Range
        int currentHR = heart_rate.get_heart_rate();
        if (currentHR > 150 || currentHR < 55) {
            buzzer.trigger_alert();
        }

        // 4. Temperature Sensor Update: Display every 2nd cycle
        if (displayCycle % 2 == 0) {
            int temperature = temp_sensor.get_temp();
            uBit.display.scroll("Temp: " + ManagedString(temperature) + "F");
        }

        // Cycle through different displays (step count, heart rate, temp)
        displayCycle++;
        if (displayCycle >= 6) {
            displayCycle = 0;  // Reset cycle after 6 loops
        }

        uBit.sleep(1000);  // 1-second delay before next iteration
    }
}
