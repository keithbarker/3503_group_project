#include "mainwindow.h"
#include "Item.h"
#include "Order.h"
#include <QApplication>
#include "inventory.h"

int main(int argc, char *argv[])
{
    // Initialize the qt application.
    QApplication a(argc, argv);

    // Create a main window and display it to the user.
    MainWindow w;
    w.show();

    return a.exec();
}
