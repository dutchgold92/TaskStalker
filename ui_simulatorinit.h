/********************************************************************************
** Form generated from reading UI file 'simulatorinit.ui'
**
** Created: Thu Feb 14 17:49:57 2013
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SimulatorInit
{
public:
    QLineEdit *fileInput;
    QLabel *label;
    QPushButton *continueButton;
    QPushButton *cancelButton;
    QPushButton *browseButton;

    void setupUi(QDialog *SimulatorInit)
    {
        if (SimulatorInit->objectName().isEmpty())
            SimulatorInit->setObjectName(QString::fromUtf8("SimulatorInit"));
        SimulatorInit->resize(353, 137);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimulatorInit->setWindowIcon(icon);
        fileInput = new QLineEdit(SimulatorInit);
        fileInput->setObjectName(QString::fromUtf8("fileInput"));
        fileInput->setGeometry(QRect(10, 60, 231, 31));
        label = new QLabel(SimulatorInit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 331, 51));
        label->setWordWrap(true);
        continueButton = new QPushButton(SimulatorInit);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(250, 100, 91, 27));
        cancelButton = new QPushButton(SimulatorInit);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(150, 100, 91, 27));
        browseButton = new QPushButton(SimulatorInit);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(250, 60, 91, 31));

        retranslateUi(SimulatorInit);

        QMetaObject::connectSlotsByName(SimulatorInit);
    } // setupUi

    void retranslateUi(QDialog *SimulatorInit)
    {
        SimulatorInit->setWindowTitle(QApplication::translate("SimulatorInit", "Select Program For Simulation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SimulatorInit", "Enter the path to the program to use as a simulation in the box below.", 0, QApplication::UnicodeUTF8));
        continueButton->setText(QApplication::translate("SimulatorInit", "Continue", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SimulatorInit", "Cancel", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("SimulatorInit", "Browse...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimulatorInit: public Ui_SimulatorInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORINIT_H
