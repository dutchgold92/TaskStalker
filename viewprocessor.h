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

private:
    Ui::ViewProcessor *ui;
    unsigned int cpu;
    pid_t current_pid;
    void update_info();
    QFuture<void> update_thread;
    bool update;
    QGraphicsScene *scene;
    void init_table();
    void init_graph();
    void transform_graph();
};

#endif // VIEWPROCESSOR_H
