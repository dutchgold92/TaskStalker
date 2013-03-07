#include "qtablewidgetcpuusageitem.h"

QTableWidgetCpuUsageItem::QTableWidgetCpuUsageItem() :
    QTableWidgetItem("Calculating...", Qt::DisplayRole)
{

}

/**
 * @brief QTableWidgetCpuUsageItem::set_last_cpu_jiffies Sets last_cpu_jiffies for this item.
 * @param last_cpu_jiffies
 */
void QTableWidgetCpuUsageItem::set_last_cpu_jiffies(unsigned long last_cpu_jiffies)
{
    this->last_cpu_jiffies = last_cpu_jiffies;
}

/**
 * @brief QTableWidgetCpuUsageItem::get_last_cpu_jiffies Returns last_cpu_jiffies for this item.
 * @return
 */
unsigned long QTableWidgetCpuUsageItem::get_last_cpu_jiffies()
{
    return this->last_cpu_jiffies;
}

/**
 * @brief QTableWidgetCpuUsageItem::set_last_proc_jiffies Sets last_proc_jiffies for this item.
 * @param last_proc_jiffies
 */
void QTableWidgetCpuUsageItem::set_last_proc_jiffies(unsigned long last_proc_jiffies)
{
    this->last_proc_jiffies = last_proc_jiffies;
}

/**
 * @brief QTableWidgetCpuUsageItem::get_last_proc_jiffies Returns last_proc_jiffies for this item.
 * @return
 */
unsigned long QTableWidgetCpuUsageItem::get_last_proc_jiffies()
{
    return this->last_proc_jiffies;
}
