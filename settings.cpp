#include "settings.h"
#include "ui_settings.h"

using namespace std;

Settings* Settings::instance = 0;

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->updateIntervalSpinBox->setValue(sys::get_update_interval());
    ui->subUpdateIntervalSpinBox->setValue(sys::get_sub_update_interval());
    ui->runningUpdateIntervalSpinBox->setValue(sys::get_running_update_interval());
    ui->cpuUpdateIntervalSpinBox->setValue(sys::get_cpu_update_interval());
    ui->sortByComboBox->setCurrentIndex(sys::get_sort_by_column());
    ui->sortByOrderComboBox->setCurrentIndex(sys::get_sort_by_order());    
    this->show();
}

/**
 * @brief Settings::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
Settings* Settings::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new Settings(parent);

    return instance;
}

Settings::~Settings()
{
    instance = 0;
    delete ui;
}

void Settings::changeEvent(QEvent *e)
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

/**
  * Action-Listener: Save button
  */
void Settings::on_saveButton_clicked()
{
    sys::set_update_interval(ui->updateIntervalSpinBox->value());
    sys::set_sub_update_interval(ui->subUpdateIntervalSpinBox->value());
    sys::set_running_update_interval(ui->runningUpdateIntervalSpinBox->value());
    sys::set_cpu_update_interval(ui->cpuUpdateIntervalSpinBox->value());
    sys::set_sort_by_column(ui->sortByComboBox->currentIndex());
    sys::set_sort_by_order(ui->sortByOrderComboBox->currentIndex());
    sys::save_config();
    this->close();
}

/**
  * Action-Listener: Cancel button
  */
void Settings::on_cancelButton_clicked()
{
    this->close();
}

/**
  * Action-Listener: Reset All button
  */
void Settings::on_resetAllButton_clicked()
{
    sys::reset_config();
    this->close();
}
