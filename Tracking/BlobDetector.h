#ifndef BLOBDETECTOR_H
#define BLOBDETECTOR_H

#include <QImage>
#include "tracking_global.h"

struct Blob
{
    QRect boundingBox;
    QImage isolatedImage;
    float avrDepth;
    int pixelCount;

    bool operator < (const Blob& blob) const;
};

class TRACKINGSHARED_EXPORT BlobDetector
{
public:
    BlobDetector();

    void update(const QImage& binaryImage, const float *depthValues = 0, float depthThreashold = 0.0f, int minSize = 2000);

    int getNumBlobs() const;
    const Blob& getBlob(int index) const;

    int grassFire(const QImage &image, QImage &blobImg, const float *depthValues, int x, int y, QColor color, QRect& boundingBox, float &avrDepth);
    bool testPixel(const QImage &image, QImage &blobImg, const float *depthValues, const QPoint& p);
private:
    QList<Blob> blobs;
    float depthThreashold;
};

#endif // BLOBDETECTOR_H
