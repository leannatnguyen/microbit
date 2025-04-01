#include "TempSensor.h"
#include <cstdio>

void TempSensor::calculate_temp() {
    int temp = uBit.thermometer.getTemperature();
    
    temperature = (temp * 1.8) + 32;
}

int TempSensor::get_temp() {
    return temperature;
}

void TempSensor::update() {
    calculate_temp();
}