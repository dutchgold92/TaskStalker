#ifndef QTABLEWIDGETCPUUSAGEITEM_H
#define QTABLEWIDGETCPUUSAGEITEM_H

#include <QTableWidgetItem>
#include "../core/proc.h"

class QTableWidgetCpuUsageItem : public QTableWidgetItem
{
public:
    explicit QTableWidgetCpuUsageItem();
    void set_last_cpu_jiffies(unsigned long last_cpu_jiffies);
    unsigned long get_last_cpu_jiffies();
    void set_last_proc_jiffies(unsigned long last_proc_jiffies);
    unsigned long get_last_proc_jiffies();

signals:
    
public slots:

private:
    unsigned long last_cpu_jiffies;
    unsigned long last_proc_jiffies;
};

#endif // QTABLEWIDGETCPUUSAGEITEM_H
