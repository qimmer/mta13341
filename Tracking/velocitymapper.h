#ifndef VELOCITYMAPPER_H
#define VELOCITYMAPPER_H

#include "tracking_global.h"
#include <QImage>

class TRACKINGSHARED_EXPORT VelocityMapper : public QObject
{
    Q_OBJECT
public:
    explicit VelocityMapper();
    virtual ~VelocityMapper();

    void update(float *oldDepthData, float *newDepthData, const QSize& size);

    float * getVelocityMap() const;
    const QImage& getBinaryImage() const;

    float getMinima() const;
    float getMaxima() const;
    float getFactor() const;
    bool isForwardOnly() const;
    float getThreashold() const;

public slots:
    void setMinima(float minima);
    void setMaxima(float maxima);
    void setFactor(float factor);
    void setForwardOnly(bool fwOnly);
    void setThreashold(float t);

private:
    QImage binary;
    float *velocityMap;
    float minima, maxima, factor, threashold;
    bool forwardOnly;

};

#endif // VELOCITYMAPPER_H
