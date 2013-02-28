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
#include <QDateTime>

namespace Ui {
    class Visualiser;
}

class Visualiser : public QDialog {
    Q_OBJECT

public:
    Visualiser(QWidget *parent, pid_t pid, bool simulation = false);
    Visualiser(QWidget *parent, QString recording_file_path);
    ~Visualiser();

protected:
    virtual void resizeEvent(QResizeEvent * event);
    void changeEvent(QEvent *e);

private:
    void update_state();
    void scale_diagram();
    void init_record();
    void play_recording();
    Ui::Visualiser *ui;
    pid_t pid;
    QString state;
    bool update;
    QFuture<void> update_thread;
    QGraphicsScene *scene;
    QGraphicsSvgItem *diagram;
    bool simulation;
    bool recording;
    bool playing_recording;
    QString recording_file_path;

signals:
    void missing_process();
    void recording_tick(QString timestamp);

private slots:
    void on_priorityButton_clicked();
    void on_stopButton_clicked();
    void on_endButton_clicked();
    void on_killButton_clicked();
    void on_infoTable_cellChanged(int row, int column);
    void kill_confirm_accepted();
    void process_not_found();
    void on_recordButton_clicked();
    void update_recording_timestamp(QString timestamp);
};

#endif // VISUALISER_H
