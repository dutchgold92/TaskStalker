#include "visualiser.h"
#include "ui_visualiser.h"
#include "proc.h"
#include "confirmkill.h"
#include "sys.h"

using namespace std;

Visualiser::Visualiser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visualiser)
{
    ui->setupUi(this);
}

Visualiser::Visualiser(QWidget *parent, pid_t pid) :
    QDialog(parent),
    ui(new Ui::Visualiser)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    this->active = true;
    this->pid = pid;
    this->show();
    ui->infoTable->setColumnWidth(1, 200);

    QImage visualImage;
    visualImage.load(":/img/blank.png");
    ui->visualContainer->setPixmap(QPixmap::fromImage(visualImage));

    ui->infoTable->setItem(0, 0, new QTableWidgetItem(QString::number(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(proc::get_name(pid)), Qt::DisplayRole));

    update_thread = QtConcurrent::run(this, &Visualiser::update_state);
}

Visualiser::~Visualiser()
{
    active = false;
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
            image.load(":/img/stopped.png");
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
    int result = kill(pid, 9);

    if(result == 0)
    {
        active = false;
        this->done(0);
    }
    else
        perror("Failed to kill process");
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
