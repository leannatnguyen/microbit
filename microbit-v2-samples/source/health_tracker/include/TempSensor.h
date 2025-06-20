#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include "HealthSensor.h"
#include "MicroBitThermometer.h"

class TempSensor : public HealthSensor {
    public:
        TempSensor(MicroBit &microbit) : HealthSensor(microbit) {}
        void calculate_temp();
        int get_temp();
        void update() override;
    private:
        int temperature;
};

#endif