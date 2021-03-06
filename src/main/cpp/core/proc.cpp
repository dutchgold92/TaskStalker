#include "../../../../include/main/cpp/core/proc.h"

#include <iostream>

using namespace std;

/**
  * Gathers a list of all PIDs active on the system, along with the respective name/status.
  * Returns a vector of structs representing this information
  */
vector<proc::process> proc::list_processes()
{
    vector<proc::process> proc_vector;
    process p;
    QDir root_dir = QDir(PATH);
    QStringList entries = root_dir.entryList(QDir::AllDirs, QDir::Unsorted);

    for(int x = 0; x < entries.length(); x++)
    {
        if(entries.at(x).toInt())
        {
            QFile status_file(PATH + entries.at(x) + "/status");
            status_file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&status_file);
            QString line = in.readLine();

            bool memory_entry = false;

            while(!line.isNull())
            {
                if(line.startsWith("Name:"))
                    p.name = line.remove(0, (line.indexOf(":") + 1)).trimmed();
                else if(line.startsWith("State:"))
                    p.state = line.remove(0, (line.indexOf(":") + 1)).trimmed();
                else if(line.startsWith("Pid:") && !line.startsWith("PPid:") && !line.startsWith("TracerPid:"))
                {
                    p.pid = line.remove(0, (line.indexOf(":") + 1)).trimmed().toInt();
                    p.priority = proc::get_priority(p.pid);
                }
                else if(line.startsWith("PPid:"))
                {
                    p.ppid = line.remove(0, (line.indexOf(":") + 1)).trimmed();

                    if(p.ppid == "0")
                        p.ppid = "N/A";
                }
                else if(line.startsWith("Uid:"))
                {
                    line = line.remove(0, (line.indexOf(":") + 1)).trimmed();
                    line = line.remove(line.indexOf(QRegExp("\\s")), line.length());
                    p.uid = line.toInt();
                    p.username = proc::get_username_from_uid(p.uid);
                }
                else if(line.startsWith("VmSize:"))
                {
                    p.memory_usage = line.remove(0, (line.indexOf(":") + 1)).trimmed();
                    memory_entry = true;
                }
                else if(line.startsWith("Threads:"))
                    p.threads = line.remove(0, (line.indexOf(":") + 1)).trimmed().toShort();

                line = in.readLine();
            }

            status_file.close();

            if(!memory_entry)
                p.memory_usage = "N/A";

            proc_vector.push_back(p);
        }
    }

    return proc_vector;
}

/**
  * Returns the state of a process, as shown in /proc/[pid]/status.
  * Parameter represents the PID of the process to check.
  */
QString proc::get_state(pid_t pid)
{
    QFile status_file(PATH + QString::number(pid) + "/status");
    status_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&status_file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        if(line.startsWith("State:"))
            return line.remove(0, (line.indexOf(":") + 1)).trimmed();

        line = in.readLine();
    }

    return "";
}

/**
  * Returns the name (eg. starting command) of the process
  * with the PID supplied as parameter
  */
QString proc::get_name(pid_t pid)
{
    QFile status_file(PATH + QString::number(pid) + "/status");
    status_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&status_file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        if(line.startsWith("Name:"))
            return line.remove(0, (line.indexOf(":") + 1)).trimmed();

        line = in.readLine();
    }

    return "";
}

/**
 * @brief proc::get_parent_pid Returns the task's parent's PID (if any).
 * @param pid
 * @return
 */
QString proc::get_parent_pid(pid_t pid)
{
    QFile status_file(PATH + QString::number(pid) + "/status");
    status_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&status_file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        if(line.startsWith("PPid:"))
        {
            line = line.remove(0, (line.indexOf(":") + 1)).trimmed();

            if(line != "0")
                return line;
            else
                return "N/A";
        }

        line = in.readLine();
    }

    return "N/A";
}

/**
 * @brief proc::get_thread_count Returns the number of threads of the process.
 * @param pid
 * @return
 */
unsigned short proc::get_thread_count(pid_t pid)
{
    QFile status_file(PATH + QString::number(pid) + "/status");
    status_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&status_file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        if(line.startsWith("Threads:"))
            return line.remove(0, (line.indexOf(":") + 1)).trimmed().toInt();

        line = in.readLine();
    }

    return 0;
}

/**
  * Returns the nice value of the process
  */
signed short proc::get_priority(pid_t pid)
{
    return getpriority(PRIO_PROCESS, pid);
}

