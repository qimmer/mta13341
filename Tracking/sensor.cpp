#include "sensor.h"
#include <QRgb>
#include <QColor>
#include <QImage>

Sensor::Sensor()
{
    sensor = 0;

}

Sensor::~Sensor()
{
    if( sensor )
        sensor->Release();

    delete[] depthData;
    delete[] oldDepthData;
    delete[] velData;

    sensor = 0;
}

bool Sensor::initialize(int sensorId, SensorResolution res)
{
    // Get a working kinect sensor
    int numSensors;
    if (NuiGetSensorCount(&numSensors) < 0 || numSensors < 1)
        return false;

    // Make sure we have the required available amount of sensors
    if( sensorId >= numSensors )
        return false;

    // Create our sensor object
    if (NuiCreateSensorByIndex(0, &this->sensor) < 0)
        return false;

    NUI_IMAGE_RESOLUTION nuiRes;
    if( res == High )
        nuiRes = NUI_IMAGE_RESOLUTION_640x480;
    else if( res == Medium )
        nuiRes = NUI_IMAGE_RESOLUTION_320x240;
    else
        nuiRes = NUI_IMAGE_RESOLUTION_80x60;

    // Initialize sensor
    sensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_DEPTH | NUI_INITIALIZE_FLAG_USES_COLOR);
    sensor->NuiImageStreamOpen(
        NUI_IMAGE_TYPE_DEPTH,            // Depth camera or rgb camera?
        nuiRes,    // Image resolution
        NUI_IMAGE_STREAM_FLAG_DISTINCT_OVERFLOW_DEPTH_VALUES,      // Image stream flags, e.g. near mode
        2,      // Number of frames to buffer
        NULL,   // Event handle
        &this->rgbStream);

    if( res == High )
    {
        imgWidth = 640;
        imgHeight = 480;
    }
    else if( res == Medium )
    {
        imgWidth = 320;
        imgHeight = 240;
    }
    else
    {
        imgWidth = 80;
        imgHeight = 60;
    }

    depthData = new USHORT[imgWidth*imgHeight];
    oldDepthData = new USHORT[imgWidth*imgHeight];
    velData = new short[imgWidth*imgHeight];
    memset(depthData, 0, sizeof(USHORT)*imgWidth*imgHeight);
    memset(oldDepthData, 0, sizeof(USHORT)*imgWidth*imgHeight);
    memset(velData, 0, sizeof(USHORT)*imgWidth*imgHeight);

    depthImage = QImage(imgWidth, imgHeight, QImage::Format_ARGB32);

    return true;
}

bool Sensor::update()
{
    NUI_IMAGE_FRAME imageFrame;
    NUI_LOCKED_RECT LockedRect;
    if (sensor->NuiImageStreamGetNextFrame(rgbStream, 0, &imageFrame) < 0)
        return false;

    INuiFrameTexture* texture = imageFrame.pFrameTexture;

    texture->LockRect(0, &LockedRect, NULL, 0);

    if (LockedRect.Pitch != 0)
    {
        const USHORT* curr = (const USHORT*) LockedRect.pBits;

        memcpy(oldDepthData, depthData,(imgWidth*imgHeight)*sizeof(USHORT));
        memcpy(depthData, curr, (imgWidth*imgHeight)*sizeof(USHORT));

        for( int x = 0; x < imgWidth; ++x )
        {
            for( int y = 0; y < imgHeight; ++y )
            {
                USHORT depth = depthData[x + y*imgWidth];


                int diff = int(depthData[x + y*imgWidth]) - int(oldDepthData[x + y*imgWidth]);

                if( depthData[x + y*imgWidth] == 0 ||
                    depthData[x + y*imgWidth] > SHRT_MAX ||
                    oldDepthData[x + y*imgWidth] == 0 ||
                    oldDepthData[x + y*imgWidth] > SHRT_MAX )
                {
                    diff = 0;
                }

                velData[x + y*imgWidth] = diff;

                if( depth > SHRT_MAX-500 )
                    depth = 0;

                depth = int((double)(depth) / USHRT_MAX * 255);

                (&depthImage.bits()[(x + y*imgWidth)*4])[2] = depth;
                (&depthImage.bits()[(x + y*imgWidth)*4])[0] = depth;
                (&depthImage.bits()[(x + y*imgWidth)*4])[1] = depth;
                (&depthImage.bits()[(x + y*imgWidth)*4])[3] = 255;
            }
        }
    }

    texture->UnlockRect(0);
    sensor->NuiImageStreamReleaseFrame(rgbStream, &imageFrame);

    return true;
}

USHORT *Sensor::getDepthData()
{
    return depthData;
}

short *Sensor::getVelocityData()
{
    return velData;
}

const QImage &Sensor::getDepthImage() const
{
    return depthImage;
}
