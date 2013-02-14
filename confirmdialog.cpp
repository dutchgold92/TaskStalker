#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent, const char *slot, QString message) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    ui->messageLabel->setText(message);
    connect(this, SIGNAL(accepted()), parent, slot, Qt::QueuedConnection);
    this->show();
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}

void ConfirmDialog::on_continueButton_clicked()
{
    emit(accepted());
    this->close();
}

void ConfirmDialog::on_cancelButton_clicked()
{
    this->close();
}