/**
 * @brief proc::get_uid Returns the User ID of the owner of the specified task.
 * @param pid
 * @return
 */
unsigned int proc::get_uid(pid_t pid)
{
    QFile status_file(PATH + QString::number(pid) + "/status");
    status_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&status_file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        if(line.startsWith("Uid:"))
        {
            line = line.remove(0, (line.indexOf(":") + 1)).trimmed();
            line = line.remove(line.indexOf(QRegExp("\\s")), line.length());
            return line.toInt();
        }

        line = in.readLine();
    }
}

/**
 * @brief proc::get_username_from_uid Returns the username corresponding to the supplied UID.
 * @param uid
 * @return
 */
QString proc::get_username_from_uid(unsigned int uid)
{
    return getpwuid(uid)->pw_name;
}

QString proc::get_username(pid_t pid)
{
    return proc::get_username_from_uid(proc::get_uid(pid));
}

/**
 * @brief proc::get_memory_usage Returns the quantity of memory allocated to the specified task.
 * @param pid
 * @return
 */
QString proc::get_memory_usage(pid_t pid)
{
    QString file_path = "/proc/" + QString::number(pid) + "/status";
    QFile file(file_path);

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line = in.readLine();

        while(!line.isNull())
        {
            if(line.contains("VmSize"))
                return line.remove(0, (line.indexOf(":") + 1)).trimmed();

            line = in.readLine();
        }
    }

    file.close();
    return "N/A";
}

/**
  * Wrapper method to call setpriority() as we wish to do so
  */
bool proc::set_priority(pid_t pid, signed short value)
{
    return(setpriority(PRIO_PROCESS, pid, value) == 0);
}

/**
 * @brief proc::stop_process Wrapper method to kill(pid, SIGSTOP)
 * @param pid
 * @return True if success; false if failure
 */
bool proc::stop_process(pid_t pid)
{
    return(kill(pid, 19) == 0);
}

/**
 * @brief proc::resume_process Wrapper method to kill(pid, SIGCONT)
 * @param pid
 * @return True if success; false if failure
 */
bool proc::resume_process(pid_t pid)
{
    return(kill(pid, 18) == 0);
}

/**
 * @brief proc::end_process Wrapper method to kill(pid, SIGTERM)
 * @param pid
 * @return True if success; false if failure
 */
bool proc::end_process(pid_t pid)
{
    return(kill(pid, 15) == 0);
}

/**
 * @brief proc::kill_process Wrapper method to kill(pid, SIGKILL)
 * @param pid
 * @return True if success; false if failure
 */
bool proc::kill_process(pid_t pid)
{
    return(kill(pid, 9) == 0);
}

/**
 * @brief proc::get_kernel_version Determines the kernel version, read from /proc/version
 * @return QString of the kernel version string
 */
QString proc::get_kernel_version()
{
    if(proc::kernel_version.isEmpty())
    {
        QFile file("/proc/version");

        if(file.exists())
        {
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString line = in.readLine();

            if(!line.isEmpty())
                proc::kernel_version = line;
        }

        file.close();
    }

    return proc::kernel_version;
}

/**
  * Returns the number of CPUs, as read from /proc/cpuinfo
  */
unsigned short proc::get_cpu_count()
{
    if(proc::cpu_count == 0)    // CPU count hasn't been determined yet; calculate it!
    {
        ifstream file;
        string line;
        file.open("/proc/cpuinfo");

        if(file.is_open())
        {
            while(!file.eof())
            {
                getline(file, line);

                if(line.find("processor") != -1)    // look for fields implying the existence of a unique CPU
                    proc::cpu_count++;
            }

            file.close();
        }
        else
            file.close();
    }

    return proc::cpu_count;
}

/**
 * @brief proc::get_cpu_type Determines the CPU model from /proc/cpuinfo
 * @return CPU type string
 */
QString proc::get_cpu_type()
{
    if(proc::cpu_type.isEmpty())
    {
        QFile file("/proc/cpuinfo");

        if(file.exists())
        {
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString line = in.readLine();

            while(!line.isEmpty())
            {
                if(line.startsWith("model name"))
                {
                    proc::cpu_type = line.remove(0, (line.indexOf(":") + 2));
                    break;
                }

                line = in.readLine();
            }
        }

        file.close();
    }

    return proc::cpu_type;
}

/**
 * @brief proc::get_memory_size Determines the total memory size from /proc/meminfo
 * @return Memory size as float, in GB
 */
