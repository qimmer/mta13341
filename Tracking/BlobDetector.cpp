#include "BlobDetector.h"
#include <QColor>

BlobDetector::BlobDetector()
{
}

void BlobDetector::update(const QImage &binaryImage, const float *depthValues, float depthThreashold, int minSize)
{
    this->depthThreashold = depthThreashold;

    int largestBlob = 0;
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

    //Makes an empty blobImg, same size and format as the binaryImage
    QImage blobImg(binaryImage.size(), binaryImage.format());
    //blobImg.fill(QColor(Qt::black));
    memset(blobImg.bits(), 255, blobImg.width()*blobImg.height()*4);

    QColor colors[] = {QColor(Qt::blue),
                       QColor(Qt::blue),
                       QColor(Qt::blue),
                       QColor(Qt::blue),
                       QColor(Qt::blue)};

    int blobId = 0;

    for(int y = 0; y < binaryImage.size().height(); y++)
    {
        for(int x = 0; x < binaryImage.size().width(); x++)
        {

            QPoint tp(x,y);

            //Grassfire algorithm to find BLOB.
            if (testPixel(binaryImage, blobImg, depthValues, tp))
            {
                QRect bb;
                float avrDepth = 0.0f;
                int size = grassFire(binaryImage, blobImg, depthValues, x, y, colors[blobId % 5], bb, avrDepth);

                if( size > largestBlob )
                    largestBlob = size;

                // Filter noise and very small objects
                if ( size >= minSize )
                {
                    blobId++;
                    Blob b;
                    b.avrDepth = avrDepth;
                    b.pixelCount = size;
                    b.boundingBox = bb;
                    b.isolatedImage = blobImg.copy(b.boundingBox);

                    this -> blobs.push_back(b);

                }
            }


            //Area


            //Circularity - remove BLOB's which do not have a circle on top


            //Bounding box for ROI


        }
    }

    qSort(this->blobs);
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

int BlobDetector::grassFire(const QImage &image, QImage &blobImg, const float *depthValues, int x, int y, QColor color, QRect& boundingBox, float& avrDepth)
{
    static QList<QPoint> pendingPixels;

    pendingPixels.clear();

    pendingPixels.push_back(QPoint(x,y));

    int size = 0;
    boundingBox.setX(x);
    boundingBox.setY(y);
    boundingBox.setWidth(1);
    boundingBox.setHeight(1);

    while( pendingPixels.size() > 0 )
    {
        size++;
        QPoint p = pendingPixels.back();
        pendingPixels.pop_back();

        // Update bounding box
        if( p.x() < boundingBox.left() )
            boundingBox.setLeft(p.x());

        if( p.y() < boundingBox.top() )
            boundingBox.setTop(p.y());

        if( p.x() > boundingBox.right() )
            boundingBox.setRight(p.x());

        if( p.y() > boundingBox.bottom() )
            boundingBox.setBottom(p.y());

        //Burn pixel
        blobImg.setPixel(p.x(), p.y(), color.rgb());
        avrDepth += depthValues[p.x() + p.y()*image.width()];

        //Kernal 4-connectivity
        //1
        QPoint tp = QPoint(p.x()+1, p.y());
        if( testPixel(image, blobImg, depthValues, tp) )
            pendingPixels.push_back(tp);

        //2
        tp = QPoint(p.x(), p.y()+1);
        if( testPixel(image, blobImg, depthValues, tp) )
            pendingPixels.push_back(tp);

        //3
        tp = QPoint(p.x()-1, p.y());
        if( testPixel(image, blobImg, depthValues, tp) )
            pendingPixels.push_back(tp);

        //4
        tp = QPoint(p.x(), p.y()-1);
        if( testPixel(image, blobImg, depthValues, tp) )
            pendingPixels.push_back(tp);

    }

    avrDepth /= size;

    return size;

}

bool BlobDetector::testPixel(const QImage &image, QImage &blobImg, const float *depthValues, const QPoint &p)
{
    static uint black = QColor(Qt::white).rgb();

    if( p.x() < 0 || p.x() >= image.width() || p.y() < 0 || p.y() >= image.height() )
        return false;

    // Eventually check depth values
    if( depthValues )
    {
        QPoint dp(p.x(), p.y());
        float referenceDepth = depthValues[dp.x() + dp.y()*image.width()];

        dp = QPoint(p.x() + 1, p.y());
        if( dp.x() >= 0 && dp.y() >= 0 && dp.x() < image.width() && dp.y() < image.height() )
            if( fabsf(depthValues[dp.x() + dp.y()*image.width()] - referenceDepth) > depthThreashold )
                return false;

        dp = QPoint(p.x() - 1, p.y());
        if( dp.x() >= 0 && dp.y() >= 0 && dp.x() < image.width() && dp.y() < image.height() )
            if( fabsf(depthValues[dp.x() + dp.y()*image.width()] - referenceDepth) > depthThreashold )
                return false;

        dp = QPoint(p.x(), p.y() + 1);
        if( dp.x() >= 0 && dp.y() >= 0 && dp.x() < image.width() && dp.y() < image.height() )
            if( fabsf(depthValues[dp.x() + dp.y()*image.width()] - referenceDepth) > depthThreashold )
                return false;

        dp = QPoint(p.x(), p.y() - 1);
        if( dp.x() >= 0 && dp.y() >= 0 && dp.x() < image.width() && dp.y() < image.height() )
            if( fabsf(depthValues[dp.x() + dp.y()*image.width()] - referenceDepth) > depthThreashold )
                return false;

    }

    if (qGray(image.pixel(p.x(), p.y())) > 127 &&
            blobImg.pixel(p.x(), p.y()) == black )
    {
        return true;
    }

    return false;
}



bool Blob::operator <(const Blob &blob) const
{
    return this->avrDepth < blob.avrDepth;
}
