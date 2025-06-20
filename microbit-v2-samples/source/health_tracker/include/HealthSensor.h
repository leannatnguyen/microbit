#ifndef HEALTHSENSOR_H
#define HEALTHSENSOR_H

#include "MicroBit.h"

class HealthSensor {
protected:
    MicroBit &uBit;  // Store reference to MicroBit instance

public:
    HealthSensor(MicroBit &microbit) : uBit(microbit) {}    
    virtual ~HealthSensor() {}  // Virtual destructor (important for polymorphism)
    
    // Pure virtual function to be overridden by child classes
    virtual void update() = 0;
};

#endif // HEALTHSENSOR_H
