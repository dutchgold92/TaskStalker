#include "viewprocessor.h"
#include "ui_viewprocessor.h"

using namespace std;

ViewProcessor::ViewProcessor(QWidget *parent, unsigned int cpu) :
    QDialog(parent),
    ui(new Ui::ViewProcessor)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->cpu = cpu;
    this->setWindowTitle("Activity for CPU#" + QString::number(cpu));
    ui->graphTimeScaleLabel->setText(ui->graphTimeScaleLabel->text() + QString::number(sys::get_cpu_update_interval() * GRAPH_TIME_PERIOD_SECONDS) + " seconds:");
    ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
    init_table();
    init_graph();
    this->update = true;
    this->closed = false;
    this->update_thread = QtConcurrent::run(this, &ViewProcessor::update_info);
    connect(this, SIGNAL(data_updated()), this, SLOT(update_data()), Qt::QueuedConnection);
    connect(this->scene, SIGNAL(selectionChanged()), this, SLOT(graph_item_clicked()), Qt::QueuedConnection);
    update_timestamps();
    this->show();
}

ViewProcessor::~ViewProcessor()
{
    update = false;
    closed = true;
    update_thread.waitForFinished();
    delete ui;
}

/**
 * @brief ViewProcessor::init_table Initialises the content of ui->procTable
 */
void ViewProcessor::init_table()
{
    ui->procTable->insertRow(ui->procTable->rowCount());
    ui->procTable->setItem(0, 0, new QTableWidgetItem());
    ui->procTable->setItem(0, 1, new QTableWidgetItem());
    current_pid = proc::get_cpu_task(cpu);

    if(current_pid > 0)
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, current_pid);
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, proc::get_name(current_pid));
    }
    else
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, "None");
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, "-");
    }
}

/**
 * @brief ViewProcessor::init_graph Configures things relating to the graph.
 */
void ViewProcessor::init_graph()
{
    scene = new QGraphicsScene(this);
    ui->graph->setScene(scene);

    QGraphicsSimpleTextItem *active_label = new QGraphicsSimpleTextItem("Active", 0, scene);
    active_label->setPos(-180, -30);
    active_label->setBrush(QBrush(Qt::red));

    QGraphicsSimpleTextItem *inactive_label = new QGraphicsSimpleTextItem("Inactive", 0, scene);
    inactive_label->setPos(-120, -30);
    inactive_label->setBrush(QBrush(Qt::blue));

    process_info = new QGraphicsSimpleTextItem(0, scene);
    process_info->setPos(-40, -30);

    static_graph_items = scene->items().size();
}

/**
 * @brief ViewProcessor::update_info Updates this->current_pid using proc::get_cpu_task(), then emits data_updated() signal. Should be threaded.
 */
void ViewProcessor::update_info()
{
    while(true)
    {
        while(update)
        {
            this->current_pid = proc::get_cpu_task(this->cpu);
            emit(data_updated());
            sleep(sys::get_cpu_update_interval());
        }

        if(closed)
            break;
    }
}

/**
 * @brief ViewProcessor::update_data Slot called when current process data is updated.
 */
void ViewProcessor::update_data()
{
    last_update_time = QTime::currentTime();
    update_timestamps();
    translate_graph();

    QGraphicsProcessItem *item;

    if(this->current_pid > 0)
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, this->current_pid);
        QString proc_name = proc::get_name(current_pid);
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, proc_name);
        item = new QGraphicsProcessItem(0, scene, true, last_update_time, proc_name, current_pid);
        item->setRect(180.0, -75.0, 10.0, 10.0);
    }
    else
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, "None");
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, "-");
        item = new QGraphicsProcessItem(0, scene, false);
        item->setRect(180.0, -55.0, 10.0, 10.0);
    }
}

/**
 * @brief ViewProcessor::on_closeButton_clicked Triggered upon pressing the "Close" button.
 */
void ViewProcessor::on_closeButton_clicked()
{
    this->done(0);
}

/**
 * @brief ViewProcessor::translate_graph Translates all points on the graph, to appear as if it is side-scrolling.
 */
void ViewProcessor::translate_graph()
{
    QList<QGraphicsItem*> item_list = scene->items();

    for(int x = 0; x < (item_list.size() - this->static_graph_items); x++)
    {
        QGraphicsItem *item = item_list[x];
        item->moveBy(-15, 0);

        if(item->x() < GRAPH_MIMIMUM_X_POSITION)
            delete item;
    }
}

/**
 * @brief ViewProcessor::update_timestamps Updates all timestamps.
 */
void ViewProcessor::update_timestamps()
{
    ui->timeLabel->setText(QTime::currentTime().toString());
}

/**
 * @brief ViewProcessor::on_toggleUpdateButton_clicked Functionality of the pause/play button.
 */
void ViewProcessor::on_toggleUpdateButton_clicked()
{
    if(update)
    {
        update = false;
        ui->toggleUpdateButton->setIcon(QIcon(":/img/button_play.png"));
    }
    else
    {
        for(int x = 0; x < (last_update_time.secsTo(QTime::currentTime())); x++)
            translate_graph();

        update = true;
        ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
    }
}

/**
 * @brief ViewProcessor::graph_item_clicked Slot triggered every time a selectable item on the graph is selected/deselected. Prints process info unto graph.
 */
void ViewProcessor::graph_item_clicked()
{
    if(!scene->selectedItems().isEmpty())
    {
        QGraphicsProcessItem *item = (QGraphicsProcessItem *)scene->selectedItems().first();
        process_info->setText(item->get_time_stamp().toString() + " - " + item->get_name() + " (" + item->get_pid() + ")");
    }
    else
        process_info->setText("");
}
