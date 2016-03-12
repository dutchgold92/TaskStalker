#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include "../core/proc.h"
#include <QDialog>

namespace Ui {
class SystemInfo;
}

class SystemInfo : public QDialog
{
    Q_OBJECT
    
public:
    static SystemInfo* get_instance(QWidget *parent = 0);
    ~SystemInfo();
    
private:
    explicit SystemInfo(QWidget *parent = 0);
    static SystemInfo* instance;
    Ui::SystemInfo *ui;
};

#endif // SYSTEMINFO_H
