#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "proc.h"
#include "sys.h"
#include "errordialog.h"
#include <QDialog>
#include <QtConcurrentRun>
#include <QProcess>
#include <iostream>
#include <signal.h>
#include <string>

namespace Ui {
    class Simulator;
}

class Simulator : public QDialog {
    Q_OBJECT
public:
    Simulator(QWidget *parent = 0, QString program = 0);
    ~Simulator();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Simulator *ui;
    void update_state();
    void do_fork();
    void watcher();
    pid_t pid;
    std::string state;
    bool update;
    QFuture<void> update_thread;
    QImage image;
    QString program_path;
    QProcess *process;

signals:
    void missing_process();
    void start_program();

private slots:
    void on_endButton_clicked();
    void on_infoTable_cellChanged(int row, int column);
    void on_priorityButton_clicked();
    void on_stopButton_clicked();
    void on_killButton_clicked();
    void on_closeButton_clicked();
    void process_not_found();
    void program_started();
};

#endif // SIMULATOR_H
