#ifndef PROC_H
#define PROC_H

#include <QString>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <signal.h>
#include <dirent.h>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QDateTime>

#define PATH "/proc/"

namespace proc
{
    struct process
    {
        std::string pid;
        std::string name;
        std::string state;
        signed short priority;
    };

    static unsigned short cpu_count = 0;    // how can a computer have no CPUs? := if 0, clearly it hasn't been successfully calculated, yet.

    std::vector<process> list_processes();
    std::string get_state(pid_t pid);
    std::string get_name(pid_t pid);
    signed short get_priority(pid_t pid);
    bool set_priority(pid_t pid, signed short value);
    bool stop_process(pid_t pid);
    bool resume_process(pid_t pid);
    bool end_process(pid_t pid);
    bool kill_process(pid_t pid);
    unsigned short get_cpu_count();
    unsigned short get_cpu_usage(pid_t pid);
    QString format_state(std::string state);
    std::string format_state_std(std::string state);
    QString get_tasks_running();
}

#endif // PROC_H
