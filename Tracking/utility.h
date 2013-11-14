#ifndef UTILITY_H
#define UTILITY_H

#include "tracking_global.h"
#include <QImage>
#include <QList>

struct Blob;

class TRACKINGSHARED_EXPORT Utility
{
public:
    /**
     * @brief depthToImage Creates a RGBA32 image from floating point depth data.
     *                     Only use this for debugging purposes, as precision is lost!
     * @param pDepthSrc The source floating point depth image
     * @param image The address of the output RGBA32 image
     */
    static void depthToImage(float *pDepthSrc, QImage *image);

    /**
     * @brief depthToBinary Take depth data and generate white pixels for every time a depth
     *                      value is not zero (outside near and far clip planes).
     * @param pDepthSrc The floating point depth image
     * @param binaryImage The address of the output image
     */
    static void depthToBinary(float *pDepthSrc, QImage *binaryImage);

    static void centerOfPlayer(Blob &blob);
};

#endif // DEPTHSLICER_H
