#ifndef SYS_H
#define SYS_H

#define UPDATE_INTERVAL 3
#define SUB_UPDATE_INTERVAL 1
#define SORT_BY 0

#include <QDir>
#include <QFile>
#include <iostream>
#include <QTextStream>

namespace sys
{
    static unsigned int update_interval = UPDATE_INTERVAL;
    static unsigned int sub_update_interval = SUB_UPDATE_INTERVAL;
    static unsigned int sort_by = SORT_BY;
    void init_help();
    void reset_config();
    void load_config();
    void save_config();
    void set_update_interval(int);
    int get_update_interval();
    void set_sub_update_interval(int);
    int get_sub_update_interval();
    void set_sort_by(int);
    int get_sort_by();
}

#endif // SYS_H
