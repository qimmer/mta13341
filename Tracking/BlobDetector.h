#ifndef BLOBDETECTOR_H
#define BLOBDETECTOR_H

#include <QImage>
#include "tracking_global.h"

struct Blob
{
    QSize boundingBox;
    QPoint center;
    float circularity;
    QImage isolatedImage;
};

class TRACKINGSHARED_EXPORT BlobDetector
{
public:
    BlobDetector();

    void update(const QImage& binaryImage);

    int getNumBlobs() const;
    const Blob& getBlob(int index) const;

private:
    QList<Blob> blobs;
};

#endif // BLOBDETECTOR_H
