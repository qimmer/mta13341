#include "depthslicer.h"
#include <QImage>
#include <QColor>

DepthSlicer::DepthSlicer()
{
}

void DepthSlicer::sliceImage(const QImage &img, int slices)
{
    this->slices.clear();

    for( int i = 0; i < slices; ++i )
    {
        QImage slice(img.size(), img.format());

        for( int x = 0; x < img.width(); ++x )
        {
            for( int y = 0; y < img.height(); ++y )
            {
                QColor pixel = QColor(img.pixel(x, y));

                if( pixel.red() > 0 && pixel.red() < 255 )
                {
                    if( pixel.redF() >= i / slices &&
                        pixel.redF() < (i+1) / slices )
                        slice.setPixel(x, y, pixel.rgb());
                    else
                        slice.setPixel(x, y, QColor(0, 0, 0).rgb());
                }
            }
        }

        this->slices.push_back(slice);
    }
}

const QImage &DepthSlicer::getSlice(int slice) const
{
    Q_ASSERT(slice < slices.count() && "Slice ID out of range");

    return slices.at(slice);
}
