#include "plugmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlugManager w;
    w.show();
    return a.exec();
}
