#ifndef HEALTHSENSOR_H
#define HEALTHSENSOR_H

#include "MicroBit.h"

class HealthSensor {
public:
    virtual ~HealthSensor() {}  // Virtual destructor (important for polymorphism)
    
    // Pure virtual function to be overridden by child classes
    virtual int readData() = 0;  
};

#endif // HEALTHSENSOR_H
