#include "viewprocessorinit.h"
#include "ui_viewprocessorinit.h"

ViewProcessorInit* ViewProcessorInit::instance = 0;

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

/**
 * @brief ViewProcessorInit::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
ViewProcessorInit* ViewProcessorInit::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new ViewProcessorInit(parent);

    return instance;
}

ViewProcessorInit::~ViewProcessorInit()
{
    instance = 0;
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
