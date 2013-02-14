#ifndef VIEWPROCESSOR_H
#define VIEWPROCESSOR_H

#include "sys.h"
#include "proc.h"
#include "qgraphicsprocessitem.h"
#include <QDialog>
#include <QFuture>
#include <QtConcurrentRun>
#include <QDateTime>

#define GRAPH_TIME_PERIOD_SECONDS 30    // period of time in seconds that can be represented by the graph
#define GRAPH_MIMIMUM_X_POSITION -375   // if an item moves below this x value, it is of bounds of the display area

namespace Ui {
class ViewProcessor;
}

class ViewProcessor : public QDialog
{
    Q_OBJECT
    
public:
    explicit ViewProcessor(QWidget *parent = 0, unsigned int cpu = 0);
    ~ViewProcessor();
    
signals:
    void data_updated();

private slots:
    void update_data();
    void on_closeButton_clicked();
    void on_toggleUpdateButton_clicked();
    void graph_item_clicked();

private:
    Ui::ViewProcessor *ui;
    unsigned int cpu;
    pid_t current_pid;
    void update_info();
    QFuture<void> update_thread;
    bool update;
    bool closed;
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
