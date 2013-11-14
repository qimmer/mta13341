#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "sensorimagedebugger.h"
#include "playertracker.h"
#include "blobimagedebugger.h"
#include "playeroverviewdebugger.h"

DebugWindow::DebugWindow(PlayerTracker *tracker, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
    this->tracker = tracker;
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::closeEvent(QCloseEvent *e)
{
    this->setVisible(false);
}

void DebugWindow::on_sliMinima_valueChanged(int value)
{
    tracker->setParameter(TP_VEL_MIN, (float)value / 1000.0f);
}

void DebugWindow::on_sliMaxima_valueChanged(int value)
{
    tracker->setParameter(TP_VEL_MAX, (float)value / 1000.0f);
}

void DebugWindow::on_sliFactor_valueChanged(int value)
{
    tracker->setParameter(TP_VEL_FACTOR, (float)value / 1000.0f);
}

void DebugWindow::on_sliThreashold_valueChanged(int value)
{
    tracker->setParameter(TP_VEL_THREASHOLD, (float)value / 1000.0f);
}

void DebugWindow::on_sliNear_valueChanged(int value)
{
    tracker->setParameter(TP_NEAR_CLIP, (float)value / 1000.0f);
}

void DebugWindow::on_sliFar_valueChanged(int value)
{
    tracker->setParameter(TP_FAR_CLIP, (float)value / 1000.0f);
}

void DebugWindow::on_sliDepthThreashold_valueChanged(int value)
{
    tracker->setParameter(TP_DEPTH_THREASHOLD, (float)value / 1000.0f);
}

void DebugWindow::on_sliMinSize_valueChanged(int value)
{
    tracker->setParameter(TP_MIN_BLOB_SIZE, (float)value / 1000.0f);
}

void DebugWindow::on_sliArmSize_valueChanged(int value)
{
    tracker->setParameter(TP_ARM_SIZE, (float)value / 1000.0f);
}

void DebugWindow::on_actionDepth_Image_triggered()
{
    ImageDebugger *imgDeb = new SensorImageDebugger(this->tracker->getSensor(), 0, this);
    imgDeb->show();
}

void DebugWindow::on_actionVelocity_triggered()
{
    ImageDebugger *imgDeb = new BlobImageDebugger(this->tracker->getBlobDetector(), 1, this);
    imgDeb->show();
}

void DebugWindow::on_actionBinary_triggered()
{
    ImageDebugger *imgDeb = new BlobImageDebugger(this->tracker->getBlobDetector(), 0, this);
    imgDeb->show();
}

void DebugWindow::on_actionBinary_Depth_image_triggered()
{
    ImageDebugger *imgDeb = new SensorImageDebugger(this->tracker->getSensor(), 1, this);
    imgDeb->show();
}

void DebugWindow::on_actionColor_triggered()
{
    ImageDebugger *imgDeb = new BlobImageDebugger(this->tracker->getBlobDetector(), 2, this);
    imgDeb->show();
}

void DebugWindow::on_actionPlayer_Overview_triggered()
{
    ImageDebugger *imgDeb = new PlayerOverviewDebugger(this->tracker, this);
    imgDeb->show();
}
