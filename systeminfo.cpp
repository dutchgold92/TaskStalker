#include "systeminfo.h"
#include "ui_systeminfo.h"

SystemInfo* SystemInfo::instance = 0;

SystemInfo::SystemInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemInfo)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    ui->kernelVersionLabel->setText(proc::get_kernel_version());
    ui->processorLabel->setText(proc::get_cpu_type() + " (" + QString::number(proc::get_cpu_count()) + " cores)");
    ui->memoryLabel->setText(QString::number(proc::get_memory_size(), 'g', 3) + " GB");
    ui->swapLabel->setText(QString::number(proc::get_swap_size(), 'g', 3) + " GB");
    this->show();
}

/**
 * @brief SystemInfo::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
SystemInfo* SystemInfo::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new SystemInfo(parent);

    return instance;
}

SystemInfo::~SystemInfo()
{
    instance = 0;
    delete ui;
}
