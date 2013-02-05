/********************************************************************************
** Form generated from reading UI file 'simulatorinit.ui'
**
** Created: Tue Feb 5 22:25:41 2013
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
    QPushButton *useDefaultButton;
    QLabel *errorLabel;

    void setupUi(QDialog *SimulatorInit)
    {
        if (SimulatorInit->objectName().isEmpty())
            SimulatorInit->setObjectName(QString::fromUtf8("SimulatorInit"));
        SimulatorInit->resize(353, 158);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimulatorInit->setWindowIcon(icon);
        fileInput = new QLineEdit(SimulatorInit);
        fileInput->setObjectName(QString::fromUtf8("fileInput"));
        fileInput->setGeometry(QRect(60, 60, 231, 25));
        label = new QLabel(SimulatorInit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 251, 51));
        label->setWordWrap(true);
        continueButton = new QPushButton(SimulatorInit);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(250, 120, 91, 27));
        cancelButton = new QPushButton(SimulatorInit);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(10, 120, 91, 27));
        useDefaultButton = new QPushButton(SimulatorInit);
        useDefaultButton->setObjectName(QString::fromUtf8("useDefaultButton"));
        useDefaultButton->setGeometry(QRect(130, 120, 91, 27));
        errorLabel = new QLabel(SimulatorInit);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setEnabled(true);
        errorLabel->setGeometry(QRect(10, 90, 331, 20));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 4, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 127, 130, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 67, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 2, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 2, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(255, 127, 129, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        errorLabel->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        errorLabel->setFont(font);
        errorLabel->setStyleSheet(QString::fromUtf8("color: #ff0000;"));
        errorLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(SimulatorInit);

        QMetaObject::connectSlotsByName(SimulatorInit);
    } // setupUi

    void retranslateUi(QDialog *SimulatorInit)
    {
        SimulatorInit->setWindowTitle(QApplication::translate("SimulatorInit", "Select Program For Simulation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SimulatorInit", "Enter the path to the program to use as a simulation in the box below.", 0, QApplication::UnicodeUTF8));
        continueButton->setText(QApplication::translate("SimulatorInit", "Continue", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SimulatorInit", "Cancel", 0, QApplication::UnicodeUTF8));
        useDefaultButton->setText(QApplication::translate("SimulatorInit", "Use Default", 0, QApplication::UnicodeUTF8));
        errorLabel->setText(QApplication::translate("SimulatorInit", "Not found!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimulatorInit: public Ui_SimulatorInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORINIT_H
