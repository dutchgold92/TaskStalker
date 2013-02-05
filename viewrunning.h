#ifndef VIEWRUNNING_H
#define VIEWRUNNING_H

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
    void update_string_updated();

private slots:
    void on_toggleUpdateButton_clicked();
    void update_outputArea();

    void on_closeButton_clicked();

private:
    Ui::ViewRunning *ui;
    QString update_string;
    QFuture<void> update_thread;
    bool update;
    bool closed;
    void update_info();
};

#endif // VIEWRUNNING_H
