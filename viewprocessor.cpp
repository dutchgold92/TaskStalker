#include "viewprocessor.h"
#include "ui_viewprocessor.h"

ViewProcessor::ViewProcessor(QWidget *parent, unsigned int cpu) :
    QDialog(parent),
    ui(new Ui::ViewProcessor)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    this->cpu = cpu;
    this->setWindowTitle("Activity for CPU#" + QString::number(this->cpu));
    ui->procTable->insertRow(ui->procTable->rowCount());
    ui->procTable->setItem(0, 0, new QTableWidgetItem());
    ui->procTable->setItem(0, 1, new QTableWidgetItem());
    init_graph();
    this->update = true;
    this->update_thread = QtConcurrent::run(this, &ViewProcessor::update_info);
    connect(this, SIGNAL(data_updated()), this, SLOT(update_data()), Qt::QueuedConnection);
    this->show();
}

ViewProcessor::~ViewProcessor()
{
    update = false;
    update_thread.waitForFinished();
    delete ui;
}

/**
 * @brief ViewProcessor::init_graph Configures things relating to the graph.
 */
void ViewProcessor::init_graph()
{
    scene = new QGraphicsScene(this);
    ui->graph->setScene(scene);
}

/**
 * @brief ViewProcessor::update_info Updates this->current_pid using proc::get_cpu_task(), then emits data_updated() signal. Should be threaded.
 */
void ViewProcessor::update_info()
{
    while(update)
    {
        this->current_pid = proc::get_cpu_task(this->cpu);
        emit(data_updated());
        sleep(sys::get_running_update_interval());
    }
}

/**
 * @brief ViewProcessor::update_data Slot called when current process data is updated.
 */
void ViewProcessor::update_data()
{
    ui->timeLabel->setText(QTime::currentTime().toString());
    transform_graph();

    if(this->current_pid > 0)
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, this->current_pid);
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, QString::fromStdString(proc::get_name(current_pid)));
        QGraphicsEllipseItem *item = new QGraphicsEllipseItem(0, scene);
        item->setRect(180.0, -50.0, 10.0, 10.0);
    }
    else
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, "None");
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, "-");
        QGraphicsEllipseItem *item = new QGraphicsEllipseItem(0, scene);
        item->setRect(180.0, 50.0, 10.0, 10.0);
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
 * @brief ViewProcessor::transform_graph Transforms all points on the graph, to appear as if it is side-scrolling.
 */
void ViewProcessor::transform_graph()
{
    for(int x = 0; x < scene->items().size(); x++)
        scene->items().at(x)->moveBy(-15, 0);
}
