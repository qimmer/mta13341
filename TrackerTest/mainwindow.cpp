#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensor.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if( sensor.initialize(0, Medium) )
    {
        connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
        timer.setInterval(1);
        timer.start(1);

        connect(ui->sliDecay,
                SIGNAL(valueChanged(int)),
                &velMapper,
                SLOT(setDecay(int)));

        connect(ui->sliMinima,
                SIGNAL(valueChanged(int)),
                &velMapper,
                SLOT(setMinima(int)));

        connect(ui->sliMaxima,
                SIGNAL(valueChanged(int)),
                &velMapper,
                SLOT(setMaxima(int)));

        connect(ui->sliFactor,
                SIGNAL(valueChanged(int)),
                &velMapper,
                SLOT(setFactor(int)));

        connect(ui->sliThreashold,
                SIGNAL(valueChanged(int)),
                &velMapper,
                SLOT(setThreashold(int)));

        connect(ui->chkForward,
                SIGNAL(toggled(bool)),
                &velMapper,
                SLOT(setForwardOnly(bool)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    if( sensor.update() )
    {
        velMapper.update(sensor.getDepthData(), sensor.getVelocityData(), sensor.getDepthImage().size());
        ui->imgOne->setPixmap(QPixmap::fromImage(velMapper.getBinaryImage()));
        ui->orig->setPixmap(QPixmap::fromImage(sensor.getDepthImage()));
    }
}
