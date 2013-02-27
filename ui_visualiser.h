/********************************************************************************
** Form generated from reading UI file 'visualiser.ui'
**
** Created: Wed Feb 27 21:35:37 2013
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
    QHBoxLayout *horizontalLayout;
    QSpinBox *priorityBox;
    QPushButton *priorityButton;
    QPushButton *stopButton;
    QPushButton *endButton;
    QPushButton *killButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *visualContainer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
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
        if (infoTable->columnCount() < 4)
            infoTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        infoTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
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
        infoTable->setColumnCount(4);
        infoTable->horizontalHeader()->setMinimumSectionSize(40);
        infoTable->horizontalHeader()->setStretchLastSection(true);
        infoTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(infoTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        priorityBox = new QSpinBox(Visualiser);
        priorityBox->setObjectName(QString::fromUtf8("priorityBox"));
        priorityBox->setMinimumSize(QSize(0, 25));
        priorityBox->setMinimum(-20);
        priorityBox->setMaximum(20);

        horizontalLayout->addWidget(priorityBox);

        priorityButton = new QPushButton(Visualiser);
        priorityButton->setObjectName(QString::fromUtf8("priorityButton"));
        priorityButton->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(priorityButton);

        stopButton = new QPushButton(Visualiser);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(stopButton);

        endButton = new QPushButton(Visualiser);
        endButton->setObjectName(QString::fromUtf8("endButton"));
        endButton->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(endButton);

        killButton = new QPushButton(Visualiser);
        killButton->setObjectName(QString::fromUtf8("killButton"));
        killButton->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(killButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        visualContainer = new QLabel(Visualiser);
        visualContainer->setObjectName(QString::fromUtf8("visualContainer"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(visualContainer->sizePolicy().hasHeightForWidth());
        visualContainer->setSizePolicy(sizePolicy2);
        visualContainer->setLayoutDirection(Qt::LeftToRight);
        visualContainer->setPixmap(QPixmap(QString::fromUtf8(":/img/unknown.png")));
        visualContainer->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(visualContainer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(Visualiser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        buttonBox->setMinimumSize(QSize(0, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Visualiser);
        QObject::connect(buttonBox, SIGNAL(accepted()), Visualiser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Visualiser, SLOT(reject()));

        QMetaObject::connectSlotsByName(Visualiser);
    } // setupUi

    void retranslateUi(QDialog *Visualiser)
    {
        Visualiser->setWindowTitle(QApplication::translate("Visualiser", "Process View", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = infoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Visualiser", "Process ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = infoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Visualiser", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = infoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Visualiser", "State", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = infoTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Visualiser", "Allocated Memory", 0, QApplication::UnicodeUTF8));
        priorityBox->setPrefix(QString());
        priorityButton->setText(QApplication::translate("Visualiser", "Set Priority", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("Visualiser", "Stop", 0, QApplication::UnicodeUTF8));
        endButton->setText(QApplication::translate("Visualiser", "Terminate", 0, QApplication::UnicodeUTF8));
        killButton->setText(QApplication::translate("Visualiser", "Kill", 0, QApplication::UnicodeUTF8));
        visualContainer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Visualiser: public Ui_Visualiser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALISER_H
