#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "MicroBit.h"

class DisplayManager {
private:
    MicroBit& microbit;

public:
    DisplayManager(MicroBit &uBit);

    void update(int steps, int heartRate);  // Displays step count and heart rate alternately
};

#endif