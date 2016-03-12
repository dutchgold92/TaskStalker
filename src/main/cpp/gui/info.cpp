#include "../../../../include/main/cpp/gui/info.h"
#include "ui_info.h"

Info* Info::instance = 0;

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->logo.load(":/resources/img/logo.png");
    ui->logoLabel->setPixmap(QPixmap::fromImage(logo));
    this->show();
}

/**
 * @brief Info::get_instance Returns the instance of this dialog.
 * @param parent
 * @return
 */
Info* Info::get_instance(QWidget *parent)
{
    if(instance == 0)
        instance = new Info(parent);

    return instance;
}

Info::~Info()
{
    instance = 0;
    delete ui;
}

void Info::changeEvent(QEvent *e)
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
