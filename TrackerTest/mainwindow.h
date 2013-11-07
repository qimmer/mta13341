#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "sensor.h"
#include "velocitymapper.h"
#include "BlobDetector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void update();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    Sensor sensor;
    VelocityMapper velMapper;
    BlobDetector blobDetector;
};

#endif // MAINWINDOW_H
