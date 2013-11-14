#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>
#include "sensor.h"
#include "velocitymapper.h"
#include "BlobDetector.h"
#include "imagedebugger.h"

class PlayerTracker;

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugWindow(PlayerTracker *tracker, QWidget *parent = 0);

    ~DebugWindow();

    void update();

    Ui::DebugWindow *ui;

protected:
    virtual void closeEvent(QCloseEvent *e);

private slots:
    void on_sliMinima_valueChanged(int value);
    void on_sliMaxima_valueChanged(int value);
    void on_sliFactor_valueChanged(int value);
    void on_sliThreashold_valueChanged(int value);
    void on_sliNear_valueChanged(int value);
    void on_sliFar_valueChanged(int value);
    void on_sliDepthThreashold_valueChanged(int value);
    void on_sliMinSize_valueChanged(int value);
    void on_sliArmSize_valueChanged(int value);

    void on_actionDepth_Image_triggered();

    void on_actionVelocity_triggered();

    void on_actionBinary_triggered();

    void on_actionBinary_Depth_image_triggered();

    void on_actionColor_triggered();

    void on_actionPlayer_Overview_triggered();

private:
    PlayerTracker *tracker;

    float depthThreashold;
    float armSize;
    float minSize;


};

#endif // DEBUGWINDOW_H
