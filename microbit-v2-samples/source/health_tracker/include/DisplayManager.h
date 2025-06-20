#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "MicroBit.h"

class HealthTracker;  
class DisplayManager {
public:
    DisplayManager(MicroBit &uBit, HealthTracker &tracker);
    void update(); 
private:
    MicroBit& microbit;
    HealthTracker &tracker;
    int display_index;
    int display_delay;
    int last_display_time;
};

#endif