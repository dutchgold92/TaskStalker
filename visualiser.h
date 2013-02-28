#ifndef VISUALISER_H
#define VISUALISER_H

#include "proc.h"
#include "confirmdialog.h"
#include "sys.h"
#include "errordialog.h"
#include <QDialog>
#include <QtConcurrentRun>
#include <QFuture>
#include <QFutureWatcher>
#include <string>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QFile>

namespace Ui {
    class Visualiser;
}

class Visualiser : public QDialog {
    Q_OBJECT

public:
    Visualiser(QWidget *parent, pid_t pid, bool simulation = false);
    ~Visualiser();

protected:
    virtual void resizeEvent(QResizeEvent * event);
    void changeEvent(QEvent *e);

private:
    void update_state();
    void scale_diagram();
    Ui::Visualiser *ui;
    pid_t pid;
    QString state;
    bool update;
    QFuture<void> update_thread;
    QGraphicsScene *scene;
    QGraphicsSvgItem *diagram;
    bool simulation;

signals:
    void missing_process();

private slots:
    void on_priorityButton_clicked();
    void on_stopButton_clicked();
    void on_endButton_clicked();
    void on_killButton_clicked();
    void on_infoTable_cellChanged(int row, int column);
    void kill_confirm_accepted();
    void process_not_found();
};

#endif // VISUALISER_H
