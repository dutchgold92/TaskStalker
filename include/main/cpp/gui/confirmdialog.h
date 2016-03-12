#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConfirmDialog(QWidget *parent = 0, const char *slot = 0, QString message = 0);
    ~ConfirmDialog();
    
private slots:
    void on_continueButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::ConfirmDialog *ui;
};

#endif // CONFIRMDIALOG_H
