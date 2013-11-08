#include "BlobDetector.h"
#include <QColor>

BlobDetector::BlobDetector()
{
}

void BlobDetector::update(const QImage &binaryImage, const QImage& velocityImage, const float *depthValues, float depthThreashold, float minSize)
{
    this->depthThreashold = depthThreashold;

    // Empty the blob container
    this->blobs.clear();

    //Makes an empty blobImg, same size and format as the binaryImage
    QImage blobImg(binaryImage.size(), binaryImage.format());

    //Fills the image with pure white opaque pixels
    memset(blobImg.bits(), 255, blobImg.width()*blobImg.height()*4);

    QColor colors[] = {QColor(Qt::blue),
                       QColor(Qt::red),
                       QColor(Qt::green),
                       QColor(Qt::yellow),
                       QColor(Qt::magenta),
                       QColor(Qt::darkBlue),
                       QColor(Qt::cyan),
                       QColor(Qt::darkGreen)};

    int blobId = 0;

    for(int y = 0; y < binaryImage.size().height(); y++)
    {
        for(int x = 0; x < binaryImage.size().width(); x++)
        {

            QPoint tp(x,y);

            //Grassfire algorithm to find BLOB.
            if (testPixel(binaryImage, blobImg, depthValues, tp))
            {
                const QColor& blobColor = colors[blobId % 8];
                QRect bb;
                float avrDepth = 0.0f;
                int size = grassFire(binaryImage, blobImg, depthValues, x, y, blobColor, bb, avrDepth);

                // Filter noise and very small objects. If the object
                // is big enough, process it!
                if ( size >= minSize )
                {
                    blobId++;

                    Blob b;
                    b.avrDepth = avrDepth;
                    b.size = (float)size/(binaryImage.width()*binaryImage.height());

                    // Calculate resolution independant BB
                    b.boundingBox = QRectF((float)bb.left()/binaryImage.width(),
                                           (float)bb.top()/binaryImage.height(),
                                           (float)bb.right()/binaryImage.width(),
                                           (float)bb.bottom()/binaryImage.height());
                    b.isolateColor(blobImg.copy(bb), blobColor);
                    b.isolateVelocity(velocityImage.copy(bb));

                    // Add the BLOB to our BLOB list
                    this->blobs.push_back(b);

                }
            }
        }
    }
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

void Blob::isolateColor(const QImage &blobImage, const QColor &blobColor)
{
    isolatedImage = blobImage;

    static uint black = QColor(Qt::black).rgb();
    static uint white = QColor(Qt::white).rgb();
    uint blobRgb = blobColor.rgb();

    for( int x = 0; x < isolatedImage.width(); ++x )
        for( int y = 0; y < isolatedImage.height(); ++y )
        {
            if( memcmp(&blobImage.bits()[(x + y*blobImage.width())*4], &blobRgb, 4) != 0 )
            {
                *((QRgb*)&isolatedImage.bits()[(x + y*isolatedImage.width())*4]) = black;
            }
            else
            {
                *((QRgb*)&isolatedImage.bits()[(x + y*isolatedImage.width())*4]) = white;
            }
        }
}

void Blob::isolateVelocity(const QImage &velocity)
{
    velocityImage = velocity;

    static uint black = QColor(Qt::black).rgb();
    static uint white = QColor(Qt::white).rgb();

    for( int x = 0; x < isolatedImage.width(); ++x )
        for( int y = 0; y < isolatedImage.height(); ++y )
        {
            if( memcmp(&isolatedImage.bits()[(x + y*isolatedImage.width())*4], &white, 4) != 0 )
            {
                *((QRgb*)&velocityImage.bits()[(x + y*isolatedImage.width())*4]) = black;
            }
        }
}
