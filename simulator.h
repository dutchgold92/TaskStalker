#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QDialog>

namespace Ui {
    class Simulator;
}

class Simulator : public QDialog {
    Q_OBJECT
public:
    Simulator(QWidget *parent = 0);
    ~Simulator();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Simulator *ui;

private slots:
    void on_closeButton_clicked();
};

#endif // SIMULATOR_H
