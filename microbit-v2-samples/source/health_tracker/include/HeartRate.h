#ifndef HEARTRATE_H
#define HEARTRATE_H

#include <cstdint>
#include "HealthSensor.h"

class HeartRate : public HealthSensor {
public:
    HeartRate(MicroBit &microbit);  // Constructor
    void update();                  // Display the current heart rate
    int calculate_heart_rate();     // Mock or process heart rate from sensor

private:
    int current_heart_rate;         // Stores the heart rate value
    
};

#endif