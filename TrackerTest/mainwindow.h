#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>
#include "sensor.h"
#include "velocitymapper.h"
#include "BlobDetector.h"

namespace Ui {
class MainWindow;
}

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0);

    ~DebugWindow();

protected:
    virtual void closeEvent(QCloseEvent *e);

public slots:
    void update();

private slots:
    void on_sliMinima_valueChanged(int value);

    void on_sliMaxima_valueChanged(int value);

    void on_sliDecay_valueChanged(int value);

    void on_sliFactor_valueChanged(int value);

    void on_sliThreashold_valueChanged(int value);

    void on_chkForward_toggled(bool checked);

    void on_sliNear_valueChanged(int value);

    void on_sliFar_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_sliDepthThreashold_valueChanged(int value);

    void on_sliMinSize_valueChanged(int value);

    void on_cmbDebugImage_currentTextChanged(const QString &arg1);

    void on_sliArmSize_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QTimer timer;
    Sensor sensor;

    QImage binaryDepth;
    int currentBlobId;
    float depthThreashold;
    float armSize;
    float minSize;
    QString currentDebugImage;

    QMap<QString, QImage> debugImages;
};

#endif // MAINWINDOW_H
