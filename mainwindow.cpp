#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "Item.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scroll_layout->setAlignment(Qt::AlignTop);
    new_order = new Order();
    connect(new_order, SIGNAL(itemsChanged()), this, SLOT(update_list()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hamburger_button_clicked()
{
    // Add the hamburger item to the scroll box.
    Item *hamburger_item = new Item();
    hamburger_item->setId(new_order->getItemCount() + 1);
    hamburger_item->setItemsLeft(99);
    hamburger_item->setPrice(3.90);
    hamburger_item->setName(string("Hamburger"));

    new_order->addItem(hamburger_item);

    // Create the topping buttons.
    button_factory("Bacon", 1);
    button_factory("Cheese",2);
    button_factory("Lettuce",3);
    button_factory("Tomatoes",4);
    button_factory("Pickles",5);
    button_factory("Onions",6);
    button_factory("Ketchup",7);
    button_factory("Mustard",8);
    button_factory("Barbeque",9);
    button_factory("Mayo",10);
    button_factory("Small",11);
    button_factory("Medium",12);
    button_factory("Large",13);

    /*How are we going to handle different sizes and extras? For example,
      each size has a different price, and some of the toppings should add
      to the price as well (bacon, cheese, etc.)
      */

    // This is what changes "pages".
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_hotdog_button_clicked()
{

    // Add the hotdog item to the scroll box.
    Item *hotdog_item = new Item();
    hotdog_item->setId(new_order->getItemCount() + 1);
    hotdog_item->setItemsLeft(99);
    hotdog_item->setPrice(3.90);
    hotdog_item->setName(string("Hotdog"));

    new_order->addItem(hotdog_item);

    // Create the topping buttons.
    button_factory("Chili", 1);
    button_factory("Cheese",2);
    button_factory("Onions",3);
    button_factory("Sauerkraut",4);
    button_factory("Relish",5);;
    button_factory("Ketchup",6);
    button_factory("Mustard",7);
    button_factory("Small",8);
    button_factory("Medium",9);
    button_factory("Large",10);

    /*How are we going to handle different sizes and extras? For example,
      each size has a different price, and some of the toppings should add
      to the price as well (bacon, cheese, etc.)
      */


    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_chick_sand_button_clicked()
{
    // Add the chicken sandwich item to the scroll box.
    Item *chick_sand_item = new Item();
    chick_sand_item->setId(new_order->getItemCount() + 1);
    chick_sand_item->setItemsLeft(99);
    chick_sand_item->setPrice(2.25);
    chick_sand_item->setName(string("Chicken Sandwich"));

    new_order->addItem(chick_sand_item);

    // Create the topping buttons.
    button_factory("Bacon", 1);
    button_factory("Cheese",2);
    button_factory("Lettuce",3);
    button_factory("Tomatoes",4);
    button_factory("Pickles",5);;
    button_factory("Mayo",6);
    button_factory("Barbeque",7);
    button_factory("Small",8);
    button_factory("Medium",9);
    button_factory("Large",10);

    /*How are we going to handle different sizes and extras? For example,
      each size has a different price, and some of the toppings should add
      to the price as well (bacon, cheese, etc.)
      */

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_chick_nug_button_clicked()
{

    // Add the chicken nugget item to the scroll box.
    Item *chick_nug_item = new Item();
    chick_nug_item->setId(new_order->getItemCount() + 1);
    chick_nug_item->setItemsLeft(99);
    chick_nug_item->setPrice(1.99);
    chick_nug_item->setName(string("Chicken Nuggets"));

    new_order->addItem(chick_nug_item);

    // Create the topping buttons.
    button_factory("Sweet & Sour Sauce", 1);
    button_factory("Honey Mustard",2);
    button_factory("Onions",3);
    button_factory("Ketchup",4);
    button_factory("Mustard",5);
    button_factory("Small",6);
    button_factory("Medium",7);
    button_factory("Large",8);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_salad_button_clicked()
{
    /// Add the salad item to the scroll box.
    Item *salad_item = new Item();
    salad_item->setId(new_order->getItemCount() + 1);
    salad_item->setItemsLeft(99);
    salad_item->setPrice(3.99);
    salad_item->setName(string("Salad"));

    new_order->addItem(salad_item);

    // Create the topping buttons.
    button_factory("Tomatoes", 1);
    button_factory("Croutons",2);
    button_factory("Almonds",3);
    button_factory("Walnuts",4);
    button_factory("Bacon",5);
    button_factory("Cheese", 6);
    button_factory("Onions",7);
    button_factory("Cucumbers",8);
    button_factory("Ranch",9);
    button_factory("Italian",10);
    button_factory("Caesar", 11);
    button_factory("Honey Mustard",12);
    button_factory("Vinaigrette",13);
    button_factory("Olive Oil",14);
    button_factory("Small",15);
    button_factory("Medium",16);
    button_factory("Large",17);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_fries_button_clicked()
{
    // Add the fries item to the scroll box.
    Item *fries_item = new Item();
    fries_item->setId(new_order->getItemCount() + 1);
    fries_item->setItemsLeft(99);
    fries_item->setPrice(1.99);
    fries_item->setName(string("Fries"));

    new_order->addItem(fries_item);

    // Create the topping buttons.
    button_factory("Chili", 1);
    button_factory("Cheese",2);
    button_factory("Bacon",3);
    button_factory("Ketchup",4);
    button_factory("Mustard",5);
    button_factory("Small",6);
    button_factory("Medium",7);
    button_factory("Large",8);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_soda_button_clicked()
{
    // Add the soda item to the scroll box.
    Item *soda_item = new Item();
    soda_item->setId(new_order->getItemCount() + 1);
    soda_item->setItemsLeft(99);
    soda_item->setPrice(1.25);
    soda_item->setName(string("Soda"));

    new_order->addItem(soda_item);

    // Create the topping buttons.
    button_factory("Cherry Soda", 1);
    button_factory("Cola",2);
    button_factory("Orange Soda",3);
    button_factory("Lemon-Lime Soda",4);
    button_factory("Grape",5);
    button_factory("Root Beer",6);
    button_factory("Ginger Ale",7);
    button_factory("Small",8);
    button_factory("Medium",9);
    button_factory("Large",10);


    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tea_button_clicked()
{
    // Add the tea item to the scroll box.
    Item *tea_item = new Item();
    tea_item->setId(new_order->getItemCount() + 1);
    tea_item->setItemsLeft(99);
    tea_item->setPrice(1.00);
    tea_item->setName(string("Tea"));

    new_order->addItem(tea_item);

    // Create the topping buttons.
    button_factory("Green Tea", 1);
    button_factory("Peach Iced Tea",2);
    button_factory("Strawberry Iced Tea",3);
    button_factory("Sweet Tea",4);
    button_factory("Unsweet Tea",5);
    button_factory("Lemon Tea",6);
    button_factory("Small",7);
    button_factory("Medium",8);
    button_factory("Large",9);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_milk_shake_button_clicked()
{
    // Add the milkshake item to the scroll box.
    Item *milkshake_item = new Item();
    milkshake_item->setId(new_order->getItemCount() + 1);
    milkshake_item->setItemsLeft(99);
    milkshake_item->setPrice(3.99);
    milkshake_item->setName(string("Milkshake"));

    new_order->addItem(milkshake_item);

    // Create the topping buttons.
    button_factory("Chocolate", 1);
    button_factory("Vanilla",2);
    button_factory("Strawberry",3);
    button_factory("Cherry",4);
    button_factory("Whipped Cream",5);
    button_factory("Sprinkles",6);
    button_factory("Small",7);
    button_factory("Medium",8);
    button_factory("Large",9);
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

void MainWindow::button_factory(string name, int position) {
    QString topping_name = QString::fromStdString(name);
    QPushButton *topping_button = new QPushButton(topping_name);
    set_button_style(topping_button);

    switch(position) {
    case 1:
        ui->gridLayout->addWidget(topping_button);
        break;
    case 2:
        ui->gridLayout2->addWidget(topping_button);
        break;
    case 3:
        ui->gridLayout3->addWidget(topping_button);
        break;
    case 4:
        ui->gridLayout4->addWidget(topping_button);
        break;
    case 5:
        ui->gridLayout5->addWidget(topping_button);
        break;
    case 6:
        ui->gridLayout6->addWidget(topping_button);
        break;
    case 7:
        ui->gridLayout7->addWidget(topping_button);
        break;
    case 8:
        ui->gridLayout8->addWidget(topping_button);
        break;
    case 9:
        ui->gridLayout9->addWidget(topping_button);
        break;
    case 10:
        ui->gridLayout10->addWidget(topping_button);
        break;
    case 11:
        ui->gridLayout11->addWidget(topping_button);
        break;
    case 12:
        ui->gridLayout12->addWidget(topping_button);
        break;
    case 13:
        ui->gridLayout13->addWidget(topping_button);
        break;
    case 14:
        ui->gridLayout14->addWidget(topping_button);
        break;
    case 15:
        ui->gridLayout15->addWidget(topping_button);
        break;
    }
}

void MainWindow::update_list() {
    clear_items(ui->scroll_layout);

    vector<Item*> *items = new_order->itemArray;
    vector<Item*>::iterator it;
    int i = 0;
    for (it = items->begin(); it != items->end(); it++, i++) {
        std::ostringstream strs;
        strs << (*it)->getPrice();
        string str_price = strs.str();

        if (str_price.length() == 3)
            str_price += "0";
        else if (str_price.length() == 2)
            str_price = "0" + str_price;
        str_price = "$" + str_price;

        QPushButton *remove_button = new QPushButton("X");
        remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
        QLabel *item = new QLabel(QString::fromStdString((*it)->getName()));
        QLabel *price = new QLabel(QString::fromStdString(str_price));
        QHBoxLayout *item_line = new QHBoxLayout();
        item_line->addWidget(remove_button);
        item_line->addWidget(item);
        item_line->addWidget(price);
        ui->scroll_layout->addLayout(item_line);

        // Working on remove button.
        //int id = (*it)->getId();
        //connect(remove_button, SIGNAL(clicked(bool)), new_order, SLOT(removeItem(int));
    }
}
