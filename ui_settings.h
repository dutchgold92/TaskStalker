/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Sat Mar 2 16:56:42 2013
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *subUpdateIntervalLabel;
    QLabel *updateIntervalLabel;
    QSpinBox *updateIntervalSpinBox;
    QSpinBox *subUpdateIntervalSpinBox;
    QLabel *sortByLabel;
    QSpinBox *runningUpdateIntervalSpinBox;
    QComboBox *sortByComboBox;
    QLabel *runningUpdateIntervalLabel;
    QLabel *cpuUpdateIntervalLabel;
    QComboBox *sortByOrderComboBox;
    QSpinBox *cpuUpdateIntervalSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *resetAllButton;
    QPushButton *saveButton;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(390, 214);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        Settings->setMinimumSize(QSize(390, 214));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        subUpdateIntervalLabel = new QLabel(Settings);
        subUpdateIntervalLabel->setObjectName(QString::fromUtf8("subUpdateIntervalLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(subUpdateIntervalLabel->sizePolicy().hasHeightForWidth());
        subUpdateIntervalLabel->setSizePolicy(sizePolicy1);
        subUpdateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(subUpdateIntervalLabel, 1, 0, 1, 3);

        updateIntervalLabel = new QLabel(Settings);
        updateIntervalLabel->setObjectName(QString::fromUtf8("updateIntervalLabel"));
        sizePolicy1.setHeightForWidth(updateIntervalLabel->sizePolicy().hasHeightForWidth());
        updateIntervalLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        updateIntervalLabel->setFont(font);
        updateIntervalLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(updateIntervalLabel, 0, 0, 1, 3);

        updateIntervalSpinBox = new QSpinBox(Settings);
        updateIntervalSpinBox->setObjectName(QString::fromUtf8("updateIntervalSpinBox"));
        sizePolicy1.setHeightForWidth(updateIntervalSpinBox->sizePolicy().hasHeightForWidth());
        updateIntervalSpinBox->setSizePolicy(sizePolicy1);
        updateIntervalSpinBox->setMinimum(1);
        updateIntervalSpinBox->setMaximum(60);

        gridLayout->addWidget(updateIntervalSpinBox, 0, 3, 1, 1);

        subUpdateIntervalSpinBox = new QSpinBox(Settings);
        subUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("subUpdateIntervalSpinBox"));
        sizePolicy1.setHeightForWidth(subUpdateIntervalSpinBox->sizePolicy().hasHeightForWidth());
        subUpdateIntervalSpinBox->setSizePolicy(sizePolicy1);
        subUpdateIntervalSpinBox->setMinimum(1);
        subUpdateIntervalSpinBox->setMaximum(60);

        gridLayout->addWidget(subUpdateIntervalSpinBox, 1, 3, 1, 1);

        sortByLabel = new QLabel(Settings);
        sortByLabel->setObjectName(QString::fromUtf8("sortByLabel"));
        sizePolicy1.setHeightForWidth(sortByLabel->sizePolicy().hasHeightForWidth());
        sortByLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(sortByLabel, 4, 0, 1, 1);

        runningUpdateIntervalSpinBox = new QSpinBox(Settings);
        runningUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("runningUpdateIntervalSpinBox"));
        sizePolicy1.setHeightForWidth(runningUpdateIntervalSpinBox->sizePolicy().hasHeightForWidth());
        runningUpdateIntervalSpinBox->setSizePolicy(sizePolicy1);
        runningUpdateIntervalSpinBox->setMinimum(1);
        runningUpdateIntervalSpinBox->setMaximum(10);

        gridLayout->addWidget(runningUpdateIntervalSpinBox, 2, 3, 1, 1);

        sortByComboBox = new QComboBox(Settings);
        sortByComboBox->setObjectName(QString::fromUtf8("sortByComboBox"));
        sizePolicy1.setHeightForWidth(sortByComboBox->sizePolicy().hasHeightForWidth());
        sortByComboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(sortByComboBox, 4, 1, 1, 1);

        runningUpdateIntervalLabel = new QLabel(Settings);
        runningUpdateIntervalLabel->setObjectName(QString::fromUtf8("runningUpdateIntervalLabel"));
        sizePolicy1.setHeightForWidth(runningUpdateIntervalLabel->sizePolicy().hasHeightForWidth());
        runningUpdateIntervalLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(runningUpdateIntervalLabel, 2, 0, 1, 3);

        cpuUpdateIntervalLabel = new QLabel(Settings);
        cpuUpdateIntervalLabel->setObjectName(QString::fromUtf8("cpuUpdateIntervalLabel"));
        sizePolicy1.setHeightForWidth(cpuUpdateIntervalLabel->sizePolicy().hasHeightForWidth());
        cpuUpdateIntervalLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cpuUpdateIntervalLabel, 3, 0, 1, 3);

        sortByOrderComboBox = new QComboBox(Settings);
        sortByOrderComboBox->setObjectName(QString::fromUtf8("sortByOrderComboBox"));
        sizePolicy1.setHeightForWidth(sortByOrderComboBox->sizePolicy().hasHeightForWidth());
        sortByOrderComboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(sortByOrderComboBox, 4, 2, 1, 2);

        cpuUpdateIntervalSpinBox = new QSpinBox(Settings);
        cpuUpdateIntervalSpinBox->setObjectName(QString::fromUtf8("cpuUpdateIntervalSpinBox"));
        sizePolicy1.setHeightForWidth(cpuUpdateIntervalSpinBox->sizePolicy().hasHeightForWidth());
        cpuUpdateIntervalSpinBox->setSizePolicy(sizePolicy1);
        cpuUpdateIntervalSpinBox->setMinimum(1);
        cpuUpdateIntervalSpinBox->setMaximum(10);

        gridLayout->addWidget(cpuUpdateIntervalSpinBox, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        cancelButton->setAutoFillBackground(false);

        horizontalLayout->addWidget(cancelButton);

        resetAllButton = new QPushButton(Settings);
        resetAllButton->setObjectName(QString::fromUtf8("resetAllButton"));
        sizePolicy1.setHeightForWidth(resetAllButton->sizePolicy().hasHeightForWidth());
        resetAllButton->setSizePolicy(sizePolicy1);
        resetAllButton->setMinimumSize(QSize(0, 35));

        horizontalLayout->addWidget(resetAllButton);

        saveButton = new QPushButton(Settings);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Program Settings", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalLabel->setText(QApplication::translate("Settings", "Individual process update interval:", 0, QApplication::UnicodeUTF8));
        updateIntervalLabel->setText(QApplication::translate("Settings", "Global process update interval:", 0, QApplication::UnicodeUTF8));
        updateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        subUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        sortByLabel->setText(QApplication::translate("Settings", "Sort processes by:", 0, QApplication::UnicodeUTF8));
        runningUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        runningUpdateIntervalLabel->setText(QApplication::translate("Settings", "Running processes update interval:", 0, QApplication::UnicodeUTF8));
        cpuUpdateIntervalLabel->setText(QApplication::translate("Settings", "Processor activity update interval:", 0, QApplication::UnicodeUTF8));
        sortByOrderComboBox->clear();
        sortByOrderComboBox->insertItems(0, QStringList()
         << QApplication::translate("Settings", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "Descending", 0, QApplication::UnicodeUTF8)
        );
        cpuUpdateIntervalSpinBox->setSuffix(QApplication::translate("Settings", " seconds", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        resetAllButton->setText(QApplication::translate("Settings", "Reset All", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Settings", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
