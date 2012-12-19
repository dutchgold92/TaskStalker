/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created: Tue Dec 18 12:07:02 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulator
{
public:
    QLabel *visualContainer;
    QPushButton *killButton;
    QTableWidget *infoTable;
    QPushButton *closeButton;
    QPushButton *endButton;
    QPushButton *stopButton;
    QPushButton *priorityButton;
    QLabel *label;
    QSpinBox *priorityBox;

    void setupUi(QDialog *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->resize(549, 510);
        visualContainer = new QLabel(Simulator);
        visualContainer->setObjectName(QString::fromUtf8("visualContainer"));
        visualContainer->setGeometry(QRect(10, 80, 531, 401));
        killButton = new QPushButton(Simulator);
        killButton->setObjectName(QString::fromUtf8("killButton"));
        killButton->setGeometry(QRect(500, 60, 41, 27));
        infoTable = new QTableWidget(Simulator);
        if (infoTable->columnCount() < 3)
            infoTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (infoTable->rowCount() < 1)
            infoTable->setRowCount(1);
        infoTable->setObjectName(QString::fromUtf8("infoTable"));
        infoTable->setGeometry(QRect(0, 0, 551, 51));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(infoTable->sizePolicy().hasHeightForWidth());
        infoTable->setSizePolicy(sizePolicy);
        infoTable->setFrameShape(QFrame::Panel);
        infoTable->setFrameShadow(QFrame::Raised);
        infoTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTable->setShowGrid(false);
        infoTable->setRowCount(1);
        infoTable->setColumnCount(3);
        infoTable->horizontalHeader()->setMinimumSectionSize(40);
        infoTable->horizontalHeader()->setStretchLastSection(true);
        infoTable->verticalHeader()->setVisible(false);
        closeButton = new QPushButton(Simulator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(450, 480, 91, 27));
        endButton = new QPushButton(Simulator);
        endButton->setObjectName(QString::fromUtf8("endButton"));
        endButton->setGeometry(QRect(450, 60, 41, 27));
        stopButton = new QPushButton(Simulator);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(370, 60, 75, 27));
        priorityButton = new QPushButton(Simulator);
        priorityButton->setObjectName(QString::fromUtf8("priorityButton"));
        priorityButton->setGeometry(QRect(270, 60, 91, 27));
        label = new QLabel(Simulator);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 141, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        priorityBox = new QSpinBox(Simulator);
        priorityBox->setObjectName(QString::fromUtf8("priorityBox"));
        priorityBox->setGeometry(QRect(210, 60, 55, 25));
        priorityBox->setMinimum(-20);
        priorityBox->setMaximum(20);

        retranslateUi(Simulator);

        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QDialog *Simulator)
    {
        Simulator->setWindowTitle(QApplication::translate("Simulator", "Process Simulator", 0, QApplication::UnicodeUTF8));
        visualContainer->setText(QString());
        killButton->setText(QApplication::translate("Simulator", "Kill", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = infoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Simulator", "Process ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = infoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Simulator", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = infoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Simulator", "State", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("Simulator", "Close", 0, QApplication::UnicodeUTF8));
        endButton->setText(QApplication::translate("Simulator", "End", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("Simulator", "Stop", 0, QApplication::UnicodeUTF8));
        priorityButton->setText(QApplication::translate("Simulator", "Set Priority", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Simulator", "Process Actions:", 0, QApplication::UnicodeUTF8));
        priorityBox->setPrefix(QString());
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
