#ifndef DEPTHSLICER_H
#define DEPTHSLICER_H

#include "tracking_global.h"
#include <QImage>
#include <QList>

class TRACKINGSHARED_EXPORT DepthSlicer
{
public:
    DepthSlicer();

    void sliceDepth(float *pDepthSrc,
                    float *pDest,
                    float nearDepth,
                    float farDepth,
                    const QSize& size);
};

#endif // DEPTHSLICER_H
