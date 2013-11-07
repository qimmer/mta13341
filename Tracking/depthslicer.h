#ifndef DEPTHSLICER_H
#define DEPTHSLICER_H

#include "tracking_global.h"
#include <QImage>
#include <QList>

class TRACKINGSHARED_EXPORT DepthSlicer
{
public:
    DepthSlicer();

    void sliceImage(const QImage& img, int slices);

    const QImage& getSlice(int slice) const;

private:
    QList<QImage> slices;
};

#endif // DEPTHSLICER_H
