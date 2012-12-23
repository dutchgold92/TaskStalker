#include "sys.h"

using namespace std;

/**
  * Sets up the help files; Creates directory in the user's home directory, then copies the files
  */
void sys::init_help()
{
    QString dir = QDir::homePath() + "/.taskstalker";
    QDir().mkdir(dir);
    dir += "/help";
    QDir().mkdir(dir);
    QString helpFile = dir + "/help.qhc";
    QFile::copy(":/doc/collection.qhc", dir + "/help.qhc");
    QFile::copy(":/doc/help.qch", dir + "/help.qch");
    QFile::copy(":/doc/index.html", dir + "/index.html");
    QFile::copy(":/doc/main.html", dir + "/main.html");
    QFile::copy(":/doc/visualisation.html", dir + "/visualisation.html");
    QFile::copy(":/doc/info.html", dir + "/info.html");
    QFile::copy(":/doc/mainwindow.png", dir + "/mainwindow.png");
    QFile::copy(":/doc/viswindow.png", dir + "/viswindow.png");
}

/**
  * Resets configuration variables to their default (constant) values, and calls sys::save_config()
  */
void sys::reset_config()
{
    sys::set_update_interval(UPDATE_INTERVAL);
    sys::set_sub_update_interval(SUB_UPDATE_INTERVAL);
    sys::set_sort_by(SORT_BY);
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
            else if(line.startsWith("sort_by"))
                sys::set_sort_by((line.remove(0, (line.indexOf("=") + 2))).toInt());

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
    config_stream << "sort_by = " << sys::get_sort_by() << "\n";
    config_file.close();
}

/**
  * Should always be used to set update_interval to avoid race conditions
  */
void sys::set_update_interval(int value)
{
    sys::update_interval = value;
}

/**
  * Should always be used to get update_interval to avoid race conditions
  */
int sys::get_update_interval()
{
    return sys::update_interval;
}

/**
  * Should always be used to set sub_update_interval to avoid race conditions
  */
void sys::set_sub_update_interval(int value)
{
    sys::sub_update_interval = value;
}

/**
  * Should always be used to get sub_update_interval to avoid race conditions
  */
int sys::get_sub_update_interval()
{
    return sys::sub_update_interval;
}

/**
  * Should always be used to set sort_by to avoid race conditions
  */
void sys::set_sort_by(int value)
{
    sys::sort_by = value;
}

/**
  * Should always be used to get sort_by to avoid race conditions
  */
int sys::get_sort_by()
{
    return sys::sort_by;
}
