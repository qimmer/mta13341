/********************************************************************************
** Form generated from reading UI file 'debugwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWindow
{
public:
    QAction *actionDepth_Image;
    QAction *actionBinary_Depth_image;
    QAction *actionPlayer_Overview;
    QAction *actionColoured;
    QAction *actionVelocity;
    QAction *actionBinary;
    QAction *actionClose;
    QAction *actionColor;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QSlider *sliMinSize;
    QLabel *label_12;
    QSlider *sliDepthThreashold;
    QLabel *label_8;
    QSlider *sliArmSize;
    QGroupBox *grpVelocity;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *sliMinima;
    QLabel *label_2;
    QSlider *sliMaxima;
    QLabel *label_4;
    QSlider *sliFactor;
    QLabel *label_5;
    QSlider *sliThreashold;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QSlider *sliNear;
    QLabel *label_7;
    QSlider *sliFar;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuView;
    QMenu *menuBlob;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DebugWindow)
    {
        if (DebugWindow->objectName().isEmpty())
            DebugWindow->setObjectName(QStringLiteral("DebugWindow"));
        DebugWindow->resize(282, 751);
        actionDepth_Image = new QAction(DebugWindow);
        actionDepth_Image->setObjectName(QStringLiteral("actionDepth_Image"));
        actionBinary_Depth_image = new QAction(DebugWindow);
        actionBinary_Depth_image->setObjectName(QStringLiteral("actionBinary_Depth_image"));
        actionPlayer_Overview = new QAction(DebugWindow);
        actionPlayer_Overview->setObjectName(QStringLiteral("actionPlayer_Overview"));
        actionColoured = new QAction(DebugWindow);
        actionColoured->setObjectName(QStringLiteral("actionColoured"));
        actionVelocity = new QAction(DebugWindow);
        actionVelocity->setObjectName(QStringLiteral("actionVelocity"));
        actionBinary = new QAction(DebugWindow);
        actionBinary->setObjectName(QStringLiteral("actionBinary"));
        actionClose = new QAction(DebugWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionColor = new QAction(DebugWindow);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        centralWidget = new QWidget(DebugWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(6, 6, 6, 6);
        verticalGroupBox = new QGroupBox(centralWidget);
        verticalGroupBox->setObjectName(QStringLiteral("verticalGroupBox"));
        verticalLayout_6 = new QVBoxLayout(verticalGroupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(10, 10, 10, 10);
        label_9 = new QLabel(verticalGroupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_6->addWidget(label_9);

        sliMinSize = new QSlider(verticalGroupBox);
        sliMinSize->setObjectName(QStringLiteral("sliMinSize"));
        sliMinSize->setMinimum(0);
        sliMinSize->setMaximum(1000);
        sliMinSize->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(sliMinSize);

        label_12 = new QLabel(verticalGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_6->addWidget(label_12);

        sliDepthThreashold = new QSlider(verticalGroupBox);
        sliDepthThreashold->setObjectName(QStringLiteral("sliDepthThreashold"));
        sliDepthThreashold->setMaximum(200);
        sliDepthThreashold->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(sliDepthThreashold);

        label_8 = new QLabel(verticalGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);

        sliArmSize = new QSlider(verticalGroupBox);
        sliArmSize->setObjectName(QStringLiteral("sliArmSize"));
        sliArmSize->setMaximum(1000);
        sliArmSize->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(sliArmSize);


        verticalLayout_7->addWidget(verticalGroupBox);

        grpVelocity = new QGroupBox(centralWidget);
        grpVelocity->setObjectName(QStringLiteral("grpVelocity"));
        verticalLayout = new QVBoxLayout(grpVelocity);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(grpVelocity);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        sliMinima = new QSlider(grpVelocity);
        sliMinima->setObjectName(QStringLiteral("sliMinima"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sliMinima->sizePolicy().hasHeightForWidth());
        sliMinima->setSizePolicy(sizePolicy1);
        sliMinima->setMinimum(0);
        sliMinima->setMaximum(100);
        sliMinima->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliMinima);

        label_2 = new QLabel(grpVelocity);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_2);

        sliMaxima = new QSlider(grpVelocity);
        sliMaxima->setObjectName(QStringLiteral("sliMaxima"));
        sizePolicy1.setHeightForWidth(sliMaxima->sizePolicy().hasHeightForWidth());
        sliMaxima->setSizePolicy(sizePolicy1);
        sliMaxima->setMaximum(1000);
        sliMaxima->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliMaxima);

        label_4 = new QLabel(grpVelocity);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_4);

        sliFactor = new QSlider(grpVelocity);
        sliFactor->setObjectName(QStringLiteral("sliFactor"));
        sizePolicy1.setHeightForWidth(sliFactor->sizePolicy().hasHeightForWidth());
        sliFactor->setSizePolicy(sizePolicy1);
        sliFactor->setMaximum(1000);
        sliFactor->setSingleStep(1);
        sliFactor->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliFactor);

        label_5 = new QLabel(grpVelocity);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        sliThreashold = new QSlider(grpVelocity);
        sliThreashold->setObjectName(QStringLiteral("sliThreashold"));
        sizePolicy1.setHeightForWidth(sliThreashold->sizePolicy().hasHeightForWidth());
        sliThreashold->setSizePolicy(sizePolicy1);
        sliThreashold->setMaximum(1000);
        sliThreashold->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliThreashold);


        verticalLayout_7->addWidget(grpVelocity);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        sliNear = new QSlider(groupBox);
        sliNear->setObjectName(QStringLiteral("sliNear"));
        sizePolicy1.setHeightForWidth(sliNear->sizePolicy().hasHeightForWidth());
        sliNear->setSizePolicy(sizePolicy1);
        sliNear->setMaximum(1000);
        sliNear->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(sliNear);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        sliFar = new QSlider(groupBox);
        sliFar->setObjectName(QStringLiteral("sliFar"));
        sizePolicy1.setHeightForWidth(sliFar->sizePolicy().hasHeightForWidth());
        sliFar->setSizePolicy(sizePolicy1);
        sliFar->setMaximum(1000);
        sliFar->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(sliFar);


        verticalLayout_7->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        DebugWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DebugWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 282, 21));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuBlob = new QMenu(menuView);
        menuBlob->setObjectName(QStringLiteral("menuBlob"));
        DebugWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DebugWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DebugWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DebugWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DebugWindow->setStatusBar(statusBar);

        menuBar->addAction(menuView->menuAction());
        menuView->addAction(actionDepth_Image);
        menuView->addAction(actionBinary_Depth_image);
        menuView->addSeparator();
        menuView->addAction(menuBlob->menuAction());
        menuView->addAction(actionPlayer_Overview);
        menuView->addSeparator();
        menuView->addAction(actionClose);
        menuBlob->addAction(actionVelocity);
        menuBlob->addAction(actionBinary);
        menuBlob->addAction(actionColor);

        retranslateUi(DebugWindow);

        QMetaObject::connectSlotsByName(DebugWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DebugWindow)
    {
        DebugWindow->setWindowTitle(QApplication::translate("DebugWindow", "mta13341 Tracking Algorithm Debugger", 0));
        actionDepth_Image->setText(QApplication::translate("DebugWindow", "Depth Image", 0));
        actionBinary_Depth_image->setText(QApplication::translate("DebugWindow", "Binary Depth Image", 0));
        actionPlayer_Overview->setText(QApplication::translate("DebugWindow", "Player Overview", 0));
        actionColoured->setText(QApplication::translate("DebugWindow", "Coloured", 0));
        actionVelocity->setText(QApplication::translate("DebugWindow", "Velocity", 0));
        actionBinary->setText(QApplication::translate("DebugWindow", "Binary", 0));
        actionClose->setText(QApplication::translate("DebugWindow", "Close", 0));
        actionColor->setText(QApplication::translate("DebugWindow", "Color", 0));
        verticalGroupBox->setTitle(QApplication::translate("DebugWindow", "Blob Detection", 0));
        label_9->setText(QApplication::translate("DebugWindow", "Minimum Size:", 0));
        label_12->setText(QApplication::translate("DebugWindow", "Depth Threashold", 0));
        label_8->setText(QApplication::translate("DebugWindow", "Arm Size (%):", 0));
        grpVelocity->setTitle(QApplication::translate("DebugWindow", "Velocity Mapping", 0));
        label->setText(QApplication::translate("DebugWindow", "Minima", 0));
        label_2->setText(QApplication::translate("DebugWindow", "Maxima", 0));
        label_4->setText(QApplication::translate("DebugWindow", "Factor", 0));
        label_5->setText(QApplication::translate("DebugWindow", "Threashold", 0));
        groupBox->setTitle(QApplication::translate("DebugWindow", "Depth Image", 0));
        label_10->setText(QApplication::translate("DebugWindow", "Near Clipping", 0));
        label_7->setText(QApplication::translate("DebugWindow", "Far Clipping", 0));
        menuView->setTitle(QApplication::translate("DebugWindow", "View", 0));
        menuBlob->setTitle(QApplication::translate("DebugWindow", "Blobs", 0));
    } // retranslateUi

};

namespace Ui {
    class DebugWindow: public Ui_DebugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
