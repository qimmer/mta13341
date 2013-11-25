/********************************************************************************
** Form generated from reading UI file 'blobimagedebugger.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOBIMAGEDEBUGGER_H
#define UI_BLOBIMAGEDEBUGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BlobImageDebugger
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblBlob3;
    QLabel *lblBlob2;
    QLabel *lblBlob1;

    void setupUi(QDialog *BlobImageDebugger)
    {
        if (BlobImageDebugger->objectName().isEmpty())
            BlobImageDebugger->setObjectName(QStringLiteral("BlobImageDebugger"));
        BlobImageDebugger->resize(218, 630);
        verticalLayout = new QVBoxLayout(BlobImageDebugger);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblBlob3 = new QLabel(BlobImageDebugger);
        lblBlob3->setObjectName(QStringLiteral("lblBlob3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblBlob3->sizePolicy().hasHeightForWidth());
        lblBlob3->setSizePolicy(sizePolicy);
        lblBlob3->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(lblBlob3);

        lblBlob2 = new QLabel(BlobImageDebugger);
        lblBlob2->setObjectName(QStringLiteral("lblBlob2"));
        sizePolicy.setHeightForWidth(lblBlob2->sizePolicy().hasHeightForWidth());
        lblBlob2->setSizePolicy(sizePolicy);
        lblBlob2->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(lblBlob2);

        lblBlob1 = new QLabel(BlobImageDebugger);
        lblBlob1->setObjectName(QStringLiteral("lblBlob1"));
        sizePolicy.setHeightForWidth(lblBlob1->sizePolicy().hasHeightForWidth());
        lblBlob1->setSizePolicy(sizePolicy);
        lblBlob1->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(lblBlob1);


        retranslateUi(BlobImageDebugger);

        QMetaObject::connectSlotsByName(BlobImageDebugger);
    } // setupUi

    void retranslateUi(QDialog *BlobImageDebugger)
    {
        BlobImageDebugger->setWindowTitle(QApplication::translate("BlobImageDebugger", "Dialog", 0));
        lblBlob3->setText(QString());
        lblBlob2->setText(QString());
        lblBlob1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BlobImageDebugger: public Ui_BlobImageDebugger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOBIMAGEDEBUGGER_H
