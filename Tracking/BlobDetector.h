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
    int pixelCount;
};

class TRACKINGSHARED_EXPORT BlobDetector
{
public:
    BlobDetector();

    void update(const QImage& binaryImage);

    int getNumBlobs() const;
    const Blob& getBlob(int index) const;

    void grassFire(const QImage &image, QImage &blobImg, int x, int y, QColor color, int &size);

private:
    QList<Blob> blobs;
};

#endif // BLOBDETECTOR_H
