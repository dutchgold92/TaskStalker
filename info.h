#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
    class Info;
}

class Info : public QDialog {
    Q_OBJECT
public:
    Info(QWidget *parent = 0);
    ~Info();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Info *ui;
    QImage logo;
};

#endif // INFO_H
