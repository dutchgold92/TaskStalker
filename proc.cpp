#include "proc.h"

using namespace std;

/**
  * Gathers a list of all PIDs active on the system, along with the respective name/status.
  * Returns a vector of structs representing this information
  *
  * Notes:
  * - Should check the returned vector isn't empty before using it
  *
  * TODO:
  * - sure it's looking grand?
  */
vector<proc::process> proc::list_processes()
{
    process p;
    DIR *rootdir = NULL;
    struct dirent *entry_point;
    vector<proc::process> proc_info;
    rootdir = opendir(PATH);

    ifstream file;
    string line;
    stringstream file_name;

    if(rootdir != NULL)
    {
        while((entry_point = readdir(rootdir)))
        {
            file_name.str("");  // empty the stringstream

            if(strcmp(entry_point->d_name, ".") != 0 && strcmp(entry_point->d_name, "..") != 0 && isdigit(entry_point->d_name[0]))
            {
                file_name << PATH << entry_point->d_name << "/status";
                file.open(file_name.str().c_str());

                if(file.is_open())
                {
                    while(!file.eof())
                    {
                        getline(file, line);

                        if(line.find("Pid:") != -1 && line.find("PPid:") == std::string::npos && line.find("TracerPid:") == std::string::npos)
                        {
                            p.pid = line.erase(0, 5);
                            p.priority = get_priority(atoi(p.pid.c_str()));
                        }
                        else if(line.find("Name:") != -1)
                            p.name = line.erase(0, 6);
                        else if(line.find("State:") != -1)
                            p.state = line.erase(0, 7);
                    }

                    proc_info.push_back(p); // add process to the vector
                    file.close();
                }
                else
                {
                    file.close();
                    perror("Failed to open status file");
                }
            }
        }

        closedir(rootdir);

        return proc_info;
    }
    else
    {
        perror("Couldn't open the directory");
        return proc_info;
    }
}

/**
  * Returns the state of a process, as shown in /proc/[pid]/status.
  * Parameter represents the PID of the process to check.
  *
  * Notes:
  * - Should check the returned string isn't empty before using it
  *
  * TODO: do something more useful if the file doesn't exist?
  */
string proc::get_state(pid_t pid)
{
    ifstream file;
    string line;
    stringstream file_name;
    file_name << PATH << pid << "/status";
    file.open(file_name.str().c_str());

    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, line);

            if(line.find("State:") != -1)
            {
                file.close();
                return (line.erase(0, 7));  // trim the field identifier prefix before returning
            }
        }
    }
    else
    {
        file.close();
        perror("Failed to open status file in proc::get_state()");
        return "";
    }
}

/**
  * Returns the name (eg. starting command) of the process
  * with the PID supplied as parameter
  *
  * Notes:
  * - Should check the returned string isn't null before using it
  *
  * TODO: do something more useful if the file doesn't exist?
  */
string proc::get_name(pid_t pid)
{
    ifstream file;
    string line;
    stringstream file_name;
    file_name << PATH << pid << "/status";
    file.open(file_name.str().c_str());

    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, line);

            if(line.find("Name:") != -1)
            {
                file.close();
                return (line.erase(0, 6));  // trim the field identifier prefix before returning
            }
        }
    }
    else
    {
        file.close();
        perror("Failed to open status file");
        return "";
    }
}

/**
  * Returns the nice value of the process
  */
signed short proc::get_priority(pid_t pid)
{
    return getpriority(PRIO_PROCESS, pid);
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
  * Returns the number of CPUs
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
  * Calculates and returns the CPU usage of the process
  * Doesn't work :(
  */
unsigned short proc::get_cpu_usage(pid_t pid)
{
    unsigned int total_cpu_time = 0;
    unsigned int proc_cpu_time = 0;
    QRegExp numbers("(\\d+)");  // regex for finding numbers in a string
    unsigned int str_pos = 0;   // position variable, for searching strings with regex

    // Calculate total CPU time
    QFile stat_file("/proc/stat");

    if(stat_file.exists())
    {
        stat_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&stat_file);
        QString line = in.readLine();

        // sum the numerical substrings, as integers
        while((str_pos = numbers.indexIn(line, str_pos)) != -1)
        {
            total_cpu_time += numbers.cap(1).toInt();
            str_pos += numbers.matchedLength();
        }

        str_pos = 0;
    }

    stat_file.close();

    // Calculate CPU time for THIS process
    stringstream file_name;
    file_name << PATH << pid << "/stat";
    QFile proc_stat_file(QString::fromStdString(file_name.str()));

    if(proc_stat_file.exists())
    {
        proc_stat_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&proc_stat_file);
        QString line = in.readLine();

        for(unsigned short x = 0; x < 13; x++)  // remove everything up to the utime field
            line.remove(0, (line.indexOf(" ") + 1));

        for(unsigned short x = 0; x < 2 && (str_pos = numbers.indexIn(line, str_pos) != -1); x++)   // add utime and stime field values together, into proc_cpu_time
        {
            proc_cpu_time += numbers.cap(1).toInt();
            str_pos += numbers.matchedLength();
        }
    }
    else
        cout << "Warning: Invalid pid specified to proc::get_cpu_usage(pid_t)" << endl;

    // Derive CPU usage statistic
    return (total_cpu_time / proc_cpu_time);
}

/**
  * Formats the std::string state, returning it in a prettier format as a QString
  * Returns empty QString if passed an unknown state
  */
QString proc::format_state(std::string state)
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
  * Formats the std::string state, returning it in a prettier format
  * Returns empty string if passed an unknown state
  * Probably will only need the QString equivalent, but sure this is here anyway
  */
string proc::format_state_std(std::string state)
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
    else if(state == "W (paging)")
        return "Paging";
    else
        return "";
}

/**
 * Returns information about tasks that have recently entered the literally running state,
 * as defined in /proc/sched_debug.
 */
QString proc::get_tasks_running()
{
    QString info_retrieved = QTime::currentTime().toString();
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
                info_retrieved += "\nCPU ";
                info_retrieved += QString::number(x);
                info_retrieved += ": ";
                line.remove(0, (line.indexOf(":") + 2));
                info_retrieved += line;
                x++;
            }

            line = in.readLine();
        }
    }
    else
        return "File could not be read: " + file.fileName() + "\n";

    file.close();
    return info_retrieved + "\n";
}
