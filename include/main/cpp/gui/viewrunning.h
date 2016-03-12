#ifndef VIEWRUNNING_H
#define VIEWRUNNING_H

#include "../core/sys.h"
#include "../core/proc.h"
#include "visualiser.h"
#include <QDialog>
#include <QtConcurrentRun>
#include <QDateTime>
#include <QVector>
#include <QMetaType>

namespace Ui {
    class ViewRunning;
}

Q_DECLARE_METATYPE(QVector<pid_t>)

class ViewRunningUpdater : public QThread {
    Q_OBJECT
public:
    ViewRunningUpdater();
protected:
    virtual void run();
private:
    bool update;
signals:
    void updated(QVector<pid_t> update_data);
private slots:
    void set_paused(bool pause);
};

class ViewRunning : public QDialog
{
    Q_OBJECT    
public:
    static ViewRunning* get_instance(QWidget *parent = 0);
    ~ViewRunning();
    
signals:
    void paused(bool pause);

private slots:
    void on_toggleUpdateButton_clicked();
    void receive_update(QVector<pid_t> update_data);
    void on_closeButton_clicked();

    void on_outputTable_cellDoubleClicked(int row, int column);

private:
    explicit ViewRunning(QWidget *parent = 0);
    static ViewRunning* instance;
    Ui::ViewRunning *ui;
    ViewRunningUpdater *update_thread;
    bool update;
    void init_table();
};

#endif // VIEWRUNNING_H
