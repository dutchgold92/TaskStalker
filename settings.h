#ifndef SETTINGS_H
#define SETTINGS_H

#include "sys.h"
#include <QDialog>

namespace Ui {
    class Settings;
}

class Settings : public QDialog {
    Q_OBJECT
public:
    static Settings* get_instance(QWidget *parent = 0);
    ~Settings();

protected:
    void changeEvent(QEvent *e);

private:
    Settings(QWidget *parent = 0);
    Ui::Settings *ui;
    static Settings* instance;

private slots:
    void on_resetAllButton_clicked();
    void on_cancelButton_clicked();
    void on_saveButton_clicked();
};

#endif // SETTINGS_H
