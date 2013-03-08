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

class VisualiserUpdater : public QThread {
    Q_OBJECT
public:
    VisualiserUpdater(pid_t pid);
    VisualiserUpdater(QString recording_file_path);
protected:
    virtual void run();
private:
    pid_t pid;
    QString recording_file_path;
    bool recording;
    bool playing_recording;
signals:
    void updated(QStringList update_data);
    void missing_process();
    void recording_finished();
    void recording_tick(QString timestamp, bool finished);
    void read_recording_header(QStringList data);
private slots:
    void set_recording(bool record, QString file_path);
};

class Visualiser : public QDialog {
    Q_OBJECT
public:
    Visualiser(QWidget *parent, pid_t pid, bool simulation = false);
    Visualiser(QWidget *parent, QString recording_file_path);
    ~Visualiser();
private:
    Ui::Visualiser *ui;
    pid_t pid;
    bool simulation;
    bool playing_recording;
    bool recording;
    QString recording_file_path;
    QGraphicsScene *scene;
    QGraphicsSvgItem *diagram;
    VisualiserUpdater *update_thread;
    void init_ui();
    void init_record();
    void scale_diagram();
signals:
    void record(bool record, QString file_path);

private slots:
    void receive_update(QStringList update_data);
    void on_priorityButton_clicked();
    void on_stopButton_clicked();
    void on_endButton_clicked();
    void on_killButton_clicked();
    void on_infoTable_cellChanged(int row, int column);
    void kill_confirm_accepted();
    void process_not_found();
    void on_recordOrPlayAgainButton_clicked();
    void update_recording_timestamp(QString timestamp, bool finished);
    void on_closeButton_clicked();
    void end_recording();
    void init_recording_playback(QStringList data);
};

#endif // VISUALISER_H
