#include "visualiser.h"
#include "ui_visualiser.h"

#include <iostream>

using namespace std;

/**
 * @brief Visualiser::Visualiser Creates a Process Viewer to monitor a live process.
 * @param parent Parent Widget.
 * @param pid Process's ID.
 * @param simulation Whether or not this is a simulation.
 */
Visualiser::Visualiser(QWidget *parent, pid_t pid, bool simulation) : QDialog(parent), ui(new Ui::Visualiser)
{
    ui->setupUi(this);
    qRegisterMetaType<pid_t>("pid_t");
    qRegisterMetaType<proc::cpu_usage>();
    this->pid = pid;
    this->simulation = simulation;
    this->playing_recording = false;
    this->setWindowTitle("Process Viewer");

    init_ui();
    ui->priorityBox->setValue(proc::get_priority(pid));
    ui->infoTable->setItem(0, 0, new QTableWidgetItem(QString::number(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 1, new QTableWidgetItem(proc::get_name(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 3, new QTableWidgetCpuUsageItem());
    ui->infoTable->setItem(0, 4, new QTableWidgetItem(proc::get_username(pid), Qt::DisplayRole));
    ui->infoTable->setItem(0, 6, new QTableWidgetItem(proc::get_parent_pid(pid), Qt::DisplayRole));
    ui->recordOrPlayAgainButton->setText("Record");
    diagram_cpu_label = new QGraphicsSimpleTextItem("CPU: ", 0, scene);

    update_thread = new VisualiserUpdater(pid);
    update_thread->start();
    connect(update_thread, SIGNAL(updated(QStringList)), this, SLOT(receive_update(QStringList)), Qt::QueuedConnection);
    connect(update_thread, SIGNAL(missing_process()), this, SLOT(process_not_found()), Qt::QueuedConnection);
    connect(this, SIGNAL(record(bool, QString)), update_thread, SLOT(set_recording(bool, QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(request_cpu_usage_update(pid_t, unsigned long, unsigned long)), update_thread, SLOT(receive_cpu_usage_update_request(pid_t, unsigned long, unsigned long)), Qt::QueuedConnection);
    connect(update_thread, SIGNAL(update_cpu_usage(proc::cpu_usage)), this, SLOT(receive_cpu_usage_update(proc::cpu_usage)), Qt::QueuedConnection);

    this->show();
}

/**
 * @brief Visualiser::Visualiser Creates a Process Viewer to view a process recording.
 * @param parent Parent Widget.
 * @param recording_file_path Path to the recording file.
 */
Visualiser::Visualiser(QWidget *parent, QString recording_file_path) : QDialog(parent), ui(new Ui::Visualiser)
{
    ui->setupUi(this);
    this->recording_file_path = recording_file_path;
    this->simulation = false;
    this->playing_recording = true;
    this->setWindowTitle("Process Recording Viewer");

    init_ui();
    ui->infoTable->setItem(0, 2, new QTableWidgetItem(Qt::DisplayRole));
    ui->infoTable->setItem(0, 3, new QTableWidgetItem(Qt::DisplayRole));
    ui->infoTable->setItem(0, 5, new QTableWidgetItem(Qt::DisplayRole));
    ui->infoTable->setItem(0, 7, new QTableWidgetItem(Qt::DisplayRole));
    ui->recordOrPlayAgainButton->setText("Play Again");
    ui->recordOrPlayAgainButton->setEnabled(false);
    ui->priorityBox->setEnabled(false);
    ui->priorityButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->endButton->setEnabled(false);
    ui->killButton->setEnabled(false);

    update_thread = new VisualiserUpdater(recording_file_path);
    update_thread->start();
    connect(update_thread, SIGNAL(updated(QStringList)), this, SLOT(receive_update(QStringList)), Qt::QueuedConnection);
    connect(update_thread, SIGNAL(recording_tick(QString,bool)), this, SLOT(update_recording_timestamp(QString,bool)), Qt::QueuedConnection);
    connect(update_thread, SIGNAL(recording_finished()), this, SLOT(end_recording()), Qt::QueuedConnection);
    connect(update_thread, SIGNAL(read_recording_header(QStringList)), this, SLOT(init_recording_playback(QStringList)), Qt::QueuedConnection);

    this->show();
}

Visualiser::~Visualiser()
{
    on_closeButton_clicked();
    this->recording = false;
    update_thread->terminate();
    delete ui;
}

void Visualiser::init_ui()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->infoTable->setColumnWidth(0, 75);
    ui->infoTable->setColumnWidth(1, 125);
    ui->infoTable->setColumnWidth(2, 100);
    ui->infoTable->setColumnWidth(3, 100);
    ui->infoTable->setColumnWidth(4, 90);

    QFile unknown_img(":/img/unknown.svg");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    diagram = new QGraphicsSvgItem(unknown_img.fileName());
    scene->addItem(diagram);
    scale_diagram();
}

/**
 * @brief Visualiser::receive_update Receives updated data from the updater thread.
 * @param update_data
 */
void Visualiser::receive_update(QStringList update_data)
{
    if(!playing_recording)
    {
        ui->infoTable->setItem(0, 2, new QTableWidgetItem(update_data.first(), Qt::DisplayRole));
        ui->infoTable->setItem(0, 5, new QTableWidgetItem(update_data.at(1), Qt::DisplayRole));
        ui->infoTable->setItem(0, 7, new QTableWidgetItem(update_data.last(), Qt::DisplayRole));
        ui->timeStamp->setText(QTime::currentTime().toString());
        emit(request_cpu_usage_update(this->pid, ((QTableWidgetCpuUsageItem*)ui->infoTable->item(0, 3))->get_last_cpu_jiffies(), ((QTableWidgetCpuUsageItem*)ui->infoTable->item(0, 3))->get_last_proc_jiffies()));
    }
    else
    {
        ui->infoTable->item(0, 2)->setData(Qt::DisplayRole, update_data.first());
        ui->infoTable->item(0, 3)->setData(Qt::DisplayRole, update_data.at(1));
        ui->infoTable->item(0, 5)->setData(Qt::DisplayRole, update_data.at(2));
        ui->infoTable->item(0, 7)->setData(Qt::DisplayRole, update_data.last());
    }
}

/**
 * @brief Visualiser::receive_cpu_usage_update Receives updated CPU usage data from the updater thread.
 * @param usage
 */
void Visualiser::receive_cpu_usage_update(proc::cpu_usage usage)
{
    ((QTableWidgetCpuUsageItem*)ui->infoTable->item(0, 3))->set_last_cpu_jiffies(usage.last_cpu_jiffies);
    ((QTableWidgetCpuUsageItem*)ui->infoTable->item(0, 3))->set_last_proc_jiffies(usage.last_proc_jiffies);

    if(usage.usage == -1)
        ui->infoTable->item(0, 3)->setData(Qt::DisplayRole, "Calculating...");
    else
        ui->infoTable->item(0, 3)->setData(Qt::DisplayRole, usage.usage);
}

/**
 * @brief Visualiser::init_recording_playback Sets constant process information from the recording.
 * @param data
 */
void Visualiser::init_recording_playback(QStringList data)
{
    if(data.length() == 4)  // FIXME: why is this all hard-coded? should use an enum or something.
    {
        ui->infoTable->setItem(0, 0, new QTableWidgetItem(data.first(), Qt::DisplayRole));
        ui->infoTable->setItem(0, 1, new QTableWidgetItem(data.at(1), Qt::DisplayRole));
        ui->infoTable->setItem(0, 4, new QTableWidgetItem(data.at(2), Qt::DisplayRole));
        ui->infoTable->setItem(0, 6, new QTableWidgetItem(data.last(), Qt::DisplayRole));
    }
    else
        cout << "Error in update packet" << endl;
}

/**
  * Updates the visualisation image if the process state from ui->infoTable has changed.
  */
void Visualiser::on_infoTable_cellChanged(int row, int column)
{
    if(row == 0 && column == 2)
    {
        if(!playing_recording)
            diagram_cpu_label->setText("CPU: -");

        scene->removeItem(diagram);

        if(ui->infoTable->item(row, column)->text() == "Running")
        {
            if(!playing_recording)
            {
                signed short cpu = proc::task_is_executing(pid);

                if(cpu >= 0)
                {
                    QFile img(":/img/executing.svg");
                    diagram = new QGraphicsSvgItem(img.fileName());
                    diagram_cpu_label->setText("CPU: " + QString::number(cpu));
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
 * @brief Visualiser::on_recordOrPlayAgainButton_clicked Enables/Disables recording or playback of a recording, depending on the situation.
 */
void Visualiser::on_recordOrPlayAgainButton_clicked()
{
    if(!playing_recording)
    {
        if(!recording)
        {
            if(!sys::get_is_recording())
                init_record();
            else
                new ErrorDialog(this, false, "Only one recording may take place simultaneously.", ErrorDialog::error);
        }
        else
        {
            ui->recordOrPlayAgainButton->setText("Record");
            recording = false;
            sys::set_recording(false);
            emit(record(false, recording_file_path));
        }
    }
    else if(playing_recording)
    {
        update_thread->terminate();
        update_thread->start();
        ui->recordOrPlayAgainButton->setEnabled(false);
    }
}

/**
 * @brief Visualiser::init_record Outputs the task's constant information to a recording file, then starts a recording of its variable information.
 */
void Visualiser::init_record()
{
    QString file_name = QDate::currentDate().toString() + "-" + QTime::currentTime().toString() + "_" + ui->infoTable->item(0, 1)->text() + ".tsr";
    QFile file(QDir::homePath() + "/.taskstalker/recordings/" + file_name);

    if(!file.exists())
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);

        if(file.isWritable())
        {
            sys::set_recording(true);
            out << ui->infoTable->item(0, 0)->text() << "\n" << ui->infoTable->item(0, 1)->text() << "\n" << ui->infoTable->item(0, 4)->text() << "\n" << ui->infoTable->item(0, 6)->text() << "\n";
            file.close();
            recording_file_path = file.fileName();
            ui->recordOrPlayAgainButton->setText("Stop Recording");
            recording = true;
            emit(record(true, recording_file_path));
        }
        else
            cout << "Recording file not writable" << endl;
    }
    else
        cout << "Recording file already exists!" << endl;
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
        update_thread->terminate();
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
        update_thread->terminate();
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
 * @brief Visualiser::update_recording_timestamp Updates the timestamp for recordings.
 * @param timestamp
 * @param finished
 */
void Visualiser::update_recording_timestamp(QString timestamp, bool finished)
{
    if(finished)
        ui->timeStamp->setText(timestamp + " (Finished)");
    else
        ui->timeStamp->setText(timestamp + " (Playing)");
}

/**
 * @brief Visualiser::on_closeButton_clicked Closes the dialog.
 */
void Visualiser::on_closeButton_clicked()
{
    if(simulation)
        proc::kill_process(pid);

    this->close();
}

/**
 * @brief Visualiser::end_recording Establishes that the recording has finished.
 */
void Visualiser::end_recording()
{
    ui->recordOrPlayAgainButton->setEnabled(true);
}

/**
 * @brief VisualiserUpdater::VisualiserUpdater Constructor for Visualiser's worker thread - process viewer.
 * @param pid
 */
VisualiserUpdater::VisualiserUpdater(pid_t pid)
{
    this->pid = pid;
    this->playing_recording = false;
    this->recording = false;
}

/**
 * @brief VisualiserUpdater::VisualiserUpdater Constructor for Visualiser's worker thread - recording viewer.
 * @param recording_file_path
 */
VisualiserUpdater::VisualiserUpdater(QString recording_file_path)
{
    this->recording_file_path = recording_file_path;
    this->playing_recording = true;
    this->recording = false;
}

/**
 * @brief VisualiserUpdater::run Update function.
 */
void VisualiserUpdater::run()
{
    if(!playing_recording)
    {
        while(true)
        {
            this->setTerminationEnabled(false);
            QStringList update_data;
            QString state = proc::format_state(proc::get_state(pid));
            QString cpu_usage;
            QString memory_usage = proc::get_memory_usage(pid);
            QString threads = QString::number(proc::get_thread_count(pid));

            if(!(!this->recording && sys::get_is_recording()))  // Ensure that we don't calculate CPU usage in this way if another viewer instance is recording.
                cpu_usage = QString::number(proc::get_cpu_usage(pid));
            else
                cpu_usage = "Calculating...";

            if(cpu_usage == "-1")
                cpu_usage = "Calculating...";

            if(state.isNull() || state.isEmpty())
            {
                emit(missing_process());
                break;
            }
            else
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

                    out << "=" << cpu_usage << "=" << memory_usage << "=" << threads << "\n";
                }

                update_data.push_back(state);
                update_data.push_back(memory_usage);
                update_data.push_back(threads);
            }

            emit(updated(update_data));
            this->setTerminationEnabled(true);
            sleep(sys::get_sub_update_interval());
        }
    }
    else if(playing_recording)
    {
        this->setTerminationEnabled(false);
        QStringList update_data;
        QFile file(recording_file_path);

        if(file.exists())
        {
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            update_data.push_back(in.readLine());
            update_data.push_back(in.readLine());
            update_data.push_back(in.readLine());
            update_data.push_back(in.readLine());

            emit(read_recording_header(update_data));
            QString line = in.readLine();

            while(true)
            {
                this->setTerminationEnabled(false);
                update_data.clear();
                QString timestamp = line.left(line.indexOf("="));
                emit(recording_tick(timestamp, false));
                line.remove(0, (line.indexOf("=") + 1));
                update_data.push_back(line.left(line.indexOf("=")));
                line.remove(0, (line.indexOf("=") + 1));
                update_data.push_back(line.left(line.indexOf("=")));
                line.remove(0, (line.indexOf("=") + 1));
                update_data.push_back(line.left(line.indexOf("=")));
                line.remove(0, (line.indexOf("=") + 1));
                update_data.push_back(line);
                emit(updated(update_data));

                if(in.atEnd())  // end of recording
                {
                    emit(recording_tick(timestamp, true));
                    break;
                }

                line = in.readLine();
                this->setTerminationEnabled(true);
                sleep(QTime::fromString(timestamp).secsTo(QTime::fromString(line.left(line.indexOf("=")))));
            }
        }
        else
            cout << "File doesn't exist" << endl;

        emit(recording_finished());
    }
}

/**
 * @brief VisualiserUpdater::set_recording Commence/End recording.
 * @param record
 */
void VisualiserUpdater::set_recording(bool record, QString file_path)
{
    this->recording_file_path = file_path;
    this->recording = record;
}

/**
 * @brief VisualiserUpdater::receive_cpu_usage_update_request Fulfils request for cpu usage info update.
 */
void VisualiserUpdater::receive_cpu_usage_update_request(pid_t pid, unsigned long last_cpu_jiffies, unsigned long last_proc_jiffies)
{
    proc::cpu_usage usage = proc::get_cpu_usage_independent(pid, last_cpu_jiffies, last_proc_jiffies);
    emit(update_cpu_usage(usage));
}
