#ifndef SIMULATORINIT_H
#define SIMULATORINIT_H

#include "visualiser.h"
#include "errordialog.h"
#include <QDialog>
#include <QFile>
#include <QProcess>

namespace Ui {
    class SimulatorInit;
}

class SimulatorInit : public QDialog {
    Q_OBJECT
public:
    SimulatorInit(QWidget *parent = 0);
    ~SimulatorInit();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SimulatorInit *ui;
    QProcess *process;

private slots:
    void on_cancelButton_clicked();
    void on_continueButton_clicked();
};

#endif // SIMULATORINIT_H
