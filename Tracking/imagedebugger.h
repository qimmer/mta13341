#ifndef IMAGEDEBUGGER_H
#define IMAGEDEBUGGER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class ImageDebugger;
}

class ImageDebugger : public QDialog
{
    Q_OBJECT

public:
    explicit ImageDebugger(QWidget *parent = 0);
    ~ImageDebugger();

protected slots:
    virtual void update() {}

protected:
    virtual void closeEvent(QCloseEvent *e);

    Ui::ImageDebugger *ui;
    QTimer updateTimer;
};

#endif // IMAGEDEBUGGER_H
