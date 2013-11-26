/********************************************************************************
** Form generated from reading UI file 'playeroverviewdebugger.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYEROVERVIEWDEBUGGER_H
#define UI_PLAYEROVERVIEWDEBUGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PlayerOverviewDebugger
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lblOverview;

    void setupUi(QDialog *PlayerOverviewDebugger)
    {
        if (PlayerOverviewDebugger->objectName().isEmpty())
            PlayerOverviewDebugger->setObjectName(QStringLiteral("PlayerOverviewDebugger"));
        PlayerOverviewDebugger->resize(400, 300);
        horizontalLayout = new QHBoxLayout(PlayerOverviewDebugger);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblOverview = new QLabel(PlayerOverviewDebugger);
        lblOverview->setObjectName(QStringLiteral("lblOverview"));

        horizontalLayout->addWidget(lblOverview);


        retranslateUi(PlayerOverviewDebugger);

        QMetaObject::connectSlotsByName(PlayerOverviewDebugger);
    } // setupUi

    void retranslateUi(QDialog *PlayerOverviewDebugger)
    {
        PlayerOverviewDebugger->setWindowTitle(QApplication::translate("PlayerOverviewDebugger", "Dialog", 0));
        lblOverview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayerOverviewDebugger: public Ui_PlayerOverviewDebugger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYEROVERVIEWDEBUGGER_H
