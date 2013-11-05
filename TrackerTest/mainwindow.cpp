#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage imgOne;
    imgOne.load("depth.png");

    QImage imgTwo;



    ui->imgOne->setPixmap(QPixmap::fromImage(imgOne));
    ui->imgTwo->setPixmap(QPixmap::fromImage(imgTwo));
}

MainWindow::~MainWindow()
{
    delete ui;
}
