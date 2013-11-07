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

    float* getDepthData();
    float* getPrevDepthData();

    void setNearClip(ushort nearClip);
    void setFarClip(ushort farClip);
    ushort getNearClip() const;
    ushort getFarClip() const;

    const QImage& getDepthImage() const;


private:
    int imgWidth, imgHeight;
    float *depthData, *oldDepthData;
    QImage depthImage;
    HANDLE rgbStream;              // The identifier of the Kinect's RGB Camera
    INuiSensor* sensor;            // The kinect sensor
    ushort nearClip, farClip;
};

#endif // SENSOR_H
