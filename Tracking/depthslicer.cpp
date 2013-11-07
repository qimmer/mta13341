#include "depthslicer.h"
#include <QImage>
#include <QColor>

DepthSlicer::DepthSlicer()
{
}

void DepthSlicer::sliceDepth(float *pDepthSrc, float *pDest, float nearDepth, float farDepth, const QSize &size)
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
