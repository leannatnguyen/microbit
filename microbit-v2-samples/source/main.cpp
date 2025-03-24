#include "MicroBit.h"
#include "samples/Tests.h"
#include "HealthSensor.h"
#include "TempSensor.h"
#include "StepCounter.h"
#include <cstdio>

MicroBit uBit;

int main() {
    uBit.init();
    uBit.display.scroll("I");  // Confirm micro:bit starts

    TempSensor temp_sensor(uBit);
    StepCounter steps(uBit);
    uBit.display.scroll(":)");

    uBit.sleep(500);
    
    while (1) {
        // temp_sensor.update();
        // uBit.sleep(500);
        steps.update();
    }
    
}