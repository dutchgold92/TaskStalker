#ifndef CONFIRMKILL_H
#define CONFIRMKILL_H

#include <QDialog>

namespace Ui {
    class ConfirmKill;
}

class ConfirmKill : public QDialog {
    Q_OBJECT
public:
    ConfirmKill(QWidget *parent = 0);
    ~ConfirmKill();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConfirmKill *ui;
};

#endif // CONFIRMKILL_H
