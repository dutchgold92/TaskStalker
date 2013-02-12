/********************************************************************************
** Form generated from reading UI file 'errordialog.ui'
**
** Created: Mon Feb 11 17:02:05 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORDIALOG_H
#define UI_ERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ErrorDialog
{
public:
    QLabel *errorLabel;
    QPushButton *dismissButton;

    void setupUi(QDialog *ErrorDialog)
    {
        if (ErrorDialog->objectName().isEmpty())
            ErrorDialog->setObjectName(QString::fromUtf8("ErrorDialog"));
        ErrorDialog->resize(342, 116);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ErrorDialog->setWindowIcon(icon);
        errorLabel = new QLabel(ErrorDialog);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(10, 10, 321, 61));
        errorLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        errorLabel->setWordWrap(true);
        dismissButton = new QPushButton(ErrorDialog);
        dismissButton->setObjectName(QString::fromUtf8("dismissButton"));
        dismissButton->setGeometry(QRect(130, 80, 71, 27));

        retranslateUi(ErrorDialog);

        QMetaObject::connectSlotsByName(ErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorDialog)
    {
        ErrorDialog->setWindowTitle(QApplication::translate("ErrorDialog", "Error", 0, QApplication::UnicodeUTF8));
        errorLabel->setText(QString());
        dismissButton->setText(QApplication::translate("ErrorDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ErrorDialog: public Ui_ErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORDIALOG_H
