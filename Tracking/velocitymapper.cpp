#include "velocitymapper.h"
#include <QColor>
#include <QFile>
#include <QDataStream>

VelocityMapper::VelocityMapper() : QObject(0)
{
    forwardOnly = false;
    decay = 0;
    minima = 0;
    maxima = 0;
    factor = 0;
    threashold = 0;
    velocityMap = 0;
}

VelocityMapper::~VelocityMapper()
{
    if( velocityMap )
        delete[] velocityMap;
}

void VelocityMapper::update(float *oldDepthData, float *newDepthData, const QSize& size)
{
    if( velocityMap == 0 )
        velocityMap = new float[size.width()*size.height()];

    if( binary.isNull() )
    {
        binary = QImage(size, QImage::Format_ARGB32);
        binary.fill(Qt::black);
    }

    uchar *binaryPixels = binary.bits();

    for( int x = 0; x < size.width(); ++x )
    {
        for( int y = 0; y < size.height(); ++y )
        {
            uchar *binaryRgb = &binaryPixels[(x+y*size.width())*4];
            float *velocityPixel = &velocityMap[x+y*size.width()];

            float oldDepth = oldDepthData[x + y*size.width()];
            float newDepth = newDepthData[x + y*size.width()];
            float velocity = -(newDepth - oldDepth);

            /*if( oldDepth < 0.00001f ||
                newDepth < 0.00001f ||
                oldDepth > 0.99999f ||
                newDepth > 0.99999f )
                velocity = 0.0f;*/

            if( forwardOnly )
            {
                if( velocity < 0 )
                    velocity = 0.0f;
            }
            else
            {
                velocity = fabsf(velocity);
            }

            if( velocity < minima || velocity > maxima )
            {
                velocity = 0.0f;
            }


            // Is the changing depth artificial or not moving?
            if( velocity > 0.0f )
                *velocityPixel = std::min(*velocityPixel + velocity*factor, 1.0f);
            else
                *velocityPixel = std::max(*velocityPixel - decay, 0.0f);

            if( *velocityPixel > threashold )
                binaryRgb[0] = binaryRgb[1] = binaryRgb[2] = 255;
            else
                binaryRgb[0] = binaryRgb[1] = binaryRgb[2] = 0;

            binaryRgb[3] = 255;
        }
    }
}

float *VelocityMapper::getVelocityMap() const
{
    return velocityMap;
}

const QImage &VelocityMapper::getBinaryImage() const
{
    return binary;
}

float VelocityMapper::getMinima() const
{
    return this->minima;
}

float VelocityMapper::getMaxima() const
{
    return this->maxima;
}

float VelocityMapper::getDecay() const
{
    return this->decay;
}

float VelocityMapper::getFactor() const
{
    return this->factor;
}

bool VelocityMapper::isForwardOnly() const
{
    return this->forwardOnly;
}

float VelocityMapper::getThreashold() const
{
    return this->threashold;
}

void VelocityMapper::setMinima(float minima)
{
    this->minima = minima;
}

void VelocityMapper::setMaxima(float maxima)
{
    this->maxima = maxima;
}

void VelocityMapper::setDecay(float decay)
{
    this->decay = decay;
}

void VelocityMapper::setFactor(float factor)
{
    this->factor = factor;
}

void VelocityMapper::setForwardOnly(bool fwOnly)
{
    this->forwardOnly = fwOnly;
}

void VelocityMapper::setThreashold(float t)
{
    this->threashold = t;
}
