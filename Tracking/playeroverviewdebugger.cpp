#include "playeroverviewdebugger.h"
#include "ui_playeroverviewdebugger.h"

PlayerOverviewDebugger::PlayerOverviewDebugger(PlayerTracker *tracker, QWidget *parent) :
    ImageDebugger(parent),
    ov_ui(new Ui::PlayerOverviewDebugger)
{
    qDeleteAll(children());
    ov_ui->setupUi(this);
    this->tracker = tracker;

    this->setWindowTitle("Player Overview");
}

PlayerOverviewDebugger::~PlayerOverviewDebugger()
{
    delete ov_ui;
}

void PlayerOverviewDebugger::update()
{
    ov_ui->lblOverview->setPixmap(QPixmap::fromImage(tracker->getPlayerDebugView()));
}
