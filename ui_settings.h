/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Feb 11 17:02:05 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLabel *updateIntervalLabel;
    QSpinBox *updateIntervalSpinBox;
    QLabel *subUpdateIntervalLabel;
    QSpinBox *subUpdateIntervalSpinBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *resetAllButton;
    QLabel *sortByLabel;
    QComboBox *sortByComboBox;
    QComboBox *sortByOrderComboBox;
    QSpinBox *runningUpdateIntervalSpinBox;
    QLabel *runningUpdateIntervalLabel;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(400, 196);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        updateIntervalLabel = new QLabel(Settings);
        updateIntervalLabel->setObjectName(QString::fromUtf8("updateIntervalLabel"));
        updateIntervalLabel->setGeometry(QRect(10, 10, 211, 21));
        updateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        updateIntervalSpinBox = new QSpinBox(Settings);
        updateIntervalSpinBox->setObjectName(QString::fromUtf8("updateIntervalSpinBox"));
        updateIntervalSpinBox->setGeometry(QRect(330, 10, 55, 25));
        updateIntervalSpinBox->setMinimum(1);
        updateIntervalSpinBox->setMaximum(60);
        subUpdateIntervalLabel = new QLabel(Settings);
        subUpdateIntervalLabel->setObjectName(QString::fromUtf8("subUpdateIntervalLabel"));
        subUpdateIntervalLabel->setGeometry(QRect(10, 46, 221, 20));
        subUpdateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        subUpdateIntervalSpinBox = new QSpinBox(Settings);
        subUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("subUpdateIntervalSpinBox"));
        subUpdateIntervalSpinBox->setGeometry(QRect(330, 40, 55, 25));
        subUpdateIntervalSpinBox->setMinimum(1);
        subUpdateIntervalSpinBox->setMaximum(60);
        saveButton = new QPushButton(Settings);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(240, 160, 71, 27));
        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(70, 160, 71, 27));
        resetAllButton = new QPushButton(Settings);
        resetAllButton->setObjectName(QString::fromUtf8("resetAllButton"));
        resetAllButton->setGeometry(QRect(150, 160, 81, 27));
        sortByLabel = new QLabel(Settings);
        sortByLabel->setObjectName(QString::fromUtf8("sortByLabel"));
        sortByLabel->setGeometry(QRect(10, 105, 121, 21));
        sortByComboBox = new QComboBox(Settings);
        sortByComboBox->setObjectName(QString::fromUtf8("sortByComboBox"));
        sortByComboBox->setGeometry(QRect(180, 100, 101, 25));
        sortByOrderComboBox = new QComboBox(Settings);
        sortByOrderComboBox->setObjectName(QString::fromUtf8("sortByOrderComboBox"));
        sortByOrderComboBox->setGeometry(QRect(280, 100, 101, 25));
        runningUpdateIntervalSpinBox = new QSpinBox(Settings);
        runningUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("runningUpdateIntervalSpinBox"));
        runningUpdateIntervalSpinBox->setGeometry(QRect(330, 70, 55, 25));
        runningUpdateIntervalSpinBox->setMinimum(1);
        runningUpdateIntervalSpinBox->setMaximum(10);
        runningUpdateIntervalLabel = new QLabel(Settings);
        runningUpdateIntervalLabel->setObjectName(QString::fromUtf8("runningUpdateIntervalLabel"));
        runningUpdateIntervalLabel->setGeometry(QRect(10, 70, 311, 31));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Program Settings", 0, QApplication::UnicodeUTF8));
        updateIntervalLabel->setText(QApplication::translate("Settings", "Global process update interval:", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalLabel->setText(QApplication::translate("Settings", "Individual process update interval:", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Settings", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        resetAllButton->setText(QApplication::translate("Settings", "Reset All", 0, QApplication::UnicodeUTF8));
        sortByLabel->setText(QApplication::translate("Settings", "Sort processes by:", 0, QApplication::UnicodeUTF8));
        sortByComboBox->clear();
        sortByComboBox->insertItems(0, QStringList()
         << QApplication::translate("Settings", "Process ID", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "Name", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "State", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "Priority", 0, QApplication::UnicodeUTF8)
        );
        sortByOrderComboBox->clear();
        sortByOrderComboBox->insertItems(0, QStringList()
         << QApplication::translate("Settings", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "Descending", 0, QApplication::UnicodeUTF8)
        );
        runningUpdateIntervalLabel->setText(QApplication::translate("Settings", "Recently running processes update interval:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
