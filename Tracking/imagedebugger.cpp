#include "imagedebugger.h"
#include "ui_imagedebugger.h"

ImageDebugger::ImageDebugger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDebugger)
{
    ui->setupUi(this);

    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer.start(33);
}

ImageDebugger::~ImageDebugger()
{
    delete ui;
}

void ImageDebugger::closeEvent(QCloseEvent *e)
{
    delete this;
}
