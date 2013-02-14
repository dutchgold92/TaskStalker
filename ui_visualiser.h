/********************************************************************************
** Form generated from reading UI file 'visualiser.ui'
**
** Created: Thu Feb 14 19:40:13 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALISER_H
#define UI_VISUALISER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Visualiser
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *visualContainer;
    QTableWidget *infoTable;
    QPushButton *killButton;
    QPushButton *stopButton;
    QPushButton *endButton;
    QSpinBox *priorityBox;
    QPushButton *priorityButton;

    void setupUi(QDialog *Visualiser)
    {
        if (Visualiser->objectName().isEmpty())
            Visualiser->setObjectName(QString::fromUtf8("Visualiser"));
        Visualiser->resize(549, 510);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Visualiser->sizePolicy().hasHeightForWidth());
        Visualiser->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Visualiser->setWindowIcon(icon);
        Visualiser->setAutoFillBackground(false);
        buttonBox = new QDialogButtonBox(Visualiser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(450, 470, 91, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);
        visualContainer = new QLabel(Visualiser);
        visualContainer->setObjectName(QString::fromUtf8("visualContainer"));
        visualContainer->setGeometry(QRect(10, 60, 531, 401));
        infoTable = new QTableWidget(Visualiser);
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
        infoTable->setGeometry(QRect(0, 0, 551, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoTable->sizePolicy().hasHeightForWidth());
        infoTable->setSizePolicy(sizePolicy1);
        infoTable->setFrameShape(QFrame::Panel);
        infoTable->setFrameShadow(QFrame::Raised);
        infoTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTable->setSelectionMode(QAbstractItemView::NoSelection);
        infoTable->setShowGrid(false);
        infoTable->setWordWrap(false);
        infoTable->setRowCount(1);
        infoTable->setColumnCount(3);
        infoTable->horizontalHeader()->setMinimumSectionSize(40);
        infoTable->horizontalHeader()->setStretchLastSection(true);
        infoTable->verticalHeader()->setVisible(false);
        killButton = new QPushButton(Visualiser);
        killButton->setObjectName(QString::fromUtf8("killButton"));
        killButton->setGeometry(QRect(500, 70, 41, 27));
        stopButton = new QPushButton(Visualiser);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(370, 70, 75, 27));
        endButton = new QPushButton(Visualiser);
        endButton->setObjectName(QString::fromUtf8("endButton"));
        endButton->setGeometry(QRect(450, 70, 41, 27));
        priorityBox = new QSpinBox(Visualiser);
        priorityBox->setObjectName(QString::fromUtf8("priorityBox"));
        priorityBox->setGeometry(QRect(210, 70, 55, 25));
        priorityBox->setMinimum(-20);
        priorityBox->setMaximum(20);
        priorityButton = new QPushButton(Visualiser);
        priorityButton->setObjectName(QString::fromUtf8("priorityButton"));
        priorityButton->setGeometry(QRect(270, 70, 91, 27));

        retranslateUi(Visualiser);
        QObject::connect(buttonBox, SIGNAL(accepted()), Visualiser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Visualiser, SLOT(reject()));

        QMetaObject::connectSlotsByName(Visualiser);
    } // setupUi

    void retranslateUi(QDialog *Visualiser)
    {
        Visualiser->setWindowTitle(QApplication::translate("Visualiser", "Process View", 0, QApplication::UnicodeUTF8));
        visualContainer->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = infoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Visualiser", "Process ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = infoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Visualiser", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = infoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Visualiser", "State", 0, QApplication::UnicodeUTF8));
        killButton->setText(QApplication::translate("Visualiser", "Kill", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("Visualiser", "Stop", 0, QApplication::UnicodeUTF8));
        endButton->setText(QApplication::translate("Visualiser", "End", 0, QApplication::UnicodeUTF8));
        priorityBox->setPrefix(QString());
        priorityButton->setText(QApplication::translate("Visualiser", "Set Priority", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Visualiser: public Ui_Visualiser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALISER_H
