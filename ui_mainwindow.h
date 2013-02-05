/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jan 19 16:52:14 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionDocumentation;
    QAction *actionSimulate;
    QAction *actionAbout;
    QAction *actionSettings;
    QAction *actionViewRunning;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QPushButton *toggleUpdateButton;
    QLabel *processCountLabel;
    QLabel *cpuCountLabel;
    QTableWidget *procTable;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuID;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 315);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 315));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        actionSimulate = new QAction(MainWindow);
        actionSimulate->setObjectName(QString::fromUtf8("actionSimulate"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionViewRunning = new QAction(MainWindow);
        actionViewRunning->setObjectName(QString::fromUtf8("actionViewRunning"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox->setFlat(false);
        toggleUpdateButton = new QPushButton(groupBox);
        toggleUpdateButton->setObjectName(QString::fromUtf8("toggleUpdateButton"));
        toggleUpdateButton->setGeometry(QRect(0, 0, 58, 27));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toggleUpdateButton->sizePolicy().hasHeightForWidth());
        toggleUpdateButton->setSizePolicy(sizePolicy2);
        processCountLabel = new QLabel(groupBox);
        processCountLabel->setObjectName(QString::fromUtf8("processCountLabel"));
        processCountLabel->setGeometry(QRect(70, 0, 321, 21));
        cpuCountLabel = new QLabel(groupBox);
        cpuCountLabel->setObjectName(QString::fromUtf8("cpuCountLabel"));
        cpuCountLabel->setGeometry(QRect(400, 0, 181, 21));
        cpuCountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cpuCountLabel->setMargin(2);

        verticalLayout->addWidget(groupBox);

        procTable = new QTableWidget(centralWidget);
        if (procTable->columnCount() < 4)
            procTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        procTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        procTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        procTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        procTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        procTable->setObjectName(QString::fromUtf8("procTable"));
        sizePolicy1.setHeightForWidth(procTable->sizePolicy().hasHeightForWidth());
        procTable->setSizePolicy(sizePolicy1);
        procTable->setLineWidth(1);
        procTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        procTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        procTable->setShowGrid(true);
        procTable->setGridStyle(Qt::NoPen);
        procTable->setSortingEnabled(true);
        procTable->setCornerButtonEnabled(true);
        procTable->setColumnCount(4);
        procTable->horizontalHeader()->setVisible(true);
        procTable->horizontalHeader()->setCascadingSectionResizes(false);
        procTable->horizontalHeader()->setDefaultSectionSize(150);
        procTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        procTable->horizontalHeader()->setStretchLastSection(true);
        procTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(procTable);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 600, 29));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuID = new QMenu(menuBar);
        menuID->setObjectName(QString::fromUtf8("menuID"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuID->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionAbout);
        menuTools->addAction(actionSimulate);
        menuTools->addAction(actionSettings);
        menuTools->addAction(actionViewRunning);
        menuID->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Task Stalker", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", 0, QApplication::UnicodeUTF8));
        actionSimulate->setText(QApplication::translate("MainWindow", "Simulate", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionViewRunning->setText(QApplication::translate("MainWindow", "View Running", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        toggleUpdateButton->setText(QString());
        processCountLabel->setText(QApplication::translate("MainWindow", "XXX system processes", 0, QApplication::UnicodeUTF8));
        cpuCountLabel->setText(QApplication::translate("MainWindow", "X available CPU(s)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = procTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Process ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = procTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = procTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = procTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Priority", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuID->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
