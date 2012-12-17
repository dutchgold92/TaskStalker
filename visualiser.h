#ifndef VISUALISER_H
#define VISUALISER_H

#include <QDialog>
#include <QtConcurrentRun>
#include <QFuture>
#include <QFutureWatcher>
#include <string>
#include <sys/types.h>
#include <signal.h>

namespace Ui {
    class Visualiser;
}

class Visualiser : public QDialog {
    Q_OBJECT

public:
    Visualiser(QWidget *parent = 0);
    Visualiser(QWidget *parent, pid_t pid);
    ~Visualiser();

protected:
    void changeEvent(QEvent *e);

private:
    void update_state();
    Ui::Visualiser *ui;
    pid_t pid;
    std::string state;
    bool active;
    QFuture<void> update_thread;
    QImage image;

private slots:
    void on_killButton_clicked();
    void on_infoTable_cellChanged(int row, int column);
    void kill_confirm_accepted();
};

#endif // VISUALISER_H
