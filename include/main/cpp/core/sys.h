#ifndef SYS_H
#define SYS_H

#define UPDATE_INTERVAL 2           // 3 seconds
#define SUB_UPDATE_INTERVAL 1       // 1 second
#define RUNNING_UPDATE_INTERVAL 1   // 1 second
#define CPU_UPDATE_INTERVAL 1       // 1 second
#define SORT_BY_COLUMN 3            // 0 = PID, 1 = Name, 2 = Status, 3 = CPU %, 4 = Priority, 5 = User, 6 = Memory
#define SORT_BY_ORDER 1             // 0 = Ascending, 1 = Descending

#include <QDir>
#include <QFile>
#include <iostream>
#include <QTextStream>

namespace sys
{
    static QStringList process_info_fields;
    static unsigned short update_interval = UPDATE_INTERVAL;
    static unsigned short sub_update_interval = SUB_UPDATE_INTERVAL;
    static unsigned short running_update_interval = RUNNING_UPDATE_INTERVAL;
    static unsigned short cpu_update_interval = CPU_UPDATE_INTERVAL;
    static unsigned short sort_by_column = SORT_BY_COLUMN;
    static unsigned short sort_by_order = SORT_BY_ORDER;
    static bool is_recording = false;
    void init();
    void init_help();
    void reset_config();
    void load_config();
    void save_config();
    void add_process_info_field(QString field);
    QStringList get_process_info_fields();
    void set_update_interval(unsigned short);
    unsigned short get_update_interval();
    void set_sub_update_interval(unsigned short);
    unsigned short get_sub_update_interval();
    void set_running_update_interval(unsigned short);
    unsigned short get_running_update_interval();
    void set_cpu_update_interval(unsigned short);
    unsigned short get_cpu_update_interval();
    void set_sort_by_column(unsigned short);
    unsigned short get_sort_by_column();
    void set_sort_by_order(unsigned short);
    unsigned short get_sort_by_order();
    void set_recording(bool recording);
    bool get_is_recording();
}

#endif // SYS_H
