/********************************************************************************
** Form generated from reading UI file 'viewrunning.ui'
**
** Created: Thu Feb 28 13:32:14 2013
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewRunning
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *outputTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *toggleUpdateButton;
    QLabel *timeLabel;
    QPushButton *closeButton;

    void setupUi(QDialog *ViewRunning)
    {
        if (ViewRunning->objectName().isEmpty())
            ViewRunning->setObjectName(QString::fromUtf8("ViewRunning"));
        ViewRunning->resize(400, 225);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ViewRunning->sizePolicy().hasHeightForWidth());
        ViewRunning->setSizePolicy(sizePolicy);
        ViewRunning->setMinimumSize(QSize(400, 225));
        verticalLayout = new QVBoxLayout(ViewRunning);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
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
        outputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        outputTable->setAlternatingRowColors(true);
        outputTable->setSelectionMode(QAbstractItemView::NoSelection);
        outputTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        outputTable->setShowGrid(false);
        outputTable->horizontalHeader()->setDefaultSectionSize(80);
        outputTable->horizontalHeader()->setStretchLastSection(true);
        outputTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(outputTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        toggleUpdateButton = new QPushButton(ViewRunning);
        toggleUpdateButton->setObjectName(QString::fromUtf8("toggleUpdateButton"));

        horizontalLayout->addWidget(toggleUpdateButton);

        timeLabel = new QLabel(ViewRunning);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(timeLabel);

        closeButton = new QPushButton(ViewRunning);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ViewRunning);

        QMetaObject::connectSlotsByName(ViewRunning);
    } // setupUi

    void retranslateUi(QDialog *ViewRunning)
    {
        ViewRunning->setWindowTitle(QApplication::translate("ViewRunning", "Running Processes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = outputTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewRunning", "CPU ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = outputTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewRunning", "Process ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = outputTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewRunning", "Process Name", 0, QApplication::UnicodeUTF8));
        toggleUpdateButton->setText(QString());
        timeLabel->setText(QString());
        closeButton->setText(QApplication::translate("ViewRunning", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewRunning: public Ui_ViewRunning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWRUNNING_H
