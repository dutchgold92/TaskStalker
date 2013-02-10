#include "simulatorinit.h"
#include "ui_simulatorinit.h"

using namespace std;

SimulatorInit::SimulatorInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulatorInit)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
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
  * Action-Listener: Continue button
  */
void SimulatorInit::on_continueButton_clicked()
{
    if(!ui->fileInput->text().isEmpty())
    {
        if(QFile(ui->fileInput->text()).exists())
        {
            process = new QProcess;
            process->start(ui->fileInput->text());

            if(!process->waitForStarted())
                return;

            new Visualiser(this->parentWidget(), process->pid(), true);
            this->close();
        }
        else
        {
            new ErrorDialog(this, false, "Invalid program path or permissions!", ErrorDialog::error);
        }
    }
    else
    {
        new ErrorDialog(this, false, "Invalid program path or permissions!", ErrorDialog::error);
    }
}

/**
  * Action-Listener: Cancel button
  */
void SimulatorInit::on_cancelButton_clicked()
{
    this->close();
}
