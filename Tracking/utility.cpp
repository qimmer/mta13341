#include "Utility.h"
#include <QImage>
#include <QColor>
#include "BlobDetector.h"
#include <QPainter>

void Utility::depthToImage(float *pDepthSrc, QImage *image)
{
    for( int x = 0; x < image->width(); ++x )
    {
        for( int y = 0; y < image->height(); ++y )
        {
            // BGRA
            image->bits()[(x + y*image->width())*4] = pDepthSrc[x + y*image->width()] * 255; //Blue
            image->bits()[(x + y*image->width())*4+1] = pDepthSrc[x + y*image->width()] * 255; // Green
            image->bits()[(x + y*image->width())*4+2] = pDepthSrc[x + y*image->width()] * 255; // Red
            image->bits()[(x + y*image->width())*4+3] = 255; // Alpha
        }
    }
}

void Utility::depthToBinary(float *pDepthSrc, QImage *binaryImage)
{
    for( int x = 0; x < binaryImage->width(); ++x )
    {
        for( int y = 0; y < binaryImage->height(); ++y )
        {
            // BGRA (inverse ARGB color channels)
            if( pDepthSrc[x + y*binaryImage->width()] < 0.00001f )
            {
                binaryImage->bits()[(x + y*binaryImage->width())*4] = 0;
                binaryImage->bits()[(x + y*binaryImage->width())*4+1] = 0;
                binaryImage->bits()[(x + y*binaryImage->width())*4+2] = 0;
                binaryImage->bits()[(x + y*binaryImage->width())*4+3] = 255;
            }
            else
            {
                binaryImage->bits()[(x + y*binaryImage->width())*4] = 255;
                binaryImage->bits()[(x + y*binaryImage->width())*4+1] = 255;
                binaryImage->bits()[(x + y*binaryImage->width())*4+2] = 255;
                binaryImage->bits()[(x + y*binaryImage->width())*4+3] = 255;
            }
        }
    }
}
