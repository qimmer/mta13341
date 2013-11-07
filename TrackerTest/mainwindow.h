#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "sensor.h"
#include "velocitymapper.h"

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
};

#endif // MAINWINDOW_H
