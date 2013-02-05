#include <QtGui/QApplication>
#include "mainwindow.h"
#include "sys.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sys::init();
    MainWindow w;
    w.show();
    return a.exec();
}
