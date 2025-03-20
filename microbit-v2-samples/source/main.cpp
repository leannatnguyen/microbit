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
    uBit.display.scroll(":)");

    uBit.display.scroll("Temp (F): ");
    int temp = tempsense.readData();
    uBit.display.print(temp);

    uBit.sleep(500);

    // thermometer.init();  // Initialize thermometer
    int new_temp = uBit.thermometer.getTemperature();

    uBit.display.print(new_temp);
    
    
    while (1) {
        uBit.display.scroll("Temp (F): ");
        int temp = tempsense.readData();
        uBit.display.print(temp);

        uBit.sleep(500);

        // thermometer.init();  // Initialize thermometer
        int new_temp = uBit.thermometer.getTemperature();

        uBit.display.print(new_temp);
    }
    
}