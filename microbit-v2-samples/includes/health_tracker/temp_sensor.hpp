#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include "sensor.hpp"

class TempSensor : public Sensor {
    public:
        TempSensor();
        ~TempSensor() override;

    float read_data() const override; 
};



#endif