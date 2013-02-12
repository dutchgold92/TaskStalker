#ifndef VIEWPROCESSOR_H
#define VIEWPROCESSOR_H

#include "sys.h"
#include "proc.h"
#include <QDialog>
#include <QFuture>
#include <QtConcurrentRun>
#include <QDateTime>
#include <QGraphicsEllipseItem>

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

private:
    Ui::ViewProcessor *ui;
    unsigned int cpu;
    pid_t current_pid;
    void update_info();
    QFuture<void> update_thread;
    bool update;
    bool closed;
    QGraphicsScene *scene;
    QGraphicsLineItem *marker_one;
    QGraphicsLineItem *marker_two;
    QGraphicsLineItem *marker_three;
    QGraphicsSimpleTextItem *marker_one_text;
    QGraphicsSimpleTextItem *marker_two_text;
    QGraphicsSimpleTextItem *marker_three_text;
    QGraphicsSimpleTextItem *marker_four_text;
    static const signed short marker_one_offset = -25;
    static const signed short marker_two_offset = -19;
    static const signed short marker_three_offset = -12;
    static const signed short marker_four_offset = -5;
    unsigned short static_graph_items;
    void init_table();
    void init_graph();
    void translate_graph();
    void update_timestamps();
    QTime last_update_time;
};

#endif // VIEWPROCESSOR_H
