#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensor.h"
#include "utility.h"

#include <QTimer>
#include <QFile>

DebugWindow::DebugWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->depthThreashold = 1.0f;
    this->armSize = 0.1f;

    QFile file("save.dat");
    if( file.exists() )
    {
        file.open(QFile::ReadOnly);

        float decay, minima, maxima, factor, threashold;
        ushort nearClip, farClip;
        bool forwardOnly;

        QDataStream stream(&file);
        stream >> decay;
        stream >> minima;
        stream >> maxima;
        stream >> factor;
        stream >> threashold;
        stream >> forwardOnly;
        stream >> nearClip;
        stream >> farClip;
        stream >> this->depthThreashold;
        stream >> this->minSize;
        stream >> this->armSize;

        sensor.getVelocityMapper()->setDecay(decay);
        sensor.getVelocityMapper()->setMinima(minima);
        sensor.getVelocityMapper()->setMaxima(maxima);
        sensor.getVelocityMapper()->setFactor(factor);
        sensor.getVelocityMapper()->setThreashold(threashold);
        sensor.getVelocityMapper()->setForwardOnly(forwardOnly);
        sensor.setNearClip(nearClip);
        sensor.setFarClip(farClip);

        file.close();
    }

    this->currentBlobId = 0;

    if( sensor.initialize(0, Medium) )
    {        
        ui->chkForward->setChecked(sensor.getVelocityMapper()->isForwardOnly());
        ui->sliDecay->setValue(sensor.getVelocityMapper()->getDecay()*10000);
        ui->sliMinima->setValue(sensor.getVelocityMapper()->getMinima()*3000);
        ui->sliMaxima->setValue(sensor.getVelocityMapper()->getMaxima()*3000);
        ui->sliFactor->setValue(sensor.getVelocityMapper()->getFactor()*1000);
        ui->sliThreashold->setValue(sensor.getVelocityMapper()->getThreashold()*8000);
        ui->sliNear->setValue(sensor.getNearClip());
        ui->sliFar->setValue(sensor.getFarClip());
        ui->sliDepthThreashold->setValue(this->depthThreashold * 1000);
        ui->sliMinSize->setValue(this->minSize);
        ui->sliArmSize->setValue(armSize * 1000);

        binaryDepth = QImage(sensor.getDepthImage().size(), QImage::Format_ARGB32);

        connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
        timer.setInterval(10);
        timer.start(10);
    }

    ui->cmbDebugImage->addItem("Depth");
    ui->cmbDebugImage->addItem("Binary Depth");
    ui->cmbDebugImage->addItem("Blob");
    ui->cmbDebugImage->addItem("Blob Velocity");

}

DebugWindow::~DebugWindow()
{    
    delete ui;
}

void DebugWindow::closeEvent(QCloseEvent *e)
{
    QFile file("save.dat");

    file.open(QFile::WriteOnly);

    QDataStream stream(&file);
    stream << sensor.getVelocityMapper()->getDecay();
    stream << sensor.getVelocityMapper()->getMinima();
    stream << sensor.getVelocityMapper()->getMaxima();
    stream << sensor.getVelocityMapper()->getFactor();
    stream << sensor.getVelocityMapper()->getThreashold();
    stream << sensor.getVelocityMapper()->isForwardOnly();
    stream << sensor.getNearClip();
    stream << sensor.getFarClip();
    stream << this->depthThreashold;
    stream << this->minSize;
    stream << this->armSize;

    file.close();
}

void DebugWindow::update()
{
    if( sensor.update() )
    {
        QImage depthImage;
        Utility::depthToImage(sensor.getDepthData(), &depthImage);
        Utility::depthToBinary(sensor.getDepthData(), &binaryDepth);

        debugImages["Depth"] = depthImage;
        debugImages["Binary Depth"] = binaryDepth;

        blobDetector.update(
                    binaryDepth,
                    sensor.getVelocityMapper()->getBinaryImage(),
                    sensor.getDepthData(),
                    this->depthThreashold,
                    this->minSize,
                    this->armSize);

        if( blobDetector.getNumBlobs() > currentBlobId )
        {
            debugImages["Blob"] = blobDetector.getBlob(currentBlobId).isolatedImage;
            debugImages["Blob Velocity"] = blobDetector.getBlob(currentBlobId).velocityImage;
        }
        else
        {
            debugImages["Blob"] = depthImage;
            debugImages["Blob Velocity"] = depthImage;
        }

        if( debugImages.contains(currentDebugImage) )
        {
            ui->imgDebug->setPixmap(QPixmap::fromImage(debugImages[currentDebugImage]));
        }


    }
}

void DebugWindow::on_sliMinima_valueChanged(int value)
{
    sensor.getVelocityMapper()->setMinima((float)value / 3000.0f);
}

void DebugWindow::on_sliMaxima_valueChanged(int value)
{
    sensor.getVelocityMapper()->setMaxima((float)value / 3000.0f);
}

void DebugWindow::on_sliDecay_valueChanged(int value)
{
    sensor.getVelocityMapper()->setDecay((float)value / 10000.0f);
}

void DebugWindow::on_sliFactor_valueChanged(int value)
{
    sensor.getVelocityMapper()->setFactor((float)value / 1000.0f);
}

void DebugWindow::on_sliThreashold_valueChanged(int value)
{
    sensor.getVelocityMapper()->setThreashold((float)value / 8000.0f);
}

void DebugWindow::on_chkForward_toggled(bool checked)
{
    sensor.getVelocityMapper()->setForwardOnly(checked);
}

void DebugWindow::on_sliNear_valueChanged(int value)
{
    sensor.setNearClip(value);
}

void DebugWindow::on_sliFar_valueChanged(int value)
{
    sensor.setFarClip(value);
}

void DebugWindow::on_horizontalSlider_valueChanged(int value)
{
    currentBlobId = value;
}

void DebugWindow::on_sliDepthThreashold_valueChanged(int value)
{
    this->depthThreashold = float(value) / 1000.0f;
}

void DebugWindow::on_sliMinSize_valueChanged(int value)
{
    this->minSize = (float)value / 1000;
}

void DebugWindow::on_cmbDebugImage_currentTextChanged(const QString &arg1)
{
    currentDebugImage = arg1;
}

void DebugWindow::on_sliArmSize_valueChanged(int value)
{
    armSize = (float)value / 1000;
}
