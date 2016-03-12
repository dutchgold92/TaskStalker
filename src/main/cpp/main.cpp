#include <QtGui/QApplication>
#include "../../../include/main/cpp/gui/mainwindow.h"
#include "../../../include/main/cpp/core/sys.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sys::init();
    MainWindow w;
    w.show();
    return a.exec();
}
