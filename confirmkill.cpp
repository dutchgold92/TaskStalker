#include "confirmkill.h"
#include "ui_confirmkill.h"
#include "visualiser.h"

ConfirmKill::ConfirmKill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmKill)
{
    ui->setupUi(this);
    this->show();
    connect(this, SIGNAL(accepted()), parent, SLOT(kill_confirm_accepted()), Qt::QueuedConnection);
}

ConfirmKill::~ConfirmKill()
{
    delete ui;
}

void ConfirmKill::changeEvent(QEvent *e)
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
