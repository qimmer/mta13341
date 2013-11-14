#ifndef BLOBIMAGEDEBUGGER_H
#define BLOBIMAGEDEBUGGER_H

#include <QDialog>
#include "imagedebugger.h"
#include "BlobDetector.h"

namespace Ui {
class BlobImageDebugger;
}

class BlobImageDebugger : public ImageDebugger
{
    Q_OBJECT

public:
    explicit BlobImageDebugger(BlobDetector *blobDetector, int imageType, QWidget *parent = 0);
    ~BlobImageDebugger();

    virtual void update();

private:
    Ui::BlobImageDebugger *blob_ui;
    BlobDetector *blobDetector;
    int imageType;
};

#endif // BLOBIMAGEDEBUGGER_H
