#include "BlobDetector.h"

BlobDetector::BlobDetector()
{
}

void BlobDetector::update(const QImage &binaryImage)
{
    // Empty the blob container
    this->blobs.clear();

    /* Add found blobs to the container here.
     * Example: Adding a blob to the container
     * GOD ARBEJDSLYST! :-D

    Blob tempBlob;
    tempBlob.boundingBox = QSize(100, 150);
    tempBlob.center = QPoint(154, 120);
    tempBlob.circularity = 0.56f; // 56 %
    tempBlob.isolatedImage = imageWithOnlyTheBlobInside;

    this->blobs.push_back(tempBlob);

    */
}

int BlobDetector::getNumBlobs() const
{
    return this->blobs.size();
}

const Blob &BlobDetector::getBlob(int index) const
{
    Q_ASSERT(index < this->blobs.size());

    return this->blobs.at(index);
}
