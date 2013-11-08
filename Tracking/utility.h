#ifndef UTILITY_H
#define UTILITY_H

#include "tracking_global.h"
#include <QImage>
#include <QList>

class TRACKINGSHARED_EXPORT Utility
{
public:
    static void sliceDepth(float *pDepthSrc,
                    float *pDest,
                    float nearDepth,
                    float farDepth,
                    const QSize& size);

    static void depthToBinary(float *pDepthSrc, QImage *binaryImage);

    static void centerOfPlayer(Blob &blob);
};

#endif // DEPTHSLICER_H
