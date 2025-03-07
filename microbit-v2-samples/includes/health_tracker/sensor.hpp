#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "MicroBit.h"

class Sensor {
    public:
        virtual ~Sensor();
        virtual float read_data() const;
};

#endif //SENSOR_HPP