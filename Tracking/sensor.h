#ifndef SENSOR_H
#define SENSOR_H

#include "tracking_global.h"

#include <Windows.h>
#include <Ole2.h>

#include <NuiApi.h>
#include <NuiImageCamera.h>
#include <NuiSensor.h>
#include <QImage>

enum SensorResolution
{
    High,
    Medium,
    Low
};

class TRACKINGSHARED_EXPORT Sensor
{
public:
    Sensor();
    ~Sensor();

    bool initialize(int sensorId, SensorResolution res);

    bool update();

    USHORT* getDepthData();
    short* getVelocityData();
    const QImage& getDepthImage() const;


private:
    int imgWidth, imgHeight;
    USHORT *depthData, *oldDepthData;
    short *velData;
    QImage depthImage;
    HANDLE rgbStream;              // The identifier of the Kinect's RGB Camera
    INuiSensor* sensor;            // The kinect sensor
};

#endif // SENSOR_H
