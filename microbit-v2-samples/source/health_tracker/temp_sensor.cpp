#include "temp_sensor.hpp"

TempSensor::~TempSensor() {
    // Optional: Clean-up logic
}

int TempSensor::read_data() {
    return thermometer.getTemperature();
}