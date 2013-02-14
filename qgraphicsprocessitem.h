#ifndef QGRAPHICSPROCESSITEM_H
#define QGRAPHICSPROCESSITEM_H

#include <QGraphicsEllipseItem>
#include <QTime>
#include <QBrush>
#include <QGraphicsScene>

class QGraphicsProcessItem : public QGraphicsEllipseItem
{
public:
    QGraphicsProcessItem(QGraphicsItem *parent = 0, QGraphicsScene *scene = 0, bool active = false, QTime time_stamp = QTime::currentTime(), QString name = 0, pid_t pid = 0);
    QTime get_time_stamp();
    QString get_name();
    QString get_pid();

private:
    bool active;
    QTime time_stamp;
    QString name;
    QString pid;
};

#endif // QGRAPHICSPROCESSITEM_H
