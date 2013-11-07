#include "velocitymapper.h"
#include <QColor>

VelocityMapper::VelocityMapper() : QObject(0)
{
    forwardOnly = false;
    decay = 0;
    minima = 0;
    maxima = 0;
    factor = 0;
    threashold = 0;
}

void VelocityMapper::update(ushort *depthData, short *velData, const QSize& size)
{

    if( intermediate.isNull() )
    {
        intermediate = QImage(size, QImage::Format_ARGB32);
        intermediate.fill(Qt::black);

        binary = QImage(size, QImage::Format_ARGB32);
        intermediate.fill(Qt::black);
    }

    uchar *interPixels = intermediate.bits();
    uchar *binaryPixels = binary.bits();

    for( int x = 0; x < size.width(); ++x )
    {
        for( int y = 0; y < size.height(); ++y )
        {
            uchar *interRgb = &interPixels[(x+y*size.width())*4];
            uchar *binaryRgb = &binaryPixels[(x+y*size.width())*4];

            ushort depth = depthData[x + y*size.width()];

            if( depth == 0 || depth == 255 )
            {
                interRgb[2] = std::max(interRgb[2] - decay, 0);
                continue;
            }

            double difference = -((double)velData[x + y*size.width()]);
            if( forwardOnly )
            {
                if( difference < 0 )
                    difference = 0;
            }
            else
            {
                difference = abs(difference);
            }
            difference = sqrt(difference);

            if( difference > maxima || difference < minima )
                difference = 0;

            // Is the changing depth artificial or not moving?
            if( difference > 0 )
                interRgb[2] = std::min(interRgb[2] + int((double)difference*(double(factor)/100.0f)), 255);
            else
                interRgb[2] = std::max(interRgb[2] - decay, 0);

            interRgb[0] = interRgb[1] = interRgb[2];
            interRgb[3] = 255;

            if( interRgb[2] > threashold )
                binaryRgb[0] = binaryRgb[1] = binaryRgb[2] = 255;
            else
                binaryRgb[0] = binaryRgb[1] = binaryRgb[2] = 0;

            binaryRgb[3] = 255;
        }
    }
}

const QImage &VelocityMapper::getVelocityMap() const
{
    return intermediate;
}

const QImage &VelocityMapper::getBinaryImage() const
{
    return binary;
}

int VelocityMapper::getThreashold() const
{
    return this->threashold;
}

void VelocityMapper::setMinima(int minima)
{
    this->minima = minima;
}

void VelocityMapper::setMaxima(int maxima)
{
    this->maxima = maxima;
}

void VelocityMapper::setDecay(int decay)
{
    this->decay = decay;
}

void VelocityMapper::setFactor(int factor)
{
    this->factor = factor;
}

void VelocityMapper::setForwardOnly(bool fwOnly)
{
    this->forwardOnly = fwOnly;
}

void VelocityMapper::setThreashold(int t)
{
    this->threashold = t;
}
