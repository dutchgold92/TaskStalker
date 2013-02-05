#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>

namespace Ui {
    class ErrorDialog;
}

class ErrorDialog : public QDialog {
    Q_OBJECT
public:
    enum type {error, warning, notification};
    ErrorDialog(QWidget *parent = 0, bool exit_parent = false, QString error_message = 0, type error_type = error);
    ~ErrorDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ErrorDialog *ui;
    QWidget *parent;
    bool exit_parent;

private slots:
    void on_dismissButton_clicked();
};

#endif // ERRORDIALOG_H
