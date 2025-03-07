#include "temp_sensor.hpp"

MicroBitStorage storage; 
MicroBitThermometer thermometer(storage); 

TempSensor::~TempSensor() {
    // Optional: Clean-up logic
}

float TempSensor::read_data(void) const{

}