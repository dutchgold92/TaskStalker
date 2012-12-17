#ifndef PROC_H
#define PROC_H

#include <QString>
#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <vector>

#define PATH "/proc/"

namespace proc
{
    struct process
    {
        std::string pid;
        std::string name;
        std::string state;
    };

    std::vector<process> list_processes();
    std::string get_state(pid_t pid);
    std::string get_name(pid_t pid);
    QString format_state(std::string state);
    std::string format_state_std(std::string state);
}

#endif // PROC_H
