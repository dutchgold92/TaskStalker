#include "visualiser.h"
#include "ui_visualiser.h"

#include <iostream>

using namespace std;

Visualiser::Visualiser(QWidget *parent, pid_t pid, bool simulation) :
    QDialog(parent),
    ui(new Ui::Visualiser)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->update = true;
    this->recording = false;
    this->pid = pid;
    this->simulation = simulation;
    ui->infoTable->setColumnWidth(0, 75);
    ui->infoTable->setColumnWidth(1, 150);
    ui->infoTable->setColumnWidth(3, 100);

    QFile unknown_img(":/img/unknown.svg");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    diagram = new QGraphicsSvgItem(unknown_img.fileName());
    scale_diagram();
    scene->addItem(diagram);

    if(!playing_recording)
    {
        ui->priorityBox->setValue(proc::get_priority(this->pid));
        ui->infoTable->setItem(0, 0, new QTableWidgetItem(QString::number(pid), Qt::DisplayRole));
        ui->infoTable->setItem(0, 1, new QTableWidgetItem(proc::get_name(pid), Qt::DisplayRole));
        ui->infoTable->setItem(0, 3, new QTableWidgetItem(proc::get_username(pid), Qt::DisplayRole));
        update_thread = QtConcurrent::run(this, &Visualiser::update_state);
        connect(this, SIGNAL(missing_process()), this, SLOT(process_not_found()), Qt::QueuedConnection);
    }

    this->show();
}

Visualiser::Visualiser(QWidget *parent, QString recording_file_path) :
    QDialog(parent),
    ui(new Ui::Visualiser)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->update = true;
    this->recording = false;
    this->playing_recording = true;
    this->simulation = false;
    this->recording_file_path = recording_file_path;
    ui->infoTable->setColumnWidth(0, 75);
    ui->infoTable->setColumnWidth(1, 150);
    ui->infoTable->setColumnWidth(3, 100);

    QFile unknown_img(":/img/unknown.svg");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    diagram = new QGraphicsSvgItem(unknown_img.fileName());
    scale_diagram();
    scene->addItem(diagram);

    this->setWindowTitle("Process Recording Viewer");
    ui->recordButton->setEnabled(false);
    ui->timeStamp->setEnabled(true);
    update_thread = QtConcurrent::run(this, &Visualiser::play_recording);
    connect(this, SIGNAL(recording_tick(QString)), this, SLOT(update_recording_timestamp(QString)), Qt::QueuedConnection);

    this->show();
}

