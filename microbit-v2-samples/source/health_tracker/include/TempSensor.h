#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include "HealthSensor.h"
#include "MicroBitThermometer.h"

class TempSensor : public HealthSensor {
    public:
        TempSensor(MicroBit &microbit) : HealthSensor(microbit) {}
        int get_temp();
        void update() override; 
};

#endif