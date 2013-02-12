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
    this->setWindowTitle("Activity for CPU#" + QString::number(cpu));
    ui->toggleUpdateButton->setIcon(QIcon(":/img/button_pause.png"));
    init_table();
    init_graph();
    this->update = true;
    this->closed = false;
    this->update_thread = QtConcurrent::run(this, &ViewProcessor::update_info);
    connect(this, SIGNAL(data_updated()), this, SLOT(update_data()), Qt::QueuedConnection);
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
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, QString::fromStdString(proc::get_name(current_pid)));
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

    // Setup markers
    /* THIS SEEMS TO BE CAUSING CRASHES! */
    marker_one = new QGraphicsLineItem(0, scene);
    marker_one->setLine(-100, -100, -100, 0);
    marker_one->setOpacity(0.5);
    marker_two = new QGraphicsLineItem(0, scene);
    marker_two->setLine(5, -100, 5, 0);
    marker_two->setOpacity(0.5);
    marker_three = new QGraphicsLineItem(0, scene);
    marker_three->setLine(110, -100, 110, 0);
    marker_three->setOpacity(0.5);

    // Setup marker timestamps
    marker_one_text = new QGraphicsSimpleTextItem(0, scene);
    marker_one_text->setPos(-180, -80);
    marker_two_text = new QGraphicsSimpleTextItem(0, scene);
    marker_two_text->setPos(-95, -80);
    marker_three_text = new QGraphicsSimpleTextItem(0, scene);
    marker_three_text->setPos(10, -80);
    marker_four_text = new QGraphicsSimpleTextItem(0, scene);
    marker_four_text->setPos(115, -80);

    update_timestamps();
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

    if(this->current_pid > 0)
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, this->current_pid);
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, QString::fromStdString(proc::get_name(current_pid)));
        QGraphicsEllipseItem *item = new QGraphicsEllipseItem(0, scene);
        item->setBrush(QBrush(Qt::red));
        item->setRect(180.0, -55.0, 10.0, 10.0);
    }
    else
    {
        ui->procTable->item(0, 0)->setData(Qt::DisplayRole, "None");
        ui->procTable->item(0, 1)->setData(Qt::DisplayRole, "-");
        QGraphicsEllipseItem *item = new QGraphicsEllipseItem(0, scene);
        item->setBrush(QBrush(Qt::blue));
        item->setRect(180.0, -35.0, 10.0, 10.0);
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
    for(int x = 0; x < (scene->items().size() - static_graph_items); x++)   // don't transform static items, eg. markers
        scene->items().at(x)->moveBy(-15, 0);
}

/**
 * @brief ViewProcessor::update_timestamps Updates all timestamps.
 */
void ViewProcessor::update_timestamps()
{
    ui->timeLabel->setText(QTime::currentTime().toString());
    marker_one_text->setText("<- " + QTime::currentTime().addSecs(marker_one_offset).toString());
    marker_two_text->setText("<- " + QTime::currentTime().addSecs(marker_two_offset).toString());
    marker_three_text->setText("<- " + QTime::currentTime().addSecs(marker_three_offset).toString());
    marker_four_text->setText("<- " + QTime::currentTime().addSecs(marker_four_offset).toString());
}

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
