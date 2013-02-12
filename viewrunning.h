#ifndef VIEWRUNNING_H
#define VIEWRUNNING_H

#include "sys.h"
#include "proc.h"
#include <QDialog>
#include <QtConcurrentRun>
#include <QDateTime>

namespace Ui {
    class ViewRunning;
}

class ViewRunning : public QDialog
{
    Q_OBJECT
    
public:
    explicit ViewRunning(QWidget *parent = 0);
    ~ViewRunning();
    
signals:
    void update_data_updated();

private slots:
    void on_toggleUpdateButton_clicked();
    void update_outputTable();
    void on_closeButton_clicked();

private:
    Ui::ViewRunning *ui;
    std::vector<pid_t> update_data;
    QFuture<void> update_thread;
    bool update;
    bool closed;
    void init_table();
    void update_info();
};

#endif // VIEWRUNNING_H
