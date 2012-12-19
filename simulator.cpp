#include "simulator.h"
#include "ui_simulator.h"
#include "proc.h"

using namespace std;

Simulator::Simulator(QWidget *parent, QString program) :
    QDialog(parent),
    ui(new Ui::Simulator)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    this->show();
    this->active = true;
    ui->infoTable->setColumnWidth(1, 200);

    QImage visualImage;
    visualImage.load(":/img/blank.png");
    ui->visualContainer->setPixmap(QPixmap::fromImage(visualImage));

    if(program == 0)
        program_path = "../busywaiting";
    else
        program_path = program;

    QtConcurrent::run(this, &Simulator::do_fork);
    QtConcurrent::run(this, &Simulator::watcher);
    update_thread = QtConcurrent::run(this, &Simulator::update_state);
}

Simulator::~Simulator()
{
    active = false;
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
    while(active)
    {
        state = proc::get_state(pid);

        if(!state.empty())
        {
            ui->infoTable->setItem(0, 2, new QTableWidgetItem(proc::format_state(state), Qt::DisplayRole));
        }
        else
        {
            perror("Not found");
            cout << "Pid: " << pid << endl;
        }

        sleep(1);
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
}

/**
  * Monitors the simulation program
  */
void Simulator::watcher()
{
    ui->infoTable->setItem(0, 0, new QTableWidgetItem(QString::number(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(proc::get_name(pid)), Qt::DisplayRole));
}

/**
  * Attempts to kill the simulation program if selected
  */
void Simulator::on_killButton_clicked()
{
    if(kill(pid, 9) == 0)
    {

    }
    else
        perror("Failed to kill process");
}

/**
  * Attempts to stop or continue the simulation program if selected
  */
void Simulator::on_stopButton_clicked()
{
    if(ui->stopButton->text() == "Stop")
    {
        if(kill(pid, 19) == 0)
        {
            ui->stopButton->setText("Resume");
        }
        else
            perror("Failed to stop process");
    }
    else
    {
        if(kill(pid, 18) == 0)
        {
            ui->stopButton->setText("Stop");
        }
        else
            perror("Failed to resume process");
    }
}

/**
  * Attempts the set the simulation program's nice value as per the value in ui->priorityBox
  */
void Simulator::on_priorityButton_clicked()
{
    stringstream cmd;
    cmd << "renice " << ui->priorityBox->value() << " " << pid;
    system(cmd.str().c_str());
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
            image.load(":/img/stopped.png");
        else if(ui->infoTable->item(row, column)->text() == "Paging")
            image.load(":/img/unknown.png");  // no image for this currently
        else
            image.load(":/img/unknown.png");

        ui->visualContainer->setPixmap(QPixmap::fromImage(image));
    }
}
