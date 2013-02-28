#include "selectrecording.h"
#include "ui_selectrecording.h"

using namespace std;

SelectRecording* SelectRecording::instance = 0;

SelectRecording::SelectRecording(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRecording)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    QDir recordings_dir = QDir::homePath() + "/.taskstalker/recordings";
    QStringList entries = recordings_dir.entryList(QDir::Files, QDir::Unsorted);

    if(entries.isEmpty())
    {
        ui->selector->addItem("No recordings available");
        ui->playButton->setEnabled(false);
    }

    for(int x = 0; x < entries.length(); x++)
    {
        if(entries.at(x).endsWith(".tsr", Qt::CaseInsensitive))
        {
            ui->selector->addItem(entries.at(x));
        }
    }

    this->show();
}

/**
 * @brief SelectRecording::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
SelectRecording* SelectRecording::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new SelectRecording(parent);

    return instance;
}

SelectRecording::~SelectRecording()
{
    delete ui;
    instance = 0;
}

void SelectRecording::on_cancelButton_clicked()
{
    this->close();
}

void SelectRecording::on_playButton_clicked()
{
    QFile recording_file(QDir::homePath() + "/.taskstalker/recordings/" + ui->selector->currentText());

    if(recording_file.exists())
    {
        new Visualiser(this->parentWidget(), recording_file.fileName());
        this->close();
    }
    else
        cout << recording_file.fileName().toStdString() << endl;
        new ErrorDialog(this, false, "The selected recording could not be read.", ErrorDialog::error);
}
