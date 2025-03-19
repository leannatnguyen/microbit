#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include "HealthSensor.h"
#include "MicroBitThermometer.h"

class TempSensor : public HealthSensor {
    // private:
    //     MicroBitThermometer thermometer;  // Declare thermometer object

    public:
        TempSensor();
        float readData();
};

#endif