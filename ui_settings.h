/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Thu Feb 21 20:07:36 2013
**      by: Qt User Interface Compiler version 4.6.3
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
    QWidget *layoutWidget;
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
        Settings->resize(390, 214);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        saveButton = new QPushButton(Settings);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(230, 180, 71, 27));
        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(60, 180, 71, 27));
        resetAllButton = new QPushButton(Settings);
        resetAllButton->setObjectName(QString::fromUtf8("resetAllButton"));
        resetAllButton->setGeometry(QRect(140, 180, 81, 27));
        layoutWidget = new QWidget(Settings);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 371, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        updateIntervalLabel = new QLabel(layoutWidget);
        updateIntervalLabel->setObjectName(QString::fromUtf8("updateIntervalLabel"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        updateIntervalLabel->setFont(font);
        updateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(updateIntervalLabel, 0, 0, 1, 3);

        updateIntervalSpinBox = new QSpinBox(layoutWidget);
        updateIntervalSpinBox->setObjectName(QString::fromUtf8("updateIntervalSpinBox"));
        updateIntervalSpinBox->setMinimum(1);
        updateIntervalSpinBox->setMaximum(60);

        gridLayout->addWidget(updateIntervalSpinBox, 0, 3, 1, 1);

        subUpdateIntervalLabel = new QLabel(layoutWidget);
        subUpdateIntervalLabel->setObjectName(QString::fromUtf8("subUpdateIntervalLabel"));
        subUpdateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(subUpdateIntervalLabel, 1, 0, 1, 3);

        subUpdateIntervalSpinBox = new QSpinBox(layoutWidget);
        subUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("subUpdateIntervalSpinBox"));
        subUpdateIntervalSpinBox->setMinimum(1);
        subUpdateIntervalSpinBox->setMaximum(60);

        gridLayout->addWidget(subUpdateIntervalSpinBox, 1, 3, 1, 1);

        runningUpdateIntervalLabel = new QLabel(layoutWidget);
        runningUpdateIntervalLabel->setObjectName(QString::fromUtf8("runningUpdateIntervalLabel"));

        gridLayout->addWidget(runningUpdateIntervalLabel, 2, 0, 1, 3);

        runningUpdateIntervalSpinBox = new QSpinBox(layoutWidget);
        runningUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("runningUpdateIntervalSpinBox"));
        runningUpdateIntervalSpinBox->setMinimum(1);
        runningUpdateIntervalSpinBox->setMaximum(10);

        gridLayout->addWidget(runningUpdateIntervalSpinBox, 2, 3, 1, 1);

        cpuUpdateIntervalLabel = new QLabel(layoutWidget);
        cpuUpdateIntervalLabel->setObjectName(QString::fromUtf8("cpuUpdateIntervalLabel"));

        gridLayout->addWidget(cpuUpdateIntervalLabel, 3, 0, 1, 3);

        cpuUpdateIntervalSpinBox = new QSpinBox(layoutWidget);
        cpuUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("cpuUpdateIntervalSpinBox"));
        cpuUpdateIntervalSpinBox->setMinimum(1);
        cpuUpdateIntervalSpinBox->setMaximum(10);

        gridLayout->addWidget(cpuUpdateIntervalSpinBox, 3, 3, 1, 1);

        sortByLabel = new QLabel(layoutWidget);
        sortByLabel->setObjectName(QString::fromUtf8("sortByLabel"));

        gridLayout->addWidget(sortByLabel, 4, 0, 1, 1);

        sortByComboBox = new QComboBox(layoutWidget);
        sortByComboBox->setObjectName(QString::fromUtf8("sortByComboBox"));

        gridLayout->addWidget(sortByComboBox, 4, 1, 1, 1);

        sortByOrderComboBox = new QComboBox(layoutWidget);
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
        updateIntervalLabel->setText(QApplication::translate("Settings", "Global process update interval:", 0, QApplication::UnicodeUTF8));
        updateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalLabel->setText(QApplication::translate("Settings", "Individual process update interval:", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        runningUpdateIntervalLabel->setText(QApplication::translate("Settings", "Running processes update interval:", 0, QApplication::UnicodeUTF8));
        runningUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        cpuUpdateIntervalLabel->setText(QApplication::translate("Settings", "Processor activity update interval:", 0, QApplication::UnicodeUTF8));
        cpuUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
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
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
