#include "simulatorinit.h"
#include "ui_simulatorinit.h"
#include "simulator.h"

SimulatorInit::SimulatorInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulatorInit)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    ui->errorLabel->setVisible(false);
    this->show();
}

SimulatorInit::~SimulatorInit()
{
    delete ui;
}

void SimulatorInit::changeEvent(QEvent *e)
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
  * Action-Listener: Use Default button
  */
void SimulatorInit::on_useDefaultButton_clicked()
{
    new Simulator(this);
    this->hide();
}

/**
  * Action-Listener: Continue button
  */
void SimulatorInit::on_continueButton_clicked()
{
    if(QFile(ui->fileInput->text()).exists())
    {
        new Simulator(this, ui->fileInput->text());
        this->hide();
    }
    else
        ui->errorLabel->setVisible(true);
}

/**
  * Action-Listener: Cancel button
  */
void SimulatorInit::on_cancelButton_clicked()
{
    this->close();
}
