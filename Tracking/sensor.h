#ifndef SENSOR_H
#define SENSOR_H

#include <QImage>

class Sensor
{
public:
    Sensor();

    bool initialize(int sensorId);

    void update();

    const QImage& getDepthImage() const;

private:
    QImage depthImage;
};

#endif // SENSOR_H
