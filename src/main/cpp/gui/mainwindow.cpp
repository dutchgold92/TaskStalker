#include "../../../../include/main/cpp/gui/mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->update = true;
    ui->toggleUpdateButton->setIcon(QIcon(":/resources/img/button_pause.png"));

    ui->procTable->setColumnWidth(0, 65);
    ui->procTable->setColumnWidth(1, 125);
    ui->procTable->setColumnWidth(2, 100);
    ui->procTable->setColumnWidth(3, 100);
    ui->procTable->setColumnWidth(4, 75);
    ui->procTable->setColumnWidth(5, 90);

    ui->procTable->horizontalHeader()->setHighlightSections(false);
    ui->procTable->addAction(ui->actionView);
    ui->procTable->addAction(ui->actionViewParent);
    QAction *menu_separator = new QAction(this);
    menu_separator->setSeparator(true);
    ui->procTable->addAction(menu_separator);
    ui->procTable->addAction(ui->actionStop);
    ui->procTable->addAction(ui->actionResume);
    ui->procTable->addAction(ui->actionTerminate);
    ui->procTable->addAction(ui->actionKill);

    for(int x = 0; x < ui->procTable->horizontalHeader()->count(); x++)
        sys::add_process_info_field(ui->procTable->horizontalHeaderItem(x)->text());

    connect(ui->procTable->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(procTable_sorted(int)), Qt::QueuedConnection);
    connect(this, SIGNAL(updated(bool)), this, SLOT(procTable_updated(bool)), Qt::QueuedConnection);
    QtConcurrent::run(this, &MainWindow::update_table);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
  * Action-Listener: Quit button
  */
void MainWindow::on_actionQuit_triggered()
{
    qApp->exit(0);
}

/**
  * Updates the table of processes on the main window,
  * adding a row for every PID with columns displaying
  * the PID, name and state
  */
void MainWindow::update_table()
{
    vector<proc::process> proc_vector;
    QTableWidgetItem *pid_item;
    QTableWidgetItem *procname_item;
    QTableWidgetItem *procstate_item;
    QTableWidgetItem *procprio_item;
    QTableWidgetItem *procuser_item;
    QTableWidgetItem *procmem_item;
    QTableWidgetItem *procppid_item;
    QTableWidgetItem *procthreads_item;

    while(true)
    {
        while(update)
        {
            emit(updated(false));
            proc_vector = proc::list_processes();

            for(size_t x = 0; x < proc_vector.size(); x++)
            {
                signed int row_position = procTable_find_process(proc_vector.at(x).pid);
                pid_item = new QTableWidgetItem;
                pid_item->setData(Qt::DisplayRole, proc_vector.at(x).pid);
                procname_item = new QTableWidgetItem(proc_vector.at(x).name, Qt::DisplayRole);
                procstate_item = new QTableWidgetItem(proc::format_state(proc_vector.at(x).state), Qt::DisplayRole);
                procprio_item = new QTableWidgetItem;
                procprio_item->setData(Qt::DisplayRole, proc_vector.at(x).priority);
                procuser_item = new QTableWidgetItem(proc_vector.at(x).username, Qt::DisplayRole);
                procmem_item = new QTableWidgetItem(proc_vector.at(x).memory_usage, Qt::DisplayRole);
                procppid_item = new QTableWidgetItem;
                procppid_item->setData(Qt::DisplayRole, proc_vector.at(x).ppid);
                procthreads_item = new QTableWidgetItem;
                procthreads_item->setData(Qt::DisplayRole, proc_vector.at(x).threads);

                // Append new row
                if(row_position == -1)
                {
                    row_position = ui->procTable->rowCount();
                    ui->procTable->insertRow(row_position);
                    ui->procTable->setItem(row_position, 3, new QTableWidgetCpuUsageItem());
                }

                ui->procTable->setItem(row_position, 0, pid_item);
                ui->procTable->setItem(row_position, 1, procname_item);
                ui->procTable->setItem(row_position, 2, procstate_item);
                ui->procTable->setItem(row_position, 4, procprio_item);
                ui->procTable->setItem(row_position, 5, procuser_item);
                ui->procTable->setItem(row_position, 6, procmem_item);
                ui->procTable->setItem(row_position, 7, procppid_item);
                ui->procTable->setItem(row_position, 8, procthreads_item);

                proc::cpu_usage usage = proc::get_cpu_usage_independent(proc_vector.at(x).pid, ((QTableWidgetCpuUsageItem*)ui->procTable->item(row_position, 3))->get_last_cpu_jiffies(), ((QTableWidgetCpuUsageItem*)ui->procTable->item(row_position, 3))->get_last_proc_jiffies());

                if(usage.usage == -1)
                    ui->procTable->item(row_position, 3)->setData(Qt::DisplayRole, "Calculating...");
                else
                    ui->procTable->item(row_position, 3)->setData(Qt::DisplayRole, usage.usage);

                ((QTableWidgetCpuUsageItem*)ui->procTable->item(row_position, 3))->set_last_cpu_jiffies(usage.last_cpu_jiffies);
                ((QTableWidgetCpuUsageItem*)ui->procTable->item(row_position, 3))->set_last_proc_jiffies(usage.last_proc_jiffies);
            }

            procTable_remove_dead(proc_vector);
            emit(updated(true));
            sleep(sys::get_update_interval());
        }
    }
}

