/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created: Tue Dec 11 21:54:59 2012
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->resize(549, 510);
        visualContainer = new QLabel(Simulator);
        visualContainer->setObjectName(QString::fromUtf8("visualContainer"));
        visualContainer->setGeometry(QRect(10, 60, 531, 401));
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
        pushButton = new QPushButton(Simulator);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 60, 51, 27));
        pushButton_2 = new QPushButton(Simulator);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 60, 91, 27));
        label = new QLabel(Simulator);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 141, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

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
        pushButton->setText(QApplication::translate("Simulator", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Simulator", "Edit Priority", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Simulator", "Process Actions:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
