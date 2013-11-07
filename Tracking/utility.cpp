#include "Utility.h"
#include <QImage>
#include <QColor>

void Utility::sliceDepth(float *pDepthSrc, float *pDest, float nearDepth, float farDepth, const QSize &size)
{
    for( int x = 0; x < size.width(); ++x )
    {
        for( int y = 0; y < size.height(); ++y )
        {
            if( pDepthSrc[x + y*size.width()] > nearDepth && pDepthSrc[x + y*size.width()] < farDepth )
                pDest[x + y*size.width()] = pDepthSrc[x + y*size.width()];
            else
                pDest[x + y*size.width()] = 0.0f;
        }
    }
}


void Utility::depthToBinary(float *pDepthSrc, QImage *binaryImage)
{
    for( int x = 0; x < binaryImage->width(); ++x )
    {
        for( int y = 0; y < binaryImage->height(); ++y )
        {
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
