#ifndef SELECTRECORDING_H
#define SELECTRECORDING_H

#include <QDialog>
#include <QDir>
#include "visualiser.h"
#include "errordialog.h"
#include "QFile"

namespace Ui {
class SelectRecording;
}

class SelectRecording : public QDialog
{
    Q_OBJECT
    
public:
    static SelectRecording* get_instance(QWidget *parent = 0);
    ~SelectRecording();
    
private slots:
    void on_cancelButton_clicked();
    void on_playButton_clicked();

private:
    explicit SelectRecording(QWidget *parent = 0);
    Ui::SelectRecording *ui;
    static SelectRecording* instance;
};

#endif // SELECTRECORDING_H
