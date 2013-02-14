#include "simulatorinit.h"
#include "ui_simulatorinit.h"

using namespace std;

SimulatorInit* SimulatorInit::instance = 0;

SimulatorInit::SimulatorInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulatorInit)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setFixedSize(this->size());
    browser = new QFileDialog(this, "Select an executable file", QDir::currentPath());
    connect(browser, SIGNAL(fileSelected(QString)), this, SLOT(file_selected()), Qt::QueuedConnection);
    this->show();
}

/**
 * @brief SimulatorInit::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
SimulatorInit* SimulatorInit::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new SimulatorInit(parent);

    return instance;
}

SimulatorInit::~SimulatorInit()
{
    instance = 0;
    delete ui;
}

void SimulatorInit::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
  * Action-Listener: Continue button
  */
void SimulatorInit::on_continueButton_clicked()
{
    if(!ui->fileInput->text().isEmpty())
    {
        if(QFile(ui->fileInput->text()).exists())
        {
            if(access(ui->fileInput->text().toStdString().c_str(), X_OK) == 0)  // test if file is executable
            {
                process = new QProcess;
                process->start(ui->fileInput->text());

                if(process->waitForStarted())
                {
                    new Visualiser(this->parentWidget(), process->pid(), true);
                    this->close();
                }
                else
                    new ErrorDialog(this, false, "Failed to execute file.", ErrorDialog::error);
            }
            else
                new ErrorDialog(this, false, "Selected file is not executable.", ErrorDialog::error);
        }
        else
        {
            new ErrorDialog(this, false, "Invalid program path or permissions!", ErrorDialog::error);
        }
    }
    else
    {
        new ErrorDialog(this, false, "Please select a file first!", ErrorDialog::error);
    }
}

/**
  * Action-Listener: Cancel button
  */
void SimulatorInit::on_cancelButton_clicked()
{
    this->close();
}

/**
 * @brief SimulatorInit::on_browseButton_clicked Opens file browser
 */
void SimulatorInit::on_browseButton_clicked()
{
    browser->show();
}

/**
 * @brief SimulatorInit::file_selected Slot called when the user selects a file
 */
void SimulatorInit::file_selected()
{
    ui->fileInput->setText(browser->selectedFiles().first());
}
