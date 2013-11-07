#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensor.h"
#include "utility.h"

#include <QTimer>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->depthThreashold = 1.0f;

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

        velMapper.setDecay(decay);
        velMapper.setMinima(minima);
        velMapper.setMaxima(maxima);
        velMapper.setFactor(factor);
        velMapper.setThreashold(threashold);
        velMapper.setForwardOnly(forwardOnly);
        sensor.setNearClip(nearClip);
        sensor.setFarClip(farClip);

        file.close();
    }

    this->currentBlobId = 0;

    if( sensor.initialize(0, Medium) )
    {        
        ui->chkForward->setChecked(velMapper.isForwardOnly());
        ui->sliDecay->setValue(velMapper.getDecay()*10000);
        ui->sliMinima->setValue(velMapper.getMinima()*3000);
        ui->sliMaxima->setValue(velMapper.getMaxima()*3000);
        ui->sliFactor->setValue(velMapper.getFactor()*1000);
        ui->sliThreashold->setValue(velMapper.getThreashold()*8000);
        ui->sliNear->setValue(sensor.getNearClip());
        ui->sliFar->setValue(sensor.getFarClip());
        ui->sliDepthThreashold->setValue(this->depthThreashold * 1000);


        binaryDepth = QImage(sensor.getDepthImage().size(), QImage::Format_ARGB32);

        connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
        timer.setInterval(10);
        timer.start(10);

    }
}

MainWindow::~MainWindow()
{    
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QFile file("save.dat");

    file.open(QFile::WriteOnly);

    QDataStream stream(&file);
    stream << velMapper.getDecay();
    stream << velMapper.getMinima();
    stream << velMapper.getMaxima();
    stream << velMapper.getFactor();
    stream << velMapper.getThreashold();
    stream << velMapper.isForwardOnly();
    stream << sensor.getNearClip();
    stream << sensor.getFarClip();
    stream << this->depthThreashold;

    file.close();
}

void MainWindow::update()
{
    if( sensor.update() )
    {
        velMapper.update(sensor.getPrevDepthData(), sensor.getDepthData(), sensor.getDepthImage().size());

        Utility::depthToBinary(sensor.getDepthData(), &binaryDepth);

        ui->imgVelocity->setPixmap(QPixmap::fromImage(velMapper.getBinaryImage()));
        ui->imgDepth->setPixmap(QPixmap::fromImage(binaryDepth));

        blobDetector.update(binaryDepth, sensor.getDepthData(), depthThreashold);

        if( blobDetector.getNumBlobs() > currentBlobId )
        {
            ui->imgBlob->setPixmap(QPixmap::fromImage(blobDetector.getBlob(currentBlobId).isolatedImage));
            ui->lblAvrDepth->setText(QString("Blob average depth value: ") + QString::number(blobDetector.getBlob(currentBlobId).avrDepth));
        }
        else
            ui->imgBlob->setText("NO BLOB DETECTED");
    }
}

void MainWindow::on_sliMinima_valueChanged(int value)
{
    velMapper.setMinima((float)value / 3000.0f);
}

void MainWindow::on_sliMaxima_valueChanged(int value)
{
    velMapper.setMaxima((float)value / 3000.0f);
}

void MainWindow::on_sliDecay_valueChanged(int value)
{
    velMapper.setDecay((float)value / 10000.0f);
}

void MainWindow::on_sliFactor_valueChanged(int value)
{
    velMapper.setFactor((float)value / 1000.0f);
}

void MainWindow::on_sliThreashold_valueChanged(int value)
{
    velMapper.setThreashold((float)value / 8000.0f);
}

void MainWindow::on_chkForward_toggled(bool checked)
{
    velMapper.setForwardOnly(checked);
}

void MainWindow::on_sliNear_valueChanged(int value)
{
    sensor.setNearClip(value);
}

void MainWindow::on_sliFar_valueChanged(int value)
{
    sensor.setFarClip(value);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    currentBlobId = value;
}

void MainWindow::on_sliDepthThreashold_valueChanged(int value)
{
    this->depthThreashold = float(value) / 1000.0f;
}
