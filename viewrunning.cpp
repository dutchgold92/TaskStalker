#include "viewrunning.h"
#include "ui_viewrunning.h"

using namespace std;

ViewRunning* ViewRunning::instance = 0;

ViewRunning::ViewRunning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewRunning)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
    init_table();
    this->update = true;

    qRegisterMetaType<QVector<pid_t> >();
    update_thread = new ViewRunningUpdater();
    update_thread->start();
    connect(update_thread, SIGNAL(updated(QVector<pid_t>)), this, SLOT(receive_update(QVector<pid_t>)), Qt::QueuedConnection);
    connect(this, SIGNAL(paused(bool)), update_thread, SLOT(set_paused(bool)), Qt::QueuedConnection);

    this->show();
}

/**
 * @brief ViewRunning::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
ViewRunning* ViewRunning::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new ViewRunning(parent);

    return instance;
}

ViewRunning::~ViewRunning()
{
    update = false;
    update_thread->terminate();
    instance = 0;
    delete ui;
}

/**
 * @brief ViewRunning::init_table Initialises ui->outputTable
 */
void ViewRunning::init_table()
{
    for(int x = 0; x < proc::get_cpu_count(); x++)
    {
        ui->outputTable->insertRow(x);
        QTableWidgetItem *cell = new QTableWidgetItem();
        cell->setData(Qt::DisplayRole, x);
        ui->outputTable->setItem(x, 0, cell);
        ui->outputTable->setItem(x, 1, new QTableWidgetItem());
        ui->outputTable->setItem(x, 2, new QTableWidgetItem());
    }
}

/**
 * ActionListener: toggleUpdateButton
 * Pause/Resume updating of information displayed in this dialog
 */
void ViewRunning::on_toggleUpdateButton_clicked()
{
    if(update)
    {
        update = false;
        ui->toggleUpdateButton->setIcon(QIcon(":/img/button_play.png"));
        emit(paused(true));
    }
    else
    {
        update = true;
        ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
        emit(paused(false));
    }
}

/**
 * @brief ViewRunning::receive_update Updates the table when the worker thread emits its corresponding signal.
 * @param update_data
 */
void ViewRunning::receive_update(QVector<pid_t> update_data)
{
    ui->timeLabel->setText(QTime::currentTime().toString());

    for(size_t x = 0; x < update_data.size(); x++)
    {
        if(update_data.at(x) == 0)
        {
            ui->outputTable->item(x, 1)->setData(Qt::DisplayRole, "None");
            ui->outputTable->item(x, 2)->setData(Qt::DisplayRole, "-");
        }
        else
        {
            ui->outputTable->item(x, 1)->setData(Qt::DisplayRole, update_data.at(x));
            ui->outputTable->item(x, 2)->setData(Qt::DisplayRole, proc::get_name(update_data.at(x)));
        }
    }
}

/**
 * ActionListener: closeButton
 * Exit the dialog.
 */
void ViewRunning::on_closeButton_clicked()
{
    this->close();
}

/**
 * @brief ViewRunningUpdater::ViewRunningUpdater Constructor for ViewRunning's worker thread class.
 */
ViewRunningUpdater::ViewRunningUpdater()
{
    this->update = true;
}

/**
 * @brief ViewRunningUpdater::run Updater function.
 */
void ViewRunningUpdater::run()
{
    while(true)
    {
        while(update)
        {
            this->setTerminationEnabled(false);
            emit(updated(proc::get_tasks_running()));
            this->setTerminationEnabled(true);
            sleep(sys::get_running_update_interval());
        }
    }
}

/**
 * @brief ViewRunningUpdater::set_paused Pauses/Resumes updating.
 * @param pause
 */
void ViewRunningUpdater::set_paused(bool pause)
{
    if(pause)
        update = false;
    else
        update = true;
}

/**
 * @brief ViewRunning::on_outputTable_cellDoubleClicked Opens a process viewer to display the task in the selected row (if any).
 */
void ViewRunning::on_outputTable_cellDoubleClicked(int row, int column)
{
    pid_t pid = ui->outputTable->item(row, 1)->text().toInt();

    if(pid > 0)
        new Visualiser(this, pid, false);
}
