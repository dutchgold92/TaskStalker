#include "viewrunning.h"
#include "ui_viewrunning.h"

ViewRunning::ViewRunning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewRunning)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));

    for(int x = 0; x < proc::get_cpu_count(); x++)
    {
        ui->outputTable->insertRow(x);
        QTableWidgetItem *cell = new QTableWidgetItem();
        cell->setData(Qt::DisplayRole, x);
        ui->outputTable->setItem(x, 0, cell);
        ui->outputTable->setItem(x, 1, new QTableWidgetItem());
        ui->outputTable->setItem(x, 2, new QTableWidgetItem());
    }

    this->update = true;
    this->closed = false;
    this->update_thread = QtConcurrent::run(this, &ViewRunning::update_info);
    connect(this, SIGNAL(update_data_updated()), this, SLOT(update_outputTable()), Qt::QueuedConnection);
    this->show();
}

ViewRunning::~ViewRunning()
{
    update = false;
    closed = true;
    update_thread.waitForFinished();
    delete ui;
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
    }
    else
    {
        update = true;
        ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
    }
}

/**
 * Updates this->update_string with more recent information from proc::get_tasks_running(),
 * emits a signal so that the GUI can take relevant action, and sleeps for a period of sys::get_sub_update_interval().
 * Should be allocated its own thread of execution.
 */
void ViewRunning::update_info()
{
    while(true)
    {
        while(update)
        {
            update_data = proc::get_tasks_running();
            emit(update_data_updated());
            sleep(sys::get_running_update_interval());
        }

        if(this->closed)
            break;
    }
}

/**
 * Slot to update ui->outputArea when the update_string_updated() signal is emitted.
 */
void ViewRunning::update_outputTable()
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
            ui->outputTable->item(x, 2)->setData(Qt::DisplayRole, QString::fromStdString(proc::get_name(update_data.at(x))));
        }
    }
}

/**
 * ActionListener: closeButton
 * Exit the dialog.
 */
void ViewRunning::on_closeButton_clicked()
{
    this->done(0);
}

/**
 * @brief ViewRunning::on_outputTable_cellDoubleClicked Opens the CPU Viewer if a row is double clicked.
 * @param row
 * @param column
 */
void ViewRunning::on_outputTable_cellDoubleClicked(int row, int column)
{
    new ViewProcessor(this, ui->outputTable->item(row, 0)->text().toInt());
}
