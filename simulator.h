#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QDialog>
#include <QtConcurrentRun>
#include <QProcess>
#include <iostream>
#include <signal.h>
#include <string>
#include <sstream>

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
    bool active;
    QFuture<void> update_thread;
    QImage image;
    QString program_path;
    QProcess *process;

private slots:
    void on_infoTable_cellChanged(int row, int column);
    void on_priorityButton_clicked();
    void on_stopButton_clicked();
    void on_killButton_clicked();
    void on_closeButton_clicked();
};

#endif // SIMULATOR_H
