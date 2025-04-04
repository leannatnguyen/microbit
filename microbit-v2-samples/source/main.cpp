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
    
    static HealthTracker health_tracker(uBit);
    static DisplayManager display_manager(uBit, health_tracker);

    int loop_delay = 100;

    while (true) {
        health_tracker.monitor();
        display_manager.update();
        uBit.sleep(loop_delay);
    }
}
   
