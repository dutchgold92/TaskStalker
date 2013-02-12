#include "viewprocessorinit.h"
#include "ui_viewprocessorinit.h"

ViewProcessorInit::ViewProcessorInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProcessorInit)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    ui->cpuSelector->setMaximum(proc::get_cpu_count() - 1);
    this->show();
}

ViewProcessorInit::~ViewProcessorInit()
{
    delete ui;
}

void ViewProcessorInit::on_buttonBox_accepted()
{
    new ViewProcessor(this->parentWidget(), ui->cpuSelector->value());
    this->close();
}

void ViewProcessorInit::on_buttonBox_rejected()
{
    this->close();
}
