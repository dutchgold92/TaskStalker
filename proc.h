#ifndef PROC_H
#define PROC_H

#include <QString>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <pwd.h>
#include <signal.h>
#include <dirent.h>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRegExp>

#define PATH "/proc/"

namespace proc
{
    struct process
    {
        pid_t pid;
        QString name;
        QString state;
        signed short priority;
        unsigned int uid;
        QString username;
        QString memory_usage;
    };

    static QString kernel_version;
    static unsigned short cpu_count = 0;    // how can a computer have no CPUs? := if 0, clearly it hasn't been successfully calculated, yet.
    static QString cpu_type;
    static float memory_size = 0;   // 0 indicates it must be calculated
    static float swap_size;

    std::vector<process> list_processes();
    QString get_state(pid_t pid);
    QString get_name(pid_t pid);
    signed short get_priority(pid_t pid);
    unsigned int get_uid(pid_t pid);
    QString get_username_from_uid(unsigned int uid);
    QString get_username(pid_t pid);
    QString get_memory_usage(pid_t pid);
    bool set_priority(pid_t pid, signed short value);
    bool stop_process(pid_t pid);
    bool resume_process(pid_t pid);
    bool end_process(pid_t pid);
    bool kill_process(pid_t pid);
    QString get_kernel_version();
    unsigned short get_cpu_count();
    QString get_cpu_type();
    float get_memory_size();
    float get_swap_size();
    unsigned short get_cpu_usage(pid_t pid);
    QString format_state(QString state);
    std::string format_state_std(std::string state);
    std::vector<pid_t> get_tasks_running();
    pid_t get_cpu_task(unsigned int cpu);
    bool task_is_executing(pid_t pid);
}

#endif // PROC_H
