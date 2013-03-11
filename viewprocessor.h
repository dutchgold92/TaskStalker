#ifndef VIEWPROCESSOR_H
#define VIEWPROCESSOR_H

#include "sys.h"
#include "proc.h"
#include "visualiser.h"
#include "qgraphicsprocessitem.h"
#include <QDialog>
#include <QFuture>
#include <QtConcurrentRun>
#include <QDateTime>

#define GRAPH_TIME_PERIOD_SECONDS 30    // period of time in seconds that can be represented by the graph
#define GRAPH_MIMIMUM_X_POSITION -375   // if an item moves below this x value, it is of bounds of the display area

// FIXME: signals/slots between the two classes should use pid_t not QString! but cannot seem to register pid_t.

namespace Ui {
class ViewProcessor;
}

class ViewProcessorUpdater : public QThread {
    Q_OBJECT
public:
    ViewProcessorUpdater(unsigned int cpu = 0);
protected:
    virtual void run();
private:
    unsigned int cpu;
    bool update;
signals:
    void updated(QString pid);
private slots:
    void set_paused(bool);
};

class ViewProcessor : public QDialog
{
    Q_OBJECT    
public:
    explicit ViewProcessor(QWidget *parent = 0, unsigned int cpu = 0);
    ~ViewProcessor();
    
signals:
    void data_updated();
    void paused(bool);

private slots:
    void receive_update(QString pid);
    void on_closeButton_clicked();
    void on_toggleUpdateButton_clicked();
    void graph_item_clicked();

    void on_procTable_cellDoubleClicked(int row, int column);

private:
    Ui::ViewProcessor *ui;
    unsigned int cpu;
    ViewProcessorUpdater *update_thread;
    bool update;
    QGraphicsScene *scene;
    QGraphicsSimpleTextItem *process_info;
    unsigned short static_graph_items;
    void init_table();
    void init_graph();
    void translate_graph();
    void update_timestamps();
    QTime last_update_time;
};

#endif // VIEWPROCESSOR_H
