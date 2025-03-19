#include "TempSensor.h"
#include <cstdio>

extern MicroBit uBit;
TempSensor::TempSensor() {
    uBit.sleep(500);
}

// TempSensor::~TempSensor() {
//     // Optional: Clean-up logic
// }

float TempSensor::readData() {
    return 0.0;
    //  return thermometer.getTemperature();
}