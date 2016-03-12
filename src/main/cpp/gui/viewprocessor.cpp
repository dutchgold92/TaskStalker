#include "../../../../include/main/cpp/gui/viewprocessor.h"
#include "ui_viewprocessor.h"

using namespace std;

/**
 * @brief ViewProcessor::ViewProcessor Creates a new instance of this dialog/class.
 * @param parent Parent widget.
 * @param cpu CPU to monitor, by ID.
 */
ViewProcessor::ViewProcessor(QWidget *parent, unsigned int cpu) :
    QDialog(parent),
    ui(new Ui::ViewProcessor)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->cpu = cpu;
    this->setWindowTitle("Activity for CPU#" + QString::number(cpu));
    ui->graphTimeScaleLabel->setText(ui->graphTimeScaleLabel->text() + QString::number(sys::get_cpu_update_interval() * GRAPH_TIME_PERIOD_SECONDS) + " seconds:");
    ui->toggleUpdateButton->setIcon(QIcon(":/resources/img/button_pause.png"));
    init_table();
    init_graph();
    this->update = true;
    update_thread = new ViewProcessorUpdater(cpu);
    update_thread->start();
    connect(update_thread, SIGNAL(updated(QString)), this, SLOT(receive_update(QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(paused(bool)), update_thread, SLOT(set_paused(bool)), Qt::QueuedConnection);
    connect(this->scene, SIGNAL(selectionChanged()), this, SLOT(graph_item_clicked()), Qt::QueuedConnection);
    update_timestamps();
    this->show();
}

/**
 * @brief ViewProcessor::~ViewProcessor Destroys the class and dialog, and terminates the updater thread.
 */
ViewProcessor::~ViewProcessor()
{
    update = false;
    update_thread->terminate();
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
    int current_pid = proc::get_cpu_task(cpu);

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
 * @brief ViewProcessor::receive_update Updates the GUI with new information from the worker thread.
 * @param pid PID of currently executing task.
 */
void ViewProcessor::receive_update(QString pid)
{
    last_update_time = QTime::currentTime();
    update_timestamps();
    translate_graph();

    QGraphicsProcessItem *item;

    if(pid.toInt() > 0)
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, pid);
        QString proc_name = proc::get_name(pid.toInt());
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, proc_name);
        item = new QGraphicsProcessItem(0, scene, true, last_update_time, proc_name, pid.toInt());
        item->setRect(180.0, -75.0, 10.0, 10.0);
    }
    else
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, "None");
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, "-");
        item = new QGraphicsProcessItem(0, scene, false, last_update_time, 0, 0);
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
        ui->toggleUpdateButton->setIcon(QIcon(":/resources/img/button_play.png"));
        emit(paused(true));
    }
    else
    {
        for(int x = 0; x < (last_update_time.secsTo(QTime::currentTime())); x++)
            translate_graph();

        update = true;
        ui->toggleUpdateButton->setIcon(QIcon(":/resources/img/button_pause.png"));
        emit(paused(false));
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

/**
 * @brief ViewProcessorUpdater::ViewProcessorUpdater Constructor for ViewProcessor's worker thread class.
 * @param cpu CPU to probe for information.
 */
ViewProcessorUpdater::ViewProcessorUpdater(unsigned int cpu)
{
    this->cpu = cpu;
    this->update = true;
}

/**
 * @brief ViewProcessorUpdater::run Updater function.
 */
void ViewProcessorUpdater::run()
{
    while(true)
    {
        while(update)
        {
            this->setTerminationEnabled(false);
            emit(updated(QString::number(proc::get_cpu_task(this->cpu))));
            this->setTerminationEnabled(true);
            sleep(sys::get_cpu_update_interval());
        }
    }
}

/**
 * @brief ViewProcessorUpdater::set_paused Pauses/Resumes updating.
 * @param pause Pause if true, resume if false.
 */
void ViewProcessorUpdater::set_paused(bool pause)
{
    if(pause)
        update = false;
    else
        update = true;
}

/**
 * @brief ViewProcessor::on_procTable_cellDoubleClicked Opens a process viewer to display the task in the selected row (if any).
 */
void ViewProcessor::on_procTable_cellDoubleClicked(int row, int column)
{
    pid_t pid = ui->procTable->item(row, 0)->text().toInt();

    if(pid > 0)
        new Visualiser(this->parentWidget(), pid, false);
}
