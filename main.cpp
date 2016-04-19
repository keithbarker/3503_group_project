#include "mainwindow.h"
#include "Item.h"
#include "Order.h"
#include <QApplication>
#include "inventory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
