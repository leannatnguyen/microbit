#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include "sensor.hpp"
#include "MicroBitThermometer.h""

class TempSensor : public Sensor {
    private:
        MicroBitThermometer thermometer;  // Declare thermometer object

    public:
        TempSensor();
        ~TempSensor() override;

    int read_data() override; 
};



#endif