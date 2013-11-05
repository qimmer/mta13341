#ifndef SENSOR_H
#define SENSOR_H

#include <QImage>

class Sensor
{
public:
    Sensor(int deviceId);

    const QImage& getDepthImage() const;

};

#endif // SENSOR_H
