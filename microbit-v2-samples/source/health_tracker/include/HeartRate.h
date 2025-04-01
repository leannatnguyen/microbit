#ifndef HEARTRATE_H
#define HEARTRATE_H

#include <cstdint>
#include "HealthSensor.h"

class HeartRate : public HealthSensor {
public:
    HeartRate(MicroBit &microbit);  // Constructor
    ~HeartRate();                   // Destructor
    void update();                  // Display the current heart rate
    int get_heart_rate();
    void onButtonA(MicroBitEvent e);
    void onButtonB(MicroBitEvent e);
    
private:
    int current_heart_rate;         // Stores the heart rate value
};

#endif