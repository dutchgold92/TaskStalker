#include "errordialog.h"
#include "ui_errordialog.h"

ErrorDialog::ErrorDialog(QWidget *parent, bool exit_parent, QString error_message, type error_type) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    this->parent = parent;
    this->exit_parent = exit_parent;
    ui->setupUi(this);
    ui->errorLabel->setText(error_message);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());

    if(error_type == error)
        this->setWindowTitle("Error");
    else if(error_type == warning)
        this->setWindowTitle("Warning");
    else if(error_type == notification)
        this->setWindowTitle("Notification");

    this->show();
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ErrorDialog::on_dismissButton_clicked()
{
    if(exit_parent)
        parent->close();

    this->close();
}