float proc::get_memory_size()
{
    if(proc::memory_size == 0)
    {
        QFile file("/proc/meminfo");

        if(file.exists())
        {
            QRegExp numbers("(\\d+)");  // regex for finding numbers in a string
            unsigned int str_pos = 0;   // position variable, for searching strings with regex

            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString line = in.readLine();

            while(!line.isEmpty())
            {
                if(line.startsWith("MemTotal"))
                {
                    while((str_pos = numbers.indexIn(line, str_pos)) != -1)
                    {
                        proc::memory_size = (numbers.cap(1).toFloat() / (1024 * 1024));
                        str_pos += numbers.matchedLength();
                    }

                    break;
                }

                line = in.readLine();
            }
        }

        file.close();
    }

    return proc::memory_size;
}

/**
 * @brief proc::get_swap_size Determines the total swap size from /proc/meminfo
 * @return Swap size as float, in GB
 */
float proc::get_swap_size()
{
    QFile file("/proc/meminfo");

    if(file.exists())
    {
        QRegExp numbers("(\\d+)");  // regex for finding numbers in a string
        unsigned int str_pos = 0;   // position variable, for searching strings with regex

        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line = in.readLine();

        while(!line.isEmpty())
        {
            if(line.startsWith("SwapTotal"))
            {
                while((str_pos = numbers.indexIn(line, str_pos)) != -1)
                {
                    proc::swap_size = (numbers.cap(1).toFloat() / (1024 * 1024));
                    str_pos += numbers.matchedLength();
                }

                break;
            }

            line = in.readLine();
        }
    }

    file.close();

    return proc::swap_size;
}

/**
 * @brief proc::get_cpu_usage Calculates and returns CPU Usage for the specified process. NOTE: Be sure to call proc::reset_usage_vars() when finished with a process!
 * @param pid Task to check.
 * @return Returns CPU usage percentage for the given process. This value cannot be calculated on the initial call of this function, in which case -1 is returned.
 */
signed int proc::get_cpu_usage(pid_t pid)
{
    unsigned long last_total_cpu_time = proc::last_cpu_jiffies;
    unsigned long last_proc_cpu_time = proc::last_proc_jiffies;
    unsigned long total_cpu_time = 0;
    unsigned long proc_cpu_time = 0;

    // Calculate total CPU time
    QFile stat_file("/proc/stat");

    if(stat_file.exists())
    {
        stat_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&stat_file);
        QString line = in.readLine();

        if(line.startsWith("cpu "))
        {
            line = line.remove(0, line.indexOf(" ")).trimmed();

            for(short x = 0; x < 10; x++)
            {
                total_cpu_time += line.left(line.indexOf(" ")).toLong();
                line = line.remove(0, line.indexOf(" ")).trimmed();
            }
        }

        stat_file.close();
    }
    else
        cout << "Failed to open /proc/stat";

    // Calculate CPU time for THIS process
    QFile proc_stat_file(PATH + QString::number(pid) + "/stat");

    if(proc_stat_file.exists())
    {
        proc_stat_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&proc_stat_file);
        QString line = in.readLine();

        for(short x = 0; x < 14; x++)
        {
            if(x >= 13)
                proc_cpu_time += line.left(line.indexOf(" ")).toLong();

            line = line.remove(0, line.indexOf(" ")).trimmed();
        }

        proc_stat_file.close();
    }
    else
        cout << "Failed to open /proc/" << pid << "/stat";

    if(proc::last_cpu_jiffies == 0)
    {
        proc::last_cpu_jiffies = total_cpu_time;
        proc::last_proc_jiffies = proc_cpu_time;
        return -1;
    }
    else
    {
        proc::last_cpu_jiffies = total_cpu_time;
        proc::last_proc_jiffies = proc_cpu_time;
        return (100 * (proc_cpu_time - last_proc_cpu_time) / (total_cpu_time - last_total_cpu_time));
    }
}

/**
 * @brief proc::get_cpu_usage_independent Calculates and returns CPU Usage for the specified process. This version does not use shared variables, hence can be used multiple times simultaneously.
 * @param pid Task to check.
 * @param last_cpu_jiffies The system total jiffy count at last update.
 * @param last_proc_jiffies The task's jiffy count at last update.
 * @return CPU usage percentage for the given process, as well as jiffy counts. This value cannot be calculated on the initial call of this function, in which case -1 is returned.
 */
