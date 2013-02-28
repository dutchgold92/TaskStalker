/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created: Thu Feb 28 13:32:14 2013
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
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QFrame *line_2;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(430, 450);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Info->sizePolicy().hasHeightForWidth());
        Info->setSizePolicy(sizePolicy);
        Info->setMinimumSize(QSize(430, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Info->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Info);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logoLabel = new QLabel(Info);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bitstream Vera Serif"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        line = new QFrame(Info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_3 = new QLabel(Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        line_2 = new QFrame(Info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_4 = new QLabel(Info);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        buttonBox = new QDialogButtonBox(Info);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Info);
        QObject::connect(buttonBox, SIGNAL(accepted()), Info, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Info, SLOT(reject()));

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QApplication::translate("Info", "About Task Stalker", 0, QApplication::UnicodeUTF8));
        logoLabel->setText(QString());
        label_2->setText(QApplication::translate("Info", "Graphical process monitoring and management software for Linux-based systems", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Info", "Released in 2013 by:\n"
"James Colgan (dutchgoldservecold@gmail.com)\n"
"Graham Downey (b00039843@student.itb.ie)\n"
"Brian McGrane (b00026934@student.itb.ie)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Info", "Developed using C++ and Qt4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
