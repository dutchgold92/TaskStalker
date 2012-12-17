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
                            p.pid = line.erase(0, 5);
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
