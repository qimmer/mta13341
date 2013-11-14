#include "sensorimagedebugger.h"
#include "ui_imagedebugger.h"
#include "utility.h"

SensorImageDebugger::SensorImageDebugger(Sensor *sensor, int imageType, QWidget *parent) : ImageDebugger(parent)
{
    this->sensor = sensor;
    this->typ = imageType;

    if( this->typ == 0 )
    {
        this->setWindowTitle("Depth Image");
    }

    if( this->typ == 1 )
    {
        this->setWindowTitle("Binary Depth Image");
    }
}

void SensorImageDebugger::update()
{
    QImage binaryDepth;

    // Depth Image
    if( this->typ == 0 )
        this->ui->lblImage->setPixmap(QPixmap::fromImage(sensor->getDepthImage()));

    // Binary Depth
    if( this->typ == 1 )
    {
        binaryDepth = QImage(sensor->getDepthImage().size(), sensor->getDepthImage().format());
        Utility::depthToBinary(sensor->getDepthData(), &binaryDepth);
        this->ui->lblImage->setPixmap(QPixmap::fromImage(binaryDepth));
    }
}