proc::cpu_usage proc::get_cpu_usage_independent(pid_t pid, unsigned long last_cpu_jiffies, unsigned long last_proc_jiffies)
{
    cpu_usage usage;
    unsigned long last_total_cpu_time = last_cpu_jiffies;
    unsigned long last_proc_cpu_time = last_proc_jiffies;
    unsigned long total_cpu_time = 0;
    unsigned long proc_cpu_time = 0;

    // Calculate total CPU time
    QFile stat_file("/proc/stat");

    if(stat_file.exists())
    {
        stat_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&stat_file);
        QString line = in.readLine();

        if(line.startsWith("cpu "))
        {
            line = line.remove(0, line.indexOf(" ")).trimmed();

            for(short x = 0; x < 10; x++)
            {
                total_cpu_time += line.left(line.indexOf(" ")).toLong();
                line = line.remove(0, line.indexOf(" ")).trimmed();
            }
        }

        stat_file.close();
    }
    else
        cout << "Failed to open /proc/stat";

    // Calculate CPU time for THIS process
    QFile proc_stat_file(PATH + QString::number(pid) + "/stat");

    if(proc_stat_file.exists())
    {
        proc_stat_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&proc_stat_file);
        QString line = in.readLine();

        for(short x = 0; x < 14; x++)
        {
            if(x >= 13)
                proc_cpu_time += line.left(line.indexOf(" ")).toLong();

            line = line.remove(0, line.indexOf(" ")).trimmed();
        }

        proc_stat_file.close();
    }
    else
        cout << "Failed to open /proc/" << pid << "/stat";

    usage.last_cpu_jiffies = total_cpu_time;
    usage.last_proc_jiffies = proc_cpu_time;

    if(last_cpu_jiffies == 0)
    {
        usage.usage = -1;
        return usage;
    }
    else
    {
        usage.usage = (100 * (proc_cpu_time - last_proc_cpu_time) / (total_cpu_time - last_total_cpu_time));
        return usage;
    }
}

/**
 * @brief proc::reset_usage_vars Resets resource usage variables.
 */
void proc::reset_usage_vars()
{
    proc::last_cpu_jiffies = 0;
    proc::last_proc_jiffies = 0;
}

/**
  * Formats the std::string state, returning it in a prettier format as a QString
  * Returns empty QString if passed an unknown state
  */
QString proc::format_state(QString state)
{
    if(state == "R (running)")
        return "Running";
    else if(state == "S (sleeping)")
        return "Sleeping";
    else if(state == "Z (zombie)")
        return "Zombie";
    else if(state == "D (disk sleep")
        return "Disk Sleep";
    else if(state == "T (stopped)")
        return "Stopped";
    else if(state == "W (paging")
        return "Paging";
    else
        return "";
}

/**
 * Returns information about tasks that have recently entered the literally running state,
 * as defined in /proc/sched_debug.
 */
QVector<pid_t> proc::get_tasks_running()
{
    QVector<pid_t> running_tasks;
    QFile file("/proc/sched_debug");

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line = in.readLine();

        for(short x = 0; x < proc::get_cpu_count(); )
        {
            if(line.contains(".curr->pid"))
            {
                line.remove(0, (line.indexOf(":") + 2));
                running_tasks.push_back(line.toInt());
                x++;
            }

            line = in.readLine();
        }
    }
    else
        running_tasks.push_back(-1);

    file.close();
    return running_tasks;
}

/**
 * @brief proc::get_cpu_task Returns the task currently executing on the selected CPU, or 0 if there is none.
 * @param cpu CPU to check
 * @return current PID
 */
pid_t proc::get_cpu_task(unsigned int cpu)
{
    QFile file("/proc/sched_debug");

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line = in.readLine();

        for(short x = 0; x <= cpu; )
        {
            if(line.contains(".curr->pid"))
            {
                if(x == cpu)
                    return(line.remove(0, (line.indexOf(":") + 2)).toInt());

                x++;
            }

            line = in.readLine();
        }
    }

    file.close();
    return 0;
}

/**
 * @brief proc::get_cpu_task Returns the ID of the CPU on which the task is executing, or -1 if it simply isn't.
 * @param cpu Task to check
 * @return
 */
signed short proc::task_is_executing(pid_t pid)
{
    QFile file("/proc/sched_debug");

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line = in.readLine();
        unsigned short cpu;

        while(!line.isNull())
        {
            if(line.startsWith("cpu#"))
                cpu++;

            if(line.contains(".curr->pid"))
                if(line.remove(0, (line.indexOf(":") + 2)).toInt() == pid)
                {
                    file.close();
                    return (cpu - 1);
                }

            line = in.readLine();
        }
    }

    file.close();
    return -1;
}
