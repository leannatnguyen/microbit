#include "TempSensor.h"
#include <cstdio>

extern MicroBit uBit;
TempSensor::TempSensor() {
    // thermometer.init();
    uBit.sleep(500);
}

// TempSensor::~TempSensor() {
//     // Optional: Clean-up logic
// }

int TempSensor::readData() {
    int temp = uBit.thermometer.getTemperature();
    
    return (temp * 1.8) + 32;
    // return thermometer.getTemperature();
}