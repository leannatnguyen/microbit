#include "MicroBit.h"
#include "Tests.h"
#include "samples/Tests.h"
#include "HealthTracker.h"
#include "HealthSensor.h"
#include "TempSensor.h"
#include "StepCounter.h"
#include "HeartRate.h"
#include <cstdio>

MicroBit uBit;

int main() {
    uBit.init();
    static HeartRate heart_rate(uBit);
    static StepCounter steps(uBit);
    static TempSensor temp(uBit);
    static Buzzer buzzer(uBit);
    uBit.display.scroll(":)");

    uBit.display.scroll("7");  // Confirm micro:bit starts

    int display_index = 0;
    int loop_delay = 100;
    int display_delay = 2000; // display every 2s
    int last_display_time = uBit.systemTime();

    while (true) {
        steps.update();
        temp.update();

        if (heart_rate.get_heart_rate() > 180) {
            buzzer.trigger_alert();
        }
        if (uBit.systemTime() - last_display_time >= display_delay) {
            last_display_time = uBit.systemTime();

            if (display_index == 0) {
                uBit.display.scroll("Steps:");
                uBit.display.scroll(steps.get_steps());
            } else if (display_index == 1) {
                uBit.display.scroll("HR:");
                uBit.display.scroll(heart_rate.get_heart_rate());
            } else if (display_index == 2) {
                uBit.display.scroll("Temp (F):");
                uBit.display.scroll(temp.get_temp());
            }

            display_index = (display_index + 1) % 3;
        }
        uBit.sleep(loop_delay);
    }
}
