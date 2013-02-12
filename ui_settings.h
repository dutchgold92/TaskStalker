/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Tue Feb 12 16:59:31 2013
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *resetAllButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *updateIntervalLabel;
    QSpinBox *updateIntervalSpinBox;
    QLabel *subUpdateIntervalLabel;
    QSpinBox *subUpdateIntervalSpinBox;
    QLabel *runningUpdateIntervalLabel;
    QSpinBox *runningUpdateIntervalSpinBox;
    QLabel *cpuUpdateIntervalLabel;
    QSpinBox *cpuUpdateIntervalSpinBox;
    QLabel *sortByLabel;
    QComboBox *sortByComboBox;
    QComboBox *sortByOrderComboBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(348, 197);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        saveButton = new QPushButton(Settings);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(230, 160, 71, 27));
        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(60, 160, 71, 27));
        resetAllButton = new QPushButton(Settings);
        resetAllButton->setObjectName(QString::fromUtf8("resetAllButton"));
        resetAllButton->setGeometry(QRect(140, 160, 81, 27));
        widget = new QWidget(Settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 327, 128));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        updateIntervalLabel = new QLabel(widget);
        updateIntervalLabel->setObjectName(QString::fromUtf8("updateIntervalLabel"));
        updateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(updateIntervalLabel, 0, 0, 1, 3);

        updateIntervalSpinBox = new QSpinBox(widget);
        updateIntervalSpinBox->setObjectName(QString::fromUtf8("updateIntervalSpinBox"));
        updateIntervalSpinBox->setMinimum(1);
        updateIntervalSpinBox->setMaximum(60);

        gridLayout->addWidget(updateIntervalSpinBox, 0, 3, 1, 1);

        subUpdateIntervalLabel = new QLabel(widget);
        subUpdateIntervalLabel->setObjectName(QString::fromUtf8("subUpdateIntervalLabel"));
        subUpdateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(subUpdateIntervalLabel, 1, 0, 1, 3);

        subUpdateIntervalSpinBox = new QSpinBox(widget);
        subUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("subUpdateIntervalSpinBox"));
        subUpdateIntervalSpinBox->setMinimum(1);
        subUpdateIntervalSpinBox->setMaximum(60);

        gridLayout->addWidget(subUpdateIntervalSpinBox, 1, 3, 1, 1);

        runningUpdateIntervalLabel = new QLabel(widget);
        runningUpdateIntervalLabel->setObjectName(QString::fromUtf8("runningUpdateIntervalLabel"));

        gridLayout->addWidget(runningUpdateIntervalLabel, 2, 0, 1, 3);

        runningUpdateIntervalSpinBox = new QSpinBox(widget);
        runningUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("runningUpdateIntervalSpinBox"));
        runningUpdateIntervalSpinBox->setMinimum(1);
        runningUpdateIntervalSpinBox->setMaximum(10);

        gridLayout->addWidget(runningUpdateIntervalSpinBox, 2, 3, 1, 1);

        cpuUpdateIntervalLabel = new QLabel(widget);
        cpuUpdateIntervalLabel->setObjectName(QString::fromUtf8("cpuUpdateIntervalLabel"));

        gridLayout->addWidget(cpuUpdateIntervalLabel, 3, 0, 1, 3);

        cpuUpdateIntervalSpinBox = new QSpinBox(widget);
        cpuUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("cpuUpdateIntervalSpinBox"));
        cpuUpdateIntervalSpinBox->setMinimum(1);
        cpuUpdateIntervalSpinBox->setMaximum(10);

        gridLayout->addWidget(cpuUpdateIntervalSpinBox, 3, 3, 1, 1);

        sortByLabel = new QLabel(widget);
        sortByLabel->setObjectName(QString::fromUtf8("sortByLabel"));

        gridLayout->addWidget(sortByLabel, 4, 0, 1, 1);

        sortByComboBox = new QComboBox(widget);
        sortByComboBox->setObjectName(QString::fromUtf8("sortByComboBox"));

        gridLayout->addWidget(sortByComboBox, 4, 1, 1, 1);

        sortByOrderComboBox = new QComboBox(widget);
        sortByOrderComboBox->setObjectName(QString::fromUtf8("sortByOrderComboBox"));

        gridLayout->addWidget(sortByOrderComboBox, 4, 2, 1, 2);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Program Settings", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Settings", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        resetAllButton->setText(QApplication::translate("Settings", "Reset All", 0, QApplication::UnicodeUTF8));
        updateIntervalLabel->setText(QApplication::translate("Settings", "<b>Global process update interval:</b>", 0, QApplication::UnicodeUTF8));
        updateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalLabel->setText(QApplication::translate("Settings", "<b>Individual process update interval:</b>", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        runningUpdateIntervalLabel->setText(QApplication::translate("Settings", "<b>Running processes update interval:</b>", 0, QApplication::UnicodeUTF8));
        runningUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        cpuUpdateIntervalLabel->setText(QApplication::translate("Settings", "<b>Processor activity update interval:</b>", 0, QApplication::UnicodeUTF8));
        cpuUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        sortByLabel->setText(QApplication::translate("Settings", "<b>Sort processes by:</b>", 0, QApplication::UnicodeUTF8));
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
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
