#ifndef SIMULATORINIT_H
#define SIMULATORINIT_H

#include "simulator.h"
#include <QDialog>
#include <QFile>

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

private slots:
    void on_cancelButton_clicked();
    void on_continueButton_clicked();
    void on_useDefaultButton_clicked();
};

#endif // SIMULATORINIT_H
