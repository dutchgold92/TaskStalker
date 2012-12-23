#include "settings.h"
#include "ui_settings.h"
#include "sys.h"

using namespace std;

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    ui->updateIntervalSpinBox->setValue(sys::get_update_interval());
    ui->subUpdateIntervalSpinBox->setValue(sys::get_sub_update_interval());
    ui->sortByComboBox->setCurrentIndex(sys::get_sort_by());
    this->show();
}

Settings::~Settings()
{
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

void Settings::on_applyButton_clicked()
{
    sys::set_update_interval(ui->updateIntervalSpinBox->value());
    sys::set_sub_update_interval(ui->subUpdateIntervalSpinBox->value());
    sys::set_sort_by(ui->sortByComboBox->currentIndex());
    sys::save_config();
    this->close();
}

void Settings::on_cancelButton_clicked()
{
    this->close();
}

void Settings::on_resetAllButton_clicked()
{
    sys::reset_config();
    this->close();
}
