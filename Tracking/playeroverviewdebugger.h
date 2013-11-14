#ifndef PLAYEROVERVIEWDEBUGGER_H
#define PLAYEROVERVIEWDEBUGGER_H

#include <QDialog>
#include "imagedebugger.h"
#include "playertracker.h"

namespace Ui {
class PlayerOverviewDebugger;
}

class PlayerOverviewDebugger : public ImageDebugger
{
    Q_OBJECT

public:
    explicit PlayerOverviewDebugger(PlayerTracker *tracker, QWidget *parent = 0);
    ~PlayerOverviewDebugger();

    virtual void update();

private:
    Ui::PlayerOverviewDebugger *ov_ui;
    PlayerTracker *tracker;
};

#endif // PLAYEROVERVIEWDEBUGGER_H
