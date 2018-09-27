#include "widget.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(200,230);
    w.setWindowTitle("calculator");
    //QIcon *icon=new QIcon("../test_calculator/deepin-launcher.svg");
    //w.setWindowIcon(*icon);
    w.show();

    return a.exec();
}