Visualiser::~Visualiser()
{
    if(simulation)
        proc::kill_process(this->pid);

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
        state = proc::format_state(proc::get_state(pid));
        QString memory_usage = proc::get_memory_usage(pid);

        if(!state.isEmpty())
        {
            if(recording)
            {
                QFile file(recording_file_path);
                file.open(QIODevice::Append | QIODevice::Text);
                QTextStream out(&file);

                if(state == "Running")
                {
                    if(proc::task_is_executing(pid))
                        out << QTime::currentTime().toString() << "=" << "Executing";
                    else
                        out << QTime::currentTime().toString() << "=" << "Ready";
                }
                else
                    out << QTime::currentTime().toString() << "=" << state;

                out << "=" << memory_usage << "\n";
                file.close();
            }

            ui->infoTable->setItem(0, 2, new QTableWidgetItem(state, Qt::DisplayRole));
            ui->infoTable->setItem(0, 4, new QTableWidgetItem(memory_usage, Qt::DisplayRole));
        }
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
        scene->removeItem(diagram);

        if(ui->infoTable->item(row, column)->text() == "Running")
        {
            if(!playing_recording)
            {
                if(proc::task_is_executing(pid))
                {
                    QFile img(":/img/executing.svg");
                    diagram = new QGraphicsSvgItem(img.fileName());
                }
                else
                {
                    QFile img(":/img/ready.svg");
                    diagram = new QGraphicsSvgItem(img.fileName());
                }
            }
            else
            {
                QFile img(":/img/running.svg");
                diagram = new QGraphicsSvgItem(img.fileName());
            }
        }
        else if(ui->infoTable->item(row, column)->text() == "Executing")
        {
            QFile img(":/img/executing.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }
        else if(ui->infoTable->item(row, column)->text() == "Ready")
        {
            QFile img(":/img/ready.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }
        else if(ui->infoTable->item(row, column)->text() == "Sleeping")
        {
            QFile img(":/img/interruptible.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }
        else if(ui->infoTable->item(row, column)->text() == "Disk Sleep")
        {
            QFile img(":/img/uninterruptible.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }
        else if(ui->infoTable->item(row, column)->text() == "Zombie")
        {
            QFile img(":/img/zombie.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }
        else if(ui->infoTable->item(row, column)->text() == "Stopped")
        {
            ui->stopButton->setText("Resume");
            QFile img(":/img/stopped.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }
        else
        {
            QFile img(":/img/unknown.svg");
            diagram = new QGraphicsSvgItem(img.fileName());
        }

        scale_diagram();
        scene->addItem(diagram);
    }
}

/**
  * Spawns a confirmation dialog when the "Kill" button is clicked
  */
void Visualiser::on_killButton_clicked()
{
    if(!simulation)
        new ConfirmDialog(this, SLOT(kill_confirm_accepted()), QString("Ending a process in this way may cause data corruption and system instability.\n\nDo you wish to continue?"));
    else
        this->kill_confirm_accepted();
}

/**
  * Attempts to kill the selected process if the confirmation dialog was accepted
  */
void Visualiser::kill_confirm_accepted()
{
    if(proc::kill_process(this->pid))
    {
        new ErrorDialog(this, true, "Process successfully terminated.", ErrorDialog::notification);
        update = false;
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
    if(proc::end_process(this->pid))
    {
        new ErrorDialog(this, true, "Process successfully terminated.", ErrorDialog::notification);
        update = false;
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
    if(!proc::set_priority(this->pid, ui->priorityBox->value()))
    {
        ui->priorityBox->setValue(proc::get_priority(this->pid));
        new ErrorDialog(this, false, "Failed to change process priority; you may need to be root.");
    }
}

/**
 * @brief Visualiser::scale_diagram Sets the diagram's scale.
 */
void Visualiser::scale_diagram()
{
    diagram->setScale(0.175 * (ui->graphicsView->height() / 200));
}

/**
 * @brief Visualiser::resizeEvent Actions for when the window has been resized.
 * @param event
 */
void Visualiser::resizeEvent(QResizeEvent *event)
{
    scale_diagram();
}

/**
 * @brief Visualiser::on_recordButton_clicked Toggles recording of the task's activity.
 */
void Visualiser::on_recordButton_clicked()
{
    if(!recording)
        init_record();
    else
    {
        recording = false;
        ui->recordButton->setText("Record");
    }
}

/**
 * @brief Visualiser::init_record Records the process's activity, outputting to a text file.
 */
void Visualiser::init_record()
{
    QString file_name = QTime::currentTime().toString() + "_" + ui->infoTable->item(0, 1)->text() + ".tsr";
    QFile file(QDir::homePath() + "/.taskstalker/recordings/" + file_name);

    if(!file.exists())
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);

        if(file.isWritable())
        {
            out << ui->infoTable->item(0, 0)->text() << "\n" << ui->infoTable->item(0, 1)->text() << "\n" << ui->infoTable->item(0, 3)->text() << "\n";
            file.close();
            recording_file_path = file.fileName();
            recording = true;
            ui->recordButton->setText("Stop Recording");
        }
        else
            cout << "Recording file not writable" << endl;
    }
    else
        cout << "Recording file exists" << endl;
}

/**
 * @brief Visualiser::play_recording Simulates process events based on a previously generated recording.
 */
void Visualiser::play_recording()
{
    QFile file(recording_file_path);

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        ui->infoTable->setItem(0, 0, new QTableWidgetItem(in.readLine(), Qt::DisplayRole));
        this->pid = ui->infoTable->item(0, 0)->text().toInt();
        ui->infoTable->setItem(0, 1, new QTableWidgetItem(in.readLine(), Qt::DisplayRole));
        ui->infoTable->setItem(0, 3, new QTableWidgetItem(in.readLine(), Qt::DisplayRole));

        QString line = in.readLine();

        while(!line.isNull())
        {
            emit(recording_tick(line.left(line.indexOf("="))));
            line.remove(0, (line.indexOf("=") + 1));
            ui->infoTable->setItem(0, 2, new QTableWidgetItem(line.left(line.indexOf("=")), Qt::DisplayRole));
            line.remove(0, (line.indexOf("=") + 1));
            ui->infoTable->setItem(0, 4, new QTableWidgetItem(line, Qt::DisplayRole));
            sleep(1);
            line = in.readLine();
        }
    }
    else
        cout << "File doesn't exist" << endl;
}

/**
 * @brief Visualiser::update_recording_timestamp Slot to update the timestamp for recordings.
 * @param timestamp
 */
void Visualiser::update_recording_timestamp(QString timestamp)
{
    ui->timeStamp->setText(timestamp);
}
