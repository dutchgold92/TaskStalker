#include "../../../../include/main/cpp/gui/qgraphicsprocessitem.h"

QGraphicsProcessItem::QGraphicsProcessItem(QGraphicsItem *parent, QGraphicsScene *scene, bool active, QTime time_stamp, QString name, pid_t pid) : QGraphicsEllipseItem(parent, scene)
{
    this->active = active;
    this->time_stamp = time_stamp;

    if(active)
    {
        this->name = name;
        this->pid = QString::number(pid);
        this->setBrush(QBrush(Qt::red));
    }
    else
    {
        this->name = "No task";
        this->pid = "-";
        this->setBrush(QBrush(Qt::blue));
    }

    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
}

/**
 * @brief QGraphicsProcessItem::get_time_stamp Returns the process's time stamp. Use this method exclusively.
 * @return
 */
QTime QGraphicsProcessItem::get_time_stamp()
{
    return this->time_stamp;
}

/**
 * @brief QGraphicsProcessItem::get_name Returns the process's command name stamp. Use this method exclusively.
 * @return
 */
QString QGraphicsProcessItem::get_name()
{
    return this->name;
}

/**
 * @brief Returns the process's PID. Use this method exclusively.
 * @return
 */
QString QGraphicsProcessItem::get_pid()
{
    return this->pid;
}
