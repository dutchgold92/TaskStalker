/********************************************************************************
** Form generated from reading UI file 'visualiser.ui'
**
** Created: Sat Mar 2 14:07:02 2013
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
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Visualiser
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *infoTable;
    QHBoxLayout *controlPanel;
    QSpinBox *priorityBox;
    QPushButton *priorityButton;
    QPushButton *stopButton;
    QPushButton *endButton;
    QPushButton *killButton;
    QHBoxLayout *graphicsViewPanel;
    QGraphicsView *graphicsView;
    QHBoxLayout *bottomPanel;
    QPushButton *recordOrPlayAgainButton;
    QLabel *timeStamp;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Visualiser)
    {
        if (Visualiser->objectName().isEmpty())
            Visualiser->setObjectName(QString::fromUtf8("Visualiser"));
        Visualiser->setEnabled(true);
        Visualiser->resize(550, 555);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Visualiser->sizePolicy().hasHeightForWidth());
        Visualiser->setSizePolicy(sizePolicy);
        Visualiser->setMinimumSize(QSize(550, 555));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Visualiser->setWindowIcon(icon);
        Visualiser->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(Visualiser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoTable = new QTableWidget(Visualiser);
        if (infoTable->columnCount() < 5)
            infoTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (infoTable->rowCount() < 1)
            infoTable->setRowCount(1);
        infoTable->setObjectName(QString::fromUtf8("infoTable"));
        infoTable->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoTable->sizePolicy().hasHeightForWidth());
        infoTable->setSizePolicy(sizePolicy1);
        infoTable->setMinimumSize(QSize(520, 60));
        infoTable->setMaximumSize(QSize(16777215, 60));
        infoTable->setFrameShape(QFrame::StyledPanel);
        infoTable->setFrameShadow(QFrame::Sunken);
        infoTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTable->setSelectionMode(QAbstractItemView::NoSelection);
        infoTable->setShowGrid(false);
        infoTable->setWordWrap(false);
        infoTable->setRowCount(1);
        infoTable->setColumnCount(5);
        infoTable->horizontalHeader()->setMinimumSectionSize(40);
        infoTable->horizontalHeader()->setStretchLastSection(true);
        infoTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(infoTable);

        controlPanel = new QHBoxLayout();
        controlPanel->setObjectName(QString::fromUtf8("controlPanel"));
        priorityBox = new QSpinBox(Visualiser);
        priorityBox->setObjectName(QString::fromUtf8("priorityBox"));
        priorityBox->setMinimumSize(QSize(0, 25));
        priorityBox->setMinimum(-20);
        priorityBox->setMaximum(20);

        controlPanel->addWidget(priorityBox);

        priorityButton = new QPushButton(Visualiser);
        priorityButton->setObjectName(QString::fromUtf8("priorityButton"));
        priorityButton->setMinimumSize(QSize(0, 25));

        controlPanel->addWidget(priorityButton);

        stopButton = new QPushButton(Visualiser);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMinimumSize(QSize(0, 25));

        controlPanel->addWidget(stopButton);

        endButton = new QPushButton(Visualiser);
        endButton->setObjectName(QString::fromUtf8("endButton"));
        endButton->setMinimumSize(QSize(0, 25));

        controlPanel->addWidget(endButton);

        killButton = new QPushButton(Visualiser);
        killButton->setObjectName(QString::fromUtf8("killButton"));
        killButton->setMinimumSize(QSize(0, 25));

        controlPanel->addWidget(killButton);


        verticalLayout->addLayout(controlPanel);

        graphicsViewPanel = new QHBoxLayout();
        graphicsViewPanel->setObjectName(QString::fromUtf8("graphicsViewPanel"));
        graphicsViewPanel->setSizeConstraint(QLayout::SetMinimumSize);
        graphicsView = new QGraphicsView(Visualiser);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(520, 400));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

        graphicsViewPanel->addWidget(graphicsView);


        verticalLayout->addLayout(graphicsViewPanel);

        bottomPanel = new QHBoxLayout();
        bottomPanel->setObjectName(QString::fromUtf8("bottomPanel"));
        recordOrPlayAgainButton = new QPushButton(Visualiser);
        recordOrPlayAgainButton->setObjectName(QString::fromUtf8("recordOrPlayAgainButton"));
        recordOrPlayAgainButton->setMinimumSize(QSize(80, 30));

        bottomPanel->addWidget(recordOrPlayAgainButton);

        timeStamp = new QLabel(Visualiser);
        timeStamp->setObjectName(QString::fromUtf8("timeStamp"));
        timeStamp->setEnabled(true);
        timeStamp->setMinimumSize(QSize(150, 0));

        bottomPanel->addWidget(timeStamp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomPanel->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(Visualiser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        buttonBox->setMinimumSize(QSize(80, 30));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        bottomPanel->addWidget(buttonBox);


        verticalLayout->addLayout(bottomPanel);


        retranslateUi(Visualiser);
        QObject::connect(buttonBox, SIGNAL(accepted()), Visualiser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Visualiser, SLOT(reject()));

        QMetaObject::connectSlotsByName(Visualiser);
    } // setupUi

    void retranslateUi(QDialog *Visualiser)
    {
        Visualiser->setWindowTitle(QApplication::translate("Visualiser", "Process View", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = infoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Visualiser", "ID", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem->setToolTip(QApplication::translate("Visualiser", "A task's Process ID is a unique number used to identify it.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem1 = infoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Visualiser", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem1->setToolTip(QApplication::translate("Visualiser", "The command name associated with the process.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem2 = infoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Visualiser", "State", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem2->setToolTip(QApplication::translate("Visualiser", "Information regarding the current status of the process.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem3 = infoTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Visualiser", "User", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem3->setToolTip(QApplication::translate("Visualiser", "Username of the owner of the process.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem4 = infoTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Visualiser", "Memory", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem4->setToolTip(QApplication::translate("Visualiser", "The sum of virtual memory allocated to the task. This memory may be shared.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        priorityBox->setPrefix(QString());
        priorityButton->setText(QApplication::translate("Visualiser", "Set Priority", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("Visualiser", "Stop", 0, QApplication::UnicodeUTF8));
        endButton->setText(QApplication::translate("Visualiser", "Terminate", 0, QApplication::UnicodeUTF8));
        killButton->setText(QApplication::translate("Visualiser", "Kill", 0, QApplication::UnicodeUTF8));
        recordOrPlayAgainButton->setText(QString());
        timeStamp->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Visualiser: public Ui_Visualiser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALISER_H
