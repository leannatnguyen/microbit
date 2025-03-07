#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "MicroBit.h"

class Sensor {
    public:
        virtual ~Sensor();
        virtual int read_data() = 0;
};

#endif //SENSOR_HPP