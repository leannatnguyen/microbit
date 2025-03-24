#include "TempSensor.h"
#include <cstdio>

// extern MicroBit uBit;

// TempSensor::~TempSensor() {
//     // Optional: Clean-up logic
// }

int TempSensor::get_temp() {
    int temp = uBit.thermometer.getTemperature();
    
    return (temp * 1.8) + 32;
}

void TempSensor::update() {
    uBit.display.scroll("Temp (F): ");
    int temp = get_temp();
    uBit.display.scroll(temp);
}