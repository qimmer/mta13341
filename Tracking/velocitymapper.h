#ifndef VELOCITYMAPPER_H
#define VELOCITYMAPPER_H

#include "tracking_global.h"
#include <QImage>

class TRACKINGSHARED_EXPORT VelocityMapper : public QObject
{
    Q_OBJECT
public:
    explicit VelocityMapper();

    void update(ushort *depthData, short *velData, const QSize& size);

    const QImage& getVelocityMap() const;
    const QImage& getBinaryImage() const;

    int getThreashold() const;

public slots:
    void setMinima(int minima);
    void setMaxima(int maxima);
    void setDecay(int decay);
    void setFactor(int factor);
    void setForwardOnly(bool fwOnly);
    void setThreashold(int t);

private:
    QImage intermediate, binary;
    int minima, maxima, decay, factor, threashold;
    bool forwardOnly;

};

#endif // VELOCITYMAPPER_H
