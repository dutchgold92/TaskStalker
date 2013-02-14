#ifndef SIMULATORINIT_H
#define SIMULATORINIT_H

#include "visualiser.h"
#include "errordialog.h"
#include <QDialog>
#include <QFile>
#include <QProcess>
#include <QFileDialog>

namespace Ui {
    class SimulatorInit;
}

class SimulatorInit : public QDialog {
    Q_OBJECT
public:
    static SimulatorInit* get_instance(QWidget *parent = 0);
    ~SimulatorInit();

protected:
    void changeEvent(QEvent *e);

private:
    SimulatorInit(QWidget *parent = 0);
    static SimulatorInit* instance;
    Ui::SimulatorInit *ui;
    QProcess *process;
    QFileDialog *browser;

private slots:
    void on_cancelButton_clicked();
    void on_continueButton_clicked();
    void on_browseButton_clicked();
    void file_selected();
};

#endif // SIMULATORINIT_H
