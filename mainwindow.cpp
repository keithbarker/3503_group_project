#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scroll_layout->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hamburger_button_clicked()
{
    // Add the hamburger item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *hamburger = new QLabel("Hamburger");
    QLabel *price = new QLabel("$3.90");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(hamburger);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *bacon_button = new QPushButton("Bacon");
    QPushButton *cheese_button = new QPushButton("Cheese");
    QPushButton *lettuce_button = new QPushButton("Lettuce");
    QPushButton *tomatoe_button = new QPushButton("Tomatoes");
    QPushButton *pickle_button = new QPushButton("Pickles");
    QPushButton *onion_button = new QPushButton("Onions");
    QPushButton *ketchup_button = new QPushButton("Ketchup");
    QPushButton *mustard_button = new QPushButton("Mustard");
    QPushButton *bbq_button = new QPushButton("Barbeque");
    QPushButton *mayo_button = new QPushButton("Mayo");

    // Set the style and make the button checkable.
    set_button_style(bacon_button);
    set_button_style(cheese_button);
    set_button_style(lettuce_button);
    set_button_style(tomatoe_button);
    set_button_style(pickle_button);
    set_button_style(onion_button);
    set_button_style(ketchup_button);
    set_button_style(mustard_button);
    set_button_style(bbq_button);
    set_button_style(mayo_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(bacon_button);
    ui->gridLayout2->addWidget(cheese_button);
    ui->gridLayout3->addWidget(lettuce_button);
    ui->gridLayout4->addWidget(tomatoe_button);
    ui->gridLayout5->addWidget(pickle_button);
    ui->gridLayout6->addWidget(onion_button);
    ui->gridLayout7->addWidget(ketchup_button);
    ui->gridLayout8->addWidget(mustard_button);
    ui->gridLayout9->addWidget(bbq_button);
    ui->gridLayout10->addWidget(mayo_button);

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

void MainWindow::on_done_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    clear_items(ui->gridLayout);
    clear_items(ui->gridLayout2);
    clear_items(ui->gridLayout3);
    clear_items(ui->gridLayout4);
    clear_items(ui->gridLayout5);
    clear_items(ui->gridLayout6);
    clear_items(ui->gridLayout7);
    clear_items(ui->gridLayout8);
    clear_items(ui->gridLayout9);
    clear_items(ui->gridLayout10);
    clear_items(ui->gridLayout11);
    clear_items(ui->gridLayout12);
    clear_items(ui->gridLayout13);
    clear_items(ui->gridLayout14);
    clear_items(ui->gridLayout15);
}

void MainWindow::clear_items(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)))
    {
        if (item->widget())
        {
            delete item->widget();
        }
    }
}

void MainWindow::set_button_style(QPushButton *button)
{
    button->setStyleSheet(
       "background-color: rgb(87, 137, 183);"
        "max-width: 150px;"
        "height: 150px;"
        "selection-color: rgb(255, 170, 127);"
        "font: 16pt 'MS Shell Dlg 2';"
        "color: rgb(255, 255, 255);"
        "selection-background-color: rgb(66, 111, 153);"
    );
    button->setCheckable(true);
}
