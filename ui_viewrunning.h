/********************************************************************************
** Form generated from reading UI file 'viewrunning.ui'
**
** Created: Wed Jan 9 22:28:08 2013
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
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ViewRunning
{
public:
    QTextBrowser *outputArea;
    QPushButton *toggleUpdateButton;
    QPushButton *closeButton;

    void setupUi(QDialog *ViewRunning)
    {
        if (ViewRunning->objectName().isEmpty())
            ViewRunning->setObjectName(QString::fromUtf8("ViewRunning"));
        ViewRunning->resize(400, 300);
        outputArea = new QTextBrowser(ViewRunning);
        outputArea->setObjectName(QString::fromUtf8("outputArea"));
        outputArea->setGeometry(QRect(10, 10, 381, 241));
        toggleUpdateButton = new QPushButton(ViewRunning);
        toggleUpdateButton->setObjectName(QString::fromUtf8("toggleUpdateButton"));
        toggleUpdateButton->setGeometry(QRect(10, 260, 51, 31));
        closeButton = new QPushButton(ViewRunning);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(324, 260, 71, 31));

        retranslateUi(ViewRunning);

        QMetaObject::connectSlotsByName(ViewRunning);
    } // setupUi

    void retranslateUi(QDialog *ViewRunning)
    {
        ViewRunning->setWindowTitle(QApplication::translate("ViewRunning", "Recently Running Processes", 0, QApplication::UnicodeUTF8));
        toggleUpdateButton->setText(QString());
        closeButton->setText(QApplication::translate("ViewRunning", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewRunning: public Ui_ViewRunning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWRUNNING_H
