#include "visualiser.h"
#include "ui_visualiser.h"
#include "proc.h"
#include "confirmkill.h"
#include "sys.h"
#include "errordialog.h"

using namespace std;

Visualiser::Visualiser(QWidget *parent, pid_t pid) :
    QDialog(parent),
    ui(new Ui::Visualiser)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    this->update = true;
    this->pid = pid;
    ui->infoTable->setColumnWidth(1, 200);
    ui->priorityBox->setValue(proc::get_priority(this->pid));

    QImage visualImage;
    visualImage.load(":/img/blank.png");
    ui->visualContainer->setPixmap(QPixmap::fromImage(visualImage));

    ui->infoTable->setItem(0, 0, new QTableWidgetItem(QString::number(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(proc::get_name(pid)), Qt::DisplayRole));

    update_thread = QtConcurrent::run(this, &Visualiser::update_state);
    connect(this, SIGNAL(missing_process()), this, SLOT(process_not_found()), Qt::QueuedConnection);
    this->show();
}

Visualiser::~Visualiser()
{
    update = false;
    update_thread.waitForFinished();
    delete ui;
}

void Visualiser::changeEvent(QEvent *e)
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
  * Update the process data in the dialog
  */
void Visualiser::update_state()
{
    while(update)
    {
        state = proc::get_state(pid);

        if(!state.empty())
            ui->infoTable->setItem(0, 2, new QTableWidgetItem(proc::format_state(state), Qt::DisplayRole));
        else
        {
            update = false;
            emit(missing_process());
            break;
        }

        sleep(sys::get_sub_update_interval());
    }
}

/**
  * Updates the visualisation image if the process state from ui->infoTable has changed.
  */
void Visualiser::on_infoTable_cellChanged(int row, int column)
{
    if(row == 0 && column == 2)
    {
        if(ui->infoTable->item(row, column)->text() == "Running")
            image.load(":/img/running.png");
        else if(ui->infoTable->item(row, column)->text() == "Sleeping")
            image.load(":/img/interruptible.png");
        else if(ui->infoTable->item(row, column)->text() == "Disk Sleep")
            image.load(":/img/uninterruptible.png");
        else if(ui->infoTable->item(row, column)->text() == "Zombie")
            image.load(":/img/zombie.png");
        else if(ui->infoTable->item(row, column)->text() == "Stopped")
        {
            ui->stopButton->setText("Resume");
            image.load(":/img/stopped.png");
        }
        else if(ui->infoTable->item(row, column)->text() == "Paging")
            image.load(":/img/unknown.png");  // no image for this currently
        else
            image.load(":/img/unknown.png");

        ui->visualContainer->setPixmap(QPixmap::fromImage(image));
    }
}

/**
  * Spawns a confirmation dialog when the "Kill" button is clicked
  */
void Visualiser::on_killButton_clicked()
{
    new ConfirmKill(this);
}

/**
  * Attempts to kill the selected process if the confirmation dialog was accepted
  */
void Visualiser::kill_confirm_accepted()
{
    if(kill(pid, 9) == 0)
    {
        update = false;
        this->done(0);
    }
    else
        new ErrorDialog(this, false, "Failed to kill process; permission denied.");
}

/**
  * Action-Listener: Stop/Resume button
  */
void Visualiser::on_stopButton_clicked()
{
    if(ui->stopButton->text() == "Stop")
    {
        if(kill(pid, 19) == 0)
        {
            ui->stopButton->setText("Resume");
        }
        else
            new ErrorDialog(this, false, "Failed to stop process; permission denied.");
    }
    else
    {
        if(kill(pid, 18) == 0)
        {
            ui->stopButton->setText("Stop");
        }
        else
            new ErrorDialog(this, false, "Failed to resume process; permission denied.");
    }
}

/**
  * Actions to undertake if the process is suddenly killed by an external means
  */
void Visualiser::process_not_found()
{
    new ErrorDialog(this, true, "The process has externally ended and can no longer be monitored.");
}

/**
  * Action-Listener: End button
  */
void Visualiser::on_endButton_clicked()
{
    if(kill(pid, 15) == 0)
    {
        update = false;
        this->done(0);
    }
    else
        new ErrorDialog(this, false, "Failed to terminate process; permission denied.");
}

/**
  * Action-Listener: Priority button
  * Attempts the set the simulation program's nice value as per the value in ui->priorityBox
  */
void Visualiser::on_priorityButton_clicked()
{
    if(setpriority(PRIO_PROCESS, this->pid, ui->priorityBox->value()) == -1)
        new ErrorDialog(this, false, "Failed to change process priority; you may need to be root.");
}
