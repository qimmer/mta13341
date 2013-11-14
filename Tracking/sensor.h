#ifndef SENSOR_H
#define SENSOR_H

#include "tracking_global.h"

#include <Windows.h>
#include <Ole2.h>

#include <NuiApi.h>
#include <NuiImageCamera.h>
#include <NuiSensor.h>
#include <QImage>

#include "velocitymapper.h"

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

    /**
     * @brief initialize Initializes a kinect sensor
     * @param sensorId The index of which sensor to initialize. 0 for the first connected sensor->
     * @param res Which resolutiion to use for the depth image
     * @return True if the sensor is initialized properly
     */
    bool initialize(int sensorId, SensorResolution res);

    /**
     * @brief update Refresh the sensor image if available
     * @return True if a new image has been received from the sensor
     */
    bool update();

    /**
     * @brief getDepthData
     * @return The depth image in normalized floating point data
     */
    float* getDepthData();

    /**
     * @brief getDepthData Used for velocity calculation
     * @return The previous depth image in normalized floating point data
     */
    float* getPrevDepthData();

    /**
     * @brief setNearClip sets the near clipping plane distance
     * @param nearClip
     */
    void setNearClip(ushort nearClip);

    /**
     * @brief setFarClip sets the far clipping plane distance
     * @param farClip
     */
    void setFarClip(ushort farClip);

    /**
     * @brief getNearClip
     * @return The current near clipping plane distace
     */
    ushort getNearClip() const;

    /**
     * @brief getFarClip
     * @return The current far clipping plane distance
     */
    ushort getFarClip() const;

    /**
     * @brief getDepthImage
     * @return A debugger image of the depth data
     */
    const QImage& getDepthImage() const;

    /**
     * @brief getVelocityMapper
     * @return A velocity mapper used to calculate velocity
     */
    VelocityMapper *getVelocityMapper();

private:
    int imgWidth, imgHeight;
    float *depthData, *oldDepthData; // Floating point depth data
    QImage depthImage; // Debugging image for depth data
    HANDLE rgbStream;              // The identifier of the Kinect's RGB Camera
    INuiSensor* sensor;            // The kinect sensor
    ushort nearClip, farClip; // Clipping planes
    VelocityMapper velMapper;
};

#endif // SENSOR_H
