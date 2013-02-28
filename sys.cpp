#include "sys.h"

using namespace std;

/**
  * Calls various other functions to initialise the program
  */
void sys::init()
{
    QDir().mkdir(QDir::homePath() + "/.taskstalker");
    QDir().mkdir(QDir::homePath() + "/.taskstalker/recordings");
    sys::init_help();
    sys::load_config();
}

/**
  * Sets up the help files; Creates directory in the user's home directory, then copies the files
  */
void sys::init_help()
{
    QString dir = QDir::homePath() + "/.taskstalker";
    dir += "/help";
    QDir().mkdir(dir);
    QString helpFile = dir + "/help.qhc";
    QFile::copy(":/doc/collection.qhc", dir + "/help.qhc");
    QFile::copy(":/doc/help.qch", dir + "/help.qch");
    QFile::copy(":/doc/index.html", dir + "/index.html");
    QFile::copy(":/doc/main.html", dir + "/main.html");
    QFile::copy(":/doc/visualisation.html", dir + "/visualisation.html");
    QFile::copy(":/doc/simulator.html", dir + "/simulator.html");
    QFile::copy(":/doc/info.html", dir + "/info.html");
    QFile::copy(":/doc/settings.html", dir + "/settings.html");
    QFile::copy(":/doc/mainwindow.png", dir + "/mainwindow.png");
    QFile::copy(":/doc/viswindow.png", dir + "/viswindow.png");
    QFile::copy(":/doc/simulator.png", dir + "/simulator.png");
    QFile::copy(":/doc/settings.png", dir + "/settings.png");
}

/**
  * Resets configuration variables to their default (constant) values, and calls sys::save_config()
  */
void sys::reset_config()
{
    sys::set_update_interval(UPDATE_INTERVAL);
    sys::set_sub_update_interval(SUB_UPDATE_INTERVAL);
    sys::set_running_update_interval(RUNNING_UPDATE_INTERVAL);
    sys::set_cpu_update_interval(CPU_UPDATE_INTERVAL);
    sys::set_sort_by_column(SORT_BY_COLUMN);
    sys::set_sort_by_order(SORT_BY_ORDER);
    sys::save_config();
}

/**
  * Reads from the configuration file and sets program variables accordingly
  */
void sys::load_config()
{
    QString config_path = QDir::homePath() + "/.taskstalker/config";
    QFile config_file(config_path);

    if(config_file.exists())
    {
        config_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&config_file);
        QString line = in.readLine();

        while(!line.isNull())
        {
            if(line.startsWith("update_interval"))
                sys::set_update_interval((line.remove(0, (line.indexOf("=") + 2))).toInt());
            else if(line.startsWith("sub_update_interval"))
                sys::set_sub_update_interval((line.remove(0, (line.indexOf("=") + 2))).toInt());
            else if(line.startsWith("running_update_interval"))
                sys::set_running_update_interval((line.remove(0, (line.indexOf("=") + 2))).toInt());
            else if(line.startsWith("cpu_update_interval"))
                sys::set_cpu_update_interval((line.remove(0, (line.indexOf("=") + 2))).toInt());
            else if(line.startsWith("sort_by_column"))
                sys::set_sort_by_column((line.remove(0, (line.indexOf("=") + 2))).toInt());
            else if(line.startsWith("sort_by_order"))
                sys::set_sort_by_order((line.remove(0, (line.indexOf("=") + 2))).toInt());

            line = in.readLine();
        }

        config_file.close();
    }
    else
        cout << "Warning: No configuration file could be found" << endl;
}

/**
  * Writes the config file to the user's home directory, in ~/.taskstalker/config
  */
void sys::save_config()
{
    QString config_path = QDir::homePath() + "/.taskstalker/config";
    QFile config_file(config_path);
    config_file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream config_stream(&config_file);
    config_stream << "update_interval = " << sys::get_update_interval() << "\n";
    config_stream << "sub_update_interval = " << sys::get_sub_update_interval() << "\n";
    config_stream << "running_update_interval = " << sys::get_running_update_interval() << "\n";
    config_stream << "cpu_update_interval = " << sys::get_cpu_update_interval() << "\n";
    config_stream << "sort_by_column = " << sys::get_sort_by_column() << "\n";
    config_stream << "sort_by_order = " << sys::get_sort_by_order() << "\n";
    config_file.close();
}

/**
 * @brief sys::set_process_info_fields Sets the list of process information fields
 * @param fields
 */
void sys::add_process_info_field(QString field)
{
    sys::process_info_fields.append(field);
}

/**
 * @brief sys::get_process_info_fields Returns the list of the process information fields
 * @return
 */
QStringList sys::get_process_info_fields()
{
    return sys::process_info_fields;
}

/**
  * Should always be used to set update_interval to avoid race conditions
  */
void sys::set_update_interval(unsigned short value)
{
    sys::update_interval = value;
}

/**
  * Should always be used to get update_interval to avoid race conditions
  */
unsigned short sys::get_update_interval()
{
    return sys::update_interval;
}

/**
  * Should always be used to set sub_update_interval to avoid race conditions
  */
void sys::set_sub_update_interval(unsigned short value)
{
    sys::sub_update_interval = value;
}

/**
  * Should always be used to get sub_update_interval to avoid race conditions
  */
unsigned short sys::get_sub_update_interval()
{
    return sys::sub_update_interval;
}

/**
  * Should always be used to set running_update_interval to avoid race conditions
  */
void sys::set_running_update_interval(unsigned short value)
{
    sys::running_update_interval = value;
}

/**
  * Should always be used to get running_update_interval to avoid race conditions
  */
unsigned short sys::get_running_update_interval()
{
    return sys::running_update_interval;
}

/**
  * Should always be used to set cpu_update_interval to avoid race conditions
  */
void sys::set_cpu_update_interval(unsigned short value)
{
    sys::cpu_update_interval = value;
}

/**
  * Should always be used to get cpu_update_interval to avoid race conditions
  */
unsigned short sys::get_cpu_update_interval()
{
    return sys::cpu_update_interval;
}

/**
  * Should always be used to set sort_by to avoid race conditions
  */
void sys::set_sort_by_column(unsigned short value)
{
    sys::sort_by_column = value;
}

/**
  * Should always be used to get sort_by to avoid race conditions
  */
unsigned short sys::get_sort_by_column()
{
    return sys::sort_by_column;
}

/**
  * Should always be used to set sort_by_order to avoid race conditions
  */
void sys::set_sort_by_order(unsigned short value)
{
    sys::sort_by_order = value;
}

/**
  * Should always be used to get sort_by_order to avoid race conditions
  */
unsigned short sys::get_sort_by_order()
{
    return sys::sort_by_order;
}
