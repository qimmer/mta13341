/********************************************************************************
** Form generated from reading UI file 'imagedebugger.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDEBUGGER_H
#define UI_IMAGEDEBUGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ImageDebugger
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lblImage;

    void setupUi(QDialog *ImageDebugger)
    {
        if (ImageDebugger->objectName().isEmpty())
            ImageDebugger->setObjectName(QStringLiteral("ImageDebugger"));
        ImageDebugger->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ImageDebugger);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblImage = new QLabel(ImageDebugger);
        lblImage->setObjectName(QStringLiteral("lblImage"));

        horizontalLayout->addWidget(lblImage);


        retranslateUi(ImageDebugger);

        QMetaObject::connectSlotsByName(ImageDebugger);
    } // setupUi

    void retranslateUi(QDialog *ImageDebugger)
    {
        ImageDebugger->setWindowTitle(QApplication::translate("ImageDebugger", "Dialog", 0));
        lblImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageDebugger: public Ui_ImageDebugger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDEBUGGER_H
