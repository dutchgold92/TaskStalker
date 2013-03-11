#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "proc.h"
#include "visualiser.h"
#include "info.h"
#include "simulatorinit.h"
#include "sys.h"
#include "settings.h"
#include "viewrunning.h"
#include "systeminfo.h"
#include "viewprocessorinit.h"
#include "selectrecording.h"
#include "qtablewidgetcpuusageitem.h"

#include <QMainWindow>
#include <QtConcurrentRun>
#include <QProcess>
#include <QDir>
#include <QTableWidgetItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void update_table();
    int procTable_find_process(pid_t pid);
    void procTable_remove_dead(std::vector<proc::process> proc_vector);
    bool update;
    int selected_row;

signals:
    void updated(bool);

private slots:
    void on_actionSettings_triggered();
    void on_toggleUpdateButton_clicked();
    void on_procTable_cellDoubleClicked(int row, int column);
    void on_actionSimulate_triggered();
    void on_actionDocumentation_triggered();
    void on_actionAbout_triggered();
    void on_actionQuit_triggered();
    void procTable_updated(bool);
    void procTable_sorted(int column);
    void on_actionView_triggered();
    void on_procTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);
    void on_actionStop_triggered();
    void on_actionResume_triggered();
    void on_actionTerminate_triggered();
    void on_actionKill_triggered();
    void on_actionSystem_Information_triggered();
    void on_actionRunning_Processes_triggered();
    void on_actionProcessor_Activity_triggered();
    void kill_confirmed();
    void on_actionProcess_Recording_triggered();
    void on_actionViewParent_triggered();
};

#endif // MAINWINDOW_H
