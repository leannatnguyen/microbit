#ifndef BUZZER_H
#define BUZZER_H

#include "MicroBit.h"

class Buzzer {
private:
    MicroBit& microbit;

public:
    Buzzer(MicroBit &uBit);

    void trigger_alert();  // Activate the buzzer for a short duration
};

#endif