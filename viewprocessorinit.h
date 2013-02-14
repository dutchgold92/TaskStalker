#ifndef VIEWPROCESSORINIT_H
#define VIEWPROCESSORINIT_H

#include "viewprocessor.h"
#include <QDialog>

namespace Ui {
class ViewProcessorInit;
}

class ViewProcessorInit : public QDialog
{
    Q_OBJECT
    
public:
    static ViewProcessorInit* get_instance(QWidget *parent = 0);
    ~ViewProcessorInit();
    
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    ViewProcessorInit(QWidget *parent = 0);
    static ViewProcessorInit* instance;
    Ui::ViewProcessorInit *ui;
};

#endif // VIEWPROCESSORINIT_H
