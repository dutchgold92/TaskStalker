#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtConcurrentRun>
#include <QProcess>
#include <QDir>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void update_table();
    void init_help();
    bool update;

signals:
    void updated(bool);

private slots:
    void on_toggleUpdateButton_clicked();
    void on_procTable_cellDoubleClicked(int row, int column);
    void on_actionSimulate_triggered();
    void on_actionDocumentation_triggered();
    void on_actionAbout_triggered();
    void on_actionQuit_triggered();
    void procTable_updated(bool);
};

#endif // MAINWINDOW_H
