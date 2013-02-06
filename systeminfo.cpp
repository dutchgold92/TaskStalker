#include "systeminfo.h"
#include "ui_systeminfo.h"

SystemInfo::SystemInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemInfo)
{
    ui->setupUi(this);
    ui->kernelVersionLabel->setText(proc::get_kernel_version());
    ui->processorLabel->setText(proc::get_cpu_type() + " (" + QString::number(proc::get_cpu_count()) + " cores)");
    ui->memoryLabel->setText(QString::number(proc::get_memory_size(), 'g', 3) + " GB");
    ui->swapLabel->setText(QString::number(proc::get_swap_size(), 'g', 3) + " GB");
    this->show();
}

SystemInfo::~SystemInfo()
{
    delete ui;
}
