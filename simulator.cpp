#include "simulator.h"
#include "ui_simulator.h"

using namespace std;

Simulator::Simulator(QWidget *parent, QString program) :
    QDialog(parent),
    ui(new Ui::Simulator)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    this->show();
    this->update = true;
    ui->infoTable->setColumnWidth(1, 200);

    QImage visualImage;
    visualImage.load(":/img/blank.png");
    ui->visualContainer->setPixmap(QPixmap::fromImage(visualImage));

    if(program == 0)
        program_path = "../busywaiting";
    else
        program_path = program;

    QtConcurrent::run(this, &Simulator::do_fork);
    update_thread = QtConcurrent::run(this, &Simulator::update_state);
    connect(this, SIGNAL(missing_process()), this, SLOT(process_not_found()), Qt::QueuedConnection);
    connect(this, SIGNAL(start_program()), this, SLOT(program_started()), Qt::QueuedConnection);
}

Simulator::~Simulator()
{
    update = false;
    update_thread.waitForFinished();
    process->kill();
    delete ui;
}

void Simulator::changeEvent(QEvent *e)
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
void Simulator::update_state()
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
  * Closes this dialog if selected
  */
void Simulator::on_closeButton_clicked()
{
    this->close();
}

/**
  * Executes the program that is used for simulation
  */
void Simulator::do_fork()
{
    process = new QProcess;
    process->start(program_path);

    if(!process->waitForStarted())
        return;

    pid = process->pid();
    emit(start_program());
}

/**
  * Attempts to kill the simulation program if selected
  */
void Simulator::on_killButton_clicked()
{  
    if(proc::kill_process(this->pid))
        new ErrorDialog(this, false, "Failed to kill process; permission denied.");
}

/**
  * Attempts to stop or continue the simulation program if selected
  */
void Simulator::on_stopButton_clicked()
{
    if(ui->stopButton->text() == "Stop")
    {
        if(proc::stop_process(this->pid))
        {
            ui->stopButton->setText("Resume");
        }
        else
            new ErrorDialog(this, false, "Failed to stop process; permission denied.");
    }
    else
    {
        if(proc::resume_process(this->pid))
        {
            ui->stopButton->setText("Stop");
        }
        else
            new ErrorDialog(this, false, "Failed to resume process; permission denied.");
    }
}

/**
  * Action-Listener: Priority button
  * Attempts the set the simulation program's nice value as per the value in ui->priorityBox
  */
void Simulator::on_priorityButton_clicked()
{
    if(!proc::set_priority(this->pid, ui->priorityBox->value()))
    {
        ui->priorityBox->setValue(proc::get_priority(this->pid));
        new ErrorDialog(this, false, "Failed to change process priority; you may need to be root.");
    }
}

void Simulator::on_infoTable_cellChanged(int row, int column)
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
  * Actions to undertake if the process is suddenly killed by an external means
  */
void Simulator::process_not_found()
{
    new ErrorDialog(this, true, "The process has externally ended and can no longer be monitored.");
}

/**
  * Action-Listener: End button
  */
void Simulator::on_endButton_clicked()
{
    if(proc::end_process(this->pid))
        new ErrorDialog(this, false, "Failed to terminate process; permission denied.");
}

void Simulator::program_started()
{
    ui->infoTable->setItem(0, 0, new QTableWidgetItem(QString::number(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(proc::get_name(pid)), Qt::DisplayRole));
}
