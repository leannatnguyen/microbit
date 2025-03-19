#include "MicroBit.h"
#include "samples/Tests.h"
#include "HealthSensor.h"
#include "TempSensor.h"
#include <cstdio>

MicroBit uBit;

int main() {
    uBit.init();
    uBit.display.scroll("I");  // Confirm micro:bit starts

    TempSensor tempsense;
    uBit.display.scroll("tempsense created");
    
    while (1) {
        uBit.sleep(1000);
    }
    
}