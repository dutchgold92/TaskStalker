/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created: Tue Feb 12 16:22:30 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_4;
    QLabel *logoLabel;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(428, 453);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Info->sizePolicy().hasHeightForWidth());
        Info->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Info->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Info);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 410, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 220, 411, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Bitstream Vera Serif"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        label_3 = new QLabel(Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 280, 391, 81));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        line = new QFrame(Info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(70, 270, 291, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(70, 360, 291, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(Info);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 370, 391, 41));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        logoLabel = new QLabel(Info);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setGeometry(QRect(30, 20, 360, 200));

        retranslateUi(Info);
        QObject::connect(buttonBox, SIGNAL(accepted()), Info, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Info, SLOT(reject()));

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QApplication::translate("Info", "About Task Stalker", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Info", "Graphical process management, visualisation and simulation software for Linux x86_64", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Info", "Released in 2013 by:\n"
"James Colgan (b00039579@student.itb.ie)\n"
"Graham Downey (b00039843@student.itb.ie)\n"
"Brian McGrane (b00026934@student.itb.ie)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Info", "Developed using C++ and Qt4", 0, QApplication::UnicodeUTF8));
        logoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
