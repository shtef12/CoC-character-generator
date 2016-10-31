#include "mainwindow.h"
#include <QApplication>
#include "occupations.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    occupations occ;
    MainWindow w;
    w.show();

    return a.exec();
}
