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
    uBit.init(); //Init the uBit object

    static HeartRate heart_rate(uBit);

    // create two static objects for Health Tracker and Display Manager 
    // static = persists for entirety of the program
    static HealthTracker health_tracker(uBit, heart_rate); // passed uBit (microbit instance)
    
    // passed microbit instance (to handle display) and health tracker instance (to fetch health 
    // sensor data)
    static DisplayManager display_manager(uBit, health_tracker); 


    int loop_delay = 100;

    while (true) {
        health_tracker.monitor();
        display_manager.update();
        uBit.sleep(loop_delay);
    }
}
   
