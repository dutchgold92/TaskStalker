/********************************************************************************
** Form generated from reading UI file 'confirmkill.ui'
**
** Created: Fri Dec 28 18:26:09 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMKILL_H
#define UI_CONFIRMKILL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ConfirmKill
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *ConfirmKill)
    {
        if (ConfirmKill->objectName().isEmpty())
            ConfirmKill->setObjectName(QString::fromUtf8("ConfirmKill"));
        ConfirmKill->resize(389, 142);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfirmKill->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(ConfirmKill);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 100, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Yes);
        label = new QLabel(ConfirmKill);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 371, 91));
        label->setWordWrap(true);

        retranslateUi(ConfirmKill);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfirmKill, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfirmKill, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfirmKill);
    } // setupUi

    void retranslateUi(QDialog *ConfirmKill)
    {
        ConfirmKill->setWindowTitle(QApplication::translate("ConfirmKill", "Warning!", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfirmKill", "Ending the process in this way may cause data corruption, system instability or possibly end your session. Unless the program has become unresponsive, it is advisable that you exit it normally.\n"
"\n"
"Do you wish to continue?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfirmKill: public Ui_ConfirmKill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMKILL_H
