/********************************************************************************
** Form generated from reading UI file 'viewrunning.ui'
**
** Created: Tue Feb 12 16:22:30 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWRUNNING_H
#define UI_VIEWRUNNING_H

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

class Ui_ViewRunning
{
public:
    QPushButton *toggleUpdateButton;
    QPushButton *closeButton;
    QTableWidget *outputTable;
    QLabel *timeLabel;

    void setupUi(QDialog *ViewRunning)
    {
        if (ViewRunning->objectName().isEmpty())
            ViewRunning->setObjectName(QString::fromUtf8("ViewRunning"));
        ViewRunning->resize(400, 225);
        toggleUpdateButton = new QPushButton(ViewRunning);
        toggleUpdateButton->setObjectName(QString::fromUtf8("toggleUpdateButton"));
        toggleUpdateButton->setGeometry(QRect(10, 190, 51, 31));
        closeButton = new QPushButton(ViewRunning);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(324, 190, 71, 31));
        outputTable = new QTableWidget(ViewRunning);
        if (outputTable->columnCount() < 3)
            outputTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        outputTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        outputTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        outputTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        outputTable->setObjectName(QString::fromUtf8("outputTable"));
        outputTable->setGeometry(QRect(10, 10, 381, 171));
        outputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        outputTable->setAlternatingRowColors(true);
        outputTable->setSelectionMode(QAbstractItemView::SingleSelection);
        outputTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        outputTable->setShowGrid(false);
        outputTable->horizontalHeader()->setDefaultSectionSize(80);
        outputTable->horizontalHeader()->setStretchLastSection(true);
        outputTable->verticalHeader()->setVisible(false);
        timeLabel = new QLabel(ViewRunning);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(70, 193, 141, 21));

        retranslateUi(ViewRunning);

        QMetaObject::connectSlotsByName(ViewRunning);
    } // setupUi

    void retranslateUi(QDialog *ViewRunning)
    {
        ViewRunning->setWindowTitle(QApplication::translate("ViewRunning", "Running Processes", 0, QApplication::UnicodeUTF8));
        toggleUpdateButton->setText(QString());
        closeButton->setText(QApplication::translate("ViewRunning", "Close", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = outputTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewRunning", "CPU ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = outputTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewRunning", "Process ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = outputTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewRunning", "Process Name", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewRunning: public Ui_ViewRunning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWRUNNING_H
