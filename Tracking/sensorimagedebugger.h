#ifndef SENSORIMAGEDEBUGGER_H
#define SENSORIMAGEDEBUGGER_H

#include "imagedebugger.h"
#include "sensor.h"

class SensorImageDebugger : public ImageDebugger
{
public:
    SensorImageDebugger(Sensor *sensor, int imageType, QWidget *parent = 0);

    virtual void update();

private:
    Sensor *sensor;
    int typ;
};

#endif // SENSORIMAGEDEBUGGER_H
