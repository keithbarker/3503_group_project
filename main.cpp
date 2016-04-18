#include "mainwindow.h"
#include "Item.h"
#include "Drinks.h"
#include "Order.h"
#include "Food.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
