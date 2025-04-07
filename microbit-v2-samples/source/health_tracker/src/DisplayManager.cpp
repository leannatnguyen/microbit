#include "DisplayManager.h"
#include "HealthTracker.h"

DisplayManager::DisplayManager(MicroBit &uBit, HealthTracker &tracker) : microbit(uBit), tracker(tracker), display_index(0), display_delay(2000) {
    last_display_time = uBit.systemTime();
}

void DisplayManager::update() {
    if (microbit.systemTime() - last_display_time >= display_delay) {
        last_display_time = microbit.systemTime();

        if (display_index == 0) {
            microbit.display.scroll("Steps:");
            microbit.display.scroll(tracker.get_step_count());
        } else if (display_index == 1) {
            microbit.display.scroll("HR:");
            microbit.display.scroll(tracker.get_heart_rate());
        } else if (display_index == 2) {
            microbit.display.scroll("Temp (F):");
            microbit.display.scroll(tracker.get_temperature());
        }

        display_index = (display_index + 1) % 3;
    }
   
}