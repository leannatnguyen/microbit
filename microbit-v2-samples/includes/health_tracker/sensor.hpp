#ifndef SENSOR_HPP
#define SENSOR_HPP

class Sensor {
    public:
        virtual int read_data() = 0;
};

#endif //SENSOR_HPP