/**
  * Search the procTable for a column with the specified PID. Return its row index if found, else return -1
  */
int MainWindow::procTable_find_process(pid_t pid)
{
    signed int row = -1;

    for(int x = 0; x < ui->procTable->rowCount(); x++)
    {
        if(ui->procTable->item(x, 0)->text().toInt() == pid)
        {
            row = x;
            break;
        }
    }

    return row;
}

/**
  * Detects and removes rows in ui->procTable representing dead processes
  */
void MainWindow::procTable_remove_dead(vector<proc::process> proc_vector)
{
    bool exists;

    for(int x = 0; x < ui->procTable->rowCount(); x++)
    {
        exists = false;

        for(size_t y = 0; y < proc_vector.size(); y++)
        {
            if(ui->procTable->item(x, 0)->text() == QString::number(proc_vector.at(y).pid))
            {
                exists = true;
                break;
            }
        }

        if(!exists)
            ui->procTable->removeRow(x);
    }
}

/**
  * Stuff to do when the "About" menu entry is selected
  */
void MainWindow::on_actionAbout_triggered()
{
    Info::get_instance(this);
}

/**
  * Stuff to do when the "Documentation" menu entry is selected:
  * Launch the Qt Assistant program, opening our documentation
  */
void MainWindow::on_actionDocumentation_triggered()
{
    QString helpFile = QDir::homePath() + "/.taskstalker/help/help.qhc";
    QProcess *process = new QProcess;
    QStringList args;
    args << QLatin1String("-collectionFile") << QLatin1String(helpFile.toLatin1()) << QLatin1String("-enableRemoteControl");
    process->start(QLatin1String("assistant"), args);

    if(!process->waitForStarted())
        return;
}

/**
  * Stuff to do when the "Simulate" menu entry is selected
  */
void MainWindow::on_actionSimulate_triggered()
{
    SimulatorInit::get_instance(this);
}

/**
  * This should open the process visualisation dialog
  */
void MainWindow::on_procTable_cellDoubleClicked(int row, int column)
{
    new Visualiser(this, atoi(ui->procTable->item(row, 0)->text().toStdString().c_str()));
}

/**
  * Action-Listener: Play/Pause button
  */
void MainWindow::on_toggleUpdateButton_clicked()
{
    if(update)
    {
        update = false;
        ui->toggleUpdateButton->setIcon(QIcon(":/resources/img/button_play.png"));
    }
    else
    {
        update = true;
        ui->toggleUpdateButton->setIcon(QIcon(":/resources/img/button_pause.png"));
    }
}

/**
  * Slot corresponding to update() signal, which is called twice during every procTable update;
  * first time with parameter false when it begins updating and then with parameter true when it finishes
  */
void MainWindow::procTable_updated(bool ready)
{
    if(ready)
    {
        ui->processCountLabel->setText(QString::number(ui->procTable->rowCount()) + " system processes");
        ui->procTable->setSortingEnabled(true);

        if(sys::get_sort_by_order() == 0)
            ui->procTable->sortByColumn(sys::get_sort_by_column(), Qt::AscendingOrder);
        else if(sys::get_sort_by_order() == 1)
            ui->procTable->sortByColumn(sys::get_sort_by_column(), Qt::DescendingOrder);
        else
            ui->procTable->sortByColumn(sys::get_sort_by_column());
    }
    else
    {
        ui->procTable->setSortingEnabled(false);
        ui->procTable->horizontalHeader()->setSortIndicatorShown(true);
    }
}

/**
  * Action-Listener: Settings button
  */
void MainWindow::on_actionSettings_triggered()
{
    Settings::get_instance(this);
}

