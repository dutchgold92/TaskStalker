#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proc.h"
#include "visualiser.h"
#include "info.h"
#include "simulatorinit.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    init_help();
    ui->setupUi(this);
    this->update = true;
    ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
    ui->procTable->setColumnWidth(0, 100);
    ui->procTable->setColumnWidth(1, 200);
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

    while(true)
    {
        while(update)
        {
            emit(updated(false));
            ui->procTable->setRowCount(0);
            proc_vector = proc::list_processes();

            for(size_t x = 0; x < proc_vector.size(); x++)
            {
                pid_item = new QTableWidgetItem;
                pid_item->setData(Qt::DisplayRole, atoi(proc_vector.at(x).pid.c_str()));
                procname_item = new QTableWidgetItem(QString::fromStdString(proc_vector.at(x).name), Qt::DisplayRole);
                procstate_item = new QTableWidgetItem(proc::format_state(proc_vector.at(x).state), Qt::DisplayRole);

                ui->procTable->insertRow(x);
                ui->procTable->setItem(x, 0, pid_item);
                ui->procTable->setItem(x, 1, procname_item);
                ui->procTable->setItem(x, 2, procstate_item);
            }

            emit(updated(true));
            sleep(3);
        }
    }
}

/**
  * Stuff to do when the "About" menu entry is selected
  */
void MainWindow::on_actionAbout_triggered()
{
    new Info(this);
}

/**
  * Stuff to do when the "Documentation" menu entry is selected:
  * Launch at Qt Assistant program, opening our documentation
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
    new SimulatorInit(this);
}

/**
  * This should open the process visualisation dialog
  */
void MainWindow::on_procTable_cellDoubleClicked(int row, int column)
{
    new Visualiser(this, atoi(ui->procTable->item(row, 0)->text().toStdString().c_str()));
}

void MainWindow::on_toggleUpdateButton_clicked()
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
  * Slot corresponding to update() signal, which is called twice during every procTable update;
  * first time with parameter false when it begins updating and then with parameter true when it finishes
  */
void MainWindow::procTable_updated(bool ready)
{
    if(ready)
        ui->procTable->setSortingEnabled(true);
    else
        ui->procTable->setSortingEnabled(false);
}

/**
  * Sets up the help files; Creates directory in the user's home directory, then copies the files
  */
void MainWindow::init_help()
{
    QString dir = QDir::homePath() + "/.taskstalker";
    QDir().mkdir(dir);
    dir += "/help";
    QDir().mkdir(dir);
    QString helpFile = dir + "/help.qhc";
    QFile::copy(":/doc/collection.qhc", dir + "/help.qhc");
    QFile::copy(":/doc/help.qch", dir + "/help.qch");
    QFile::copy(":/doc/index.html", dir + "/index.html");
    QFile::copy(":/doc/main.html", dir + "/main.html");
    QFile::copy(":/doc/visualisation.html", dir + "/visualisation.html");
    QFile::copy(":/doc/info.html", dir + "/info.html");
    QFile::copy(":/doc/mainwindow.png", dir + "/mainwindow.png");
    QFile::copy(":/doc/viswindow.png", dir + "/viswindow.png");
}
