#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// Try not to work on this page. I'm going to try to find
//  a better way so we don't have millions of functions. -Keith

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hamburger_button_clicked()
{
    // This is what changes "pages".
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_hotdog_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_chick_sand_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_chick_nug_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_salad_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_fries_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_soda_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tea_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_milk_shake_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_admin_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_checkout_button_clicked()
{
    // This is where we will add the confirmation page.
    // Then print out the receipt.
}

void MainWindow::on_admin_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_bacon_button_clicked()
{

}

void MainWindow::on_cheese_button_clicked()
{

}

void MainWindow::on_lettuce_button_clicked()
{

}

void MainWindow::on_tomatoes_button_clicked()
{

}

void MainWindow::on_pickles_button_clicked()
{

}

void MainWindow::on_onions_button_clicked()
{

}

void MainWindow::on_ketchup_button_clicked()
{

}

void MainWindow::on_mustard_button_clicked()
{

}

void MainWindow::on_bbq_button_clicked()
{

}

void MainWindow::on_mayo_button_clicked()
{

}

void MainWindow::on_done_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
