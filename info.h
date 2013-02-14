#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
    class Info;
}

class Info : public QDialog {
    Q_OBJECT
public:
    static Info* get_instance(QWidget *parent = 0);
    ~Info();

protected:
    void changeEvent(QEvent *e);

private:
    Info(QWidget *parent = 0);
    static Info* instance;
    Ui::Info *ui;
    QImage logo;
};

#endif // INFO_H
