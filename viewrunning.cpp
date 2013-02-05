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
    this->update = true;
    this->closed = false;
    this->update_thread = QtConcurrent::run(this, &ViewRunning::update_info);
    connect(this, SIGNAL(update_string_updated()), this, SLOT(update_outputArea()), Qt::QueuedConnection);
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
            update_string = proc::get_tasks_running();
            emit(update_string_updated());
            sleep(sys::get_running_update_interval());
        }

        if(this->closed)
            break;
    }
}

/**
 * Slot to update ui->outputArea when the update_string_updated() signal is emitted.
 */
void ViewRunning::update_outputArea()
{
    ui->outputArea->append(update_string);
}

/**
 * ActionListener: closeButton
 * Exit the dialog.
 */
void ViewRunning::on_closeButton_clicked()
{
    this->done(0);
}
