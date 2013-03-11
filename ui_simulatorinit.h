/********************************************************************************
** Form generated from reading UI file 'simulatorinit.ui'
**
** Created: Mon Mar 11 13:24:44 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORINIT_H
#define UI_SIMULATORINIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SimulatorInit
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *fileInput;
    QPushButton *browseButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QPushButton *continueButton;

    void setupUi(QDialog *SimulatorInit)
    {
        if (SimulatorInit->objectName().isEmpty())
            SimulatorInit->setObjectName(QString::fromUtf8("SimulatorInit"));
        SimulatorInit->resize(353, 137);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SimulatorInit->sizePolicy().hasHeightForWidth());
        SimulatorInit->setSizePolicy(sizePolicy);
        SimulatorInit->setMinimumSize(QSize(353, 137));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimulatorInit->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SimulatorInit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SimulatorInit);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(331, 41));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        fileInput = new QLineEdit(SimulatorInit);
        fileInput->setObjectName(QString::fromUtf8("fileInput"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileInput->sizePolicy().hasHeightForWidth());
        fileInput->setSizePolicy(sizePolicy1);
        fileInput->setMinimumSize(QSize(231, 31));

        horizontalLayout->addWidget(fileInput);

        browseButton = new QPushButton(SimulatorInit);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(browseButton->sizePolicy().hasHeightForWidth());
        browseButton->setSizePolicy(sizePolicy2);
        browseButton->setMinimumSize(QSize(91, 31));

        horizontalLayout->addWidget(browseButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        cancelButton = new QPushButton(SimulatorInit);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        cancelButton->setMinimumSize(QSize(81, 31));

        horizontalLayout_2->addWidget(cancelButton);

        continueButton = new QPushButton(SimulatorInit);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        sizePolicy1.setHeightForWidth(continueButton->sizePolicy().hasHeightForWidth());
        continueButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(continueButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SimulatorInit);

        QMetaObject::connectSlotsByName(SimulatorInit);
    } // setupUi

    void retranslateUi(QDialog *SimulatorInit)
    {
        SimulatorInit->setWindowTitle(QApplication::translate("SimulatorInit", "Select Program For Simulation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SimulatorInit", "Enter the path to the program to use as a simulation in the box below.", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("SimulatorInit", "Browse...", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SimulatorInit", "Cancel", 0, QApplication::UnicodeUTF8));
        continueButton->setText(QApplication::translate("SimulatorInit", "Continue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimulatorInit: public Ui_SimulatorInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORINIT_H