/**
  * Slot updates sys::sort_by_column and sys::sort_by_order when ui->procTable is sorted via its header.
  */
void MainWindow::procTable_sorted(int column)
{
    // Table is already sorted by this column
    if(column == sys::get_sort_by_column())
    {
        if(sys::get_sort_by_order() == 0)
            sys::set_sort_by_order(1);
        else
            sys::set_sort_by_order(0);
    }
    // Table is already sorted by a different column
    else
    {
        sys::set_sort_by_order(0);
        sys::set_sort_by_column(column);
    }
}

/**
 * @brief MainWindow::on_actionView_triggered Action-Listener for View option of procTable's context menu.
 */
void MainWindow::on_actionView_triggered()
{
    new Visualiser(this, ui->procTable->item(this->selected_row, 0)->text().toInt(), false);
}

/**
 * @brief MainWindow::on_procTable_currentCellChanged Sets selected_row to the newly selected row index.
 * @param currentRow
 * @param currentColumn
 * @param previousRow
 * @param previousColumn
 */
void MainWindow::on_procTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    this->selected_row = currentRow;
}

/**
 * @brief MainWindow::on_actionStop_triggered Action-Listener for Stop option of procTable's context menu.
 */
void MainWindow::on_actionStop_triggered()
{
    if(!proc::stop_process(atoi(ui->procTable->item(this->selected_row, 0)->text().toStdString().c_str())))
        new ErrorDialog(this, false, "Failed to stop process", ErrorDialog::error);
}

/**
 * @brief MainWindow::on_actionResume_triggered Action-Listener for Resume option of procTable's context menu.
 */
void MainWindow::on_actionResume_triggered()
{
    if(!proc::resume_process(atoi(ui->procTable->item(this->selected_row, 0)->text().toStdString().c_str())))
        new ErrorDialog(this, false, "Failed to resume process", ErrorDialog::error);
}

/**
 * @brief MainWindow::on_actionTerminate_triggered Action-Listener for Terminate option of procTable's context menu.
 */
void MainWindow::on_actionTerminate_triggered()
{
    if(!proc::end_process(atoi(ui->procTable->item(this->selected_row, 0)->text().toStdString().c_str())))
        new ErrorDialog(this, false, "Failed to terminate process", ErrorDialog::error);
}

/**
 * @brief MainWindow::on_actionKill_triggered Action-Listener for Kill option of procTable's context menu.
 */
void MainWindow::on_actionKill_triggered()
{
    new ConfirmDialog(this, SLOT(kill_confirmed()), QString("Ending a process in this way may cause data corruption and system instability.\n\nDo you wish to continue?"));
}

/**
 * @brief MainWindow::on_actionSystem_Information_triggered Action-Listener for "View System Information" menu option. Opens SystemInfo dialog.
 */
void MainWindow::on_actionSystem_Information_triggered()
{
    SystemInfo::get_instance(this);
}

/**
 * @brief MainWindow::on_actionSystem_Information_triggered Action-Listener for "View Running" menu option. Opens ViewRunning dialog.
 */
void MainWindow::on_actionRunning_Processes_triggered()
{
    ViewRunning::get_instance(this);
}

/**
 * @brief MainWindow::on_actionSystem_Information_triggered Action-Listener for "View Processor" menu option. Opens ViewProcessorInit dialog.
 */
void MainWindow::on_actionProcessor_Activity_triggered()
{
    ViewProcessorInit::get_instance(this);
}

/**
 * @brief MainWindow::kill_confirmed Called if ConfirmDialog is accepted. Kills selected task.
 */
void MainWindow::kill_confirmed()
{
    if(!proc::kill_process(atoi(ui->procTable->item(this->selected_row, 0)->text().toStdString().c_str())))
        new ErrorDialog(this, false, "Failed to kill process", ErrorDialog::error);
}

/**
 * @brief MainWindow::on_actionProcess_Recording_triggered Triggered if View Recording menu option is selected.
 */
void MainWindow::on_actionProcess_Recording_triggered()
{
    SelectRecording::get_instance(this);
}

/**
 * @brief MainWindow::on_actionViewParent_triggered Called if "View Parent" is selected from context-menu. Opens viewer on parent process, if possible.
 */
void MainWindow::on_actionViewParent_triggered()
{
    if(ui->procTable->item(this->selected_row, 7)->text().toInt())
        new Visualiser(this, ui->procTable->item(this->selected_row, 7)->text().toInt(), false);
    else
        new ErrorDialog(this, false, "This process has no parent", ErrorDialog::error);
}
