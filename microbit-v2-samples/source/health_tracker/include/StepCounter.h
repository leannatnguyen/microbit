#ifndef STEPCOUNTER_H
#define STEPCOUNTER_H

#include "HealthSensor.h"
#include "MicroBitThermometer.h"

class StepCounter : public HealthSensor {
    // private:
    //     MicroBitThermometer thermometer;  // Declare thermometer object

    public:
        StepCounter();
        int readData();
};

#endif