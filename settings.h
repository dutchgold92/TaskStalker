#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
    class Settings;
}

class Settings : public QDialog {
    Q_OBJECT
public:
    Settings(QWidget *parent = 0);
    ~Settings();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Settings *ui;

private slots:
    void on_resetAllButton_clicked();
    void on_cancelButton_clicked();
    void on_saveButton_clicked();
};

#endif // SETTINGS_H
