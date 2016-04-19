#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "Item.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include "inventory.h"
#include <ctime>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new_order = new Order();
    new_Inventory = new Inventory();
    connect(new_order, SIGNAL(itemsChanged()), this, SLOT(update_list()));
    connect(new_order, SIGNAL(itemsChanged()), this, SLOT(update_totals()));
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
    hamburger_item->setItemsLeft(hamburger_item->getItemsLeft() - 1);
    hamburger_item->setPrice(3.99);
    hamburger_item->setName(string("Hamburger"));

    // Set the allowed toppings.
    vector<string> extras {"Bacon","Cheese","Lettuce","Tomatoes","Pickles","Onions","Ketchup","Mustard","Barbeque","Mayo"};
    hamburger_item->addAllowedExtras(extras);

    new_order->addItem(hamburger_item);

    // Update the toppings page label.
    ui->food_label_2->setText("What toppings would you like on your hamburger?");

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

    /*How are we going to handle different sizes and extras? For example,
      each size has a different price, and some of the toppings should add
      to the price as well (bacon, cheese, etc.)
      */

    // This is what changes "pages".
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_hotdog_button_clicked()
{

    // Add the hotdog item to the scroll box.
    Item *hotdog_item = new Item();
    hotdog_item->setId(new_order->getItemCount() + 1);
    hotdog_item->setItemsLeft(hotdog_item->getItemsLeft() - 1);
    hotdog_item->setPrice(2.99);
    hotdog_item->setName(string("Hotdog"));

    // Set the allowed toppings.
    vector<string> extras {"Chili","Cheese","Onions","Sauerkraut","Relish","Ketchup","Mustard"};
    hotdog_item->addAllowedExtras(extras);

    new_order->addItem(hotdog_item);

    // Update the toppings page label.
    ui->food_label_2->setText("What toppings would you like on your hotdog?");

    // Create the topping buttons.
    button_factory("Chili", 1);
    button_factory("Cheese",2);
    button_factory("Onions",3);
    button_factory("Sauerkraut",4);
    button_factory("Relish",5);;
    button_factory("Ketchup",6);
    button_factory("Mustard",7);

    /*How are we going to handle different sizes and extras? For example,
      each size has a different price, and some of the toppings should add
      to the price as well (bacon, cheese, etc.)
      */


    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_chick_sand_button_clicked()
{
    // Add the chicken sandwich item to the scroll box.
    Item *chick_sand_item = new Item();
    chick_sand_item->setId(new_order->getItemCount() + 1);
    chick_sand_item->setItemsLeft(chick_sand_item->getItemsLeft() - 1);
    chick_sand_item->setPrice(3.49);
    chick_sand_item->setName(string("Chicken Sandwich"));

    vector<string> extras {"Bacon","Cheese","Lettuce","Tomatoes","Pickles","Onions","Ketchup","Mustard","Barbeque","Mayo"};
    chick_sand_item->addAllowedExtras(extras);

    new_order->addItem(chick_sand_item);

    // Update the toppings page label.
    ui->food_label_2->setText("What would you like on your chicken sandwich?");

    // Create the topping buttons.
    button_factory("Bacon", 1);
    button_factory("Cheese",2);
    button_factory("Lettuce",3);
    button_factory("Tomatoes",4);
    button_factory("Pickles",5);;
    button_factory("Mayo",6);
    button_factory("Barbeque",7);

    /*How are we going to handle different sizes and extras? For example,
      each size has a different price, and some of the toppings should add
      to the price as well (bacon, cheese, etc.)
      */

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_chick_nug_button_clicked()
{

    // Add the chicken nugget item to the scroll box.
    Item *chick_nug_item = new Item();
    chick_nug_item->setId(new_order->getItemCount() + 1);
    chick_nug_item->setItemsLeft(chick_nug_item->getItemsLeft() - 1);
    chick_nug_item->setPrice(1.99);
    chick_nug_item->setName(string("Chicken Nuggets"));

    vector<string> extras {"Honey Mustard","Hot Sauce","Barbecue","Ketchup","Mustard"};
    chick_nug_item->addAllowedExtras(extras);

    new_order->addItem(chick_nug_item);

    // Update the toppings page label.
    ui->food_label_2->setText("What sauce would you like?");

    // Create the topping buttons.
    button_factory("Honey Mustard",1);
    button_factory("Hot Sauce",2);
    button_factory("Barebecue",3);
    button_factory("Ketchup",4);
    button_factory("Mustard",5);


    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_salad_button_clicked()
{
    /// Add the salad item to the scroll box.
    Item *salad_item = new Item();
    salad_item->setId(new_order->getItemCount() + 1);
    salad_item->setItemsLeft(salad_item->getItemsLeft() - 1);
    salad_item->setPrice(3.99);
    salad_item->setName(string("Salad"));

    new_order->addItem(salad_item);

    vector<string> extras {"Tomoatoes","Croutons","Almonds","Walnuts","Bacon","Cheese","Onions","Cucumbers","Ranch","Italian","Caesar"
                           ,"Honey Mustard","Vinaigrette","Olive Oil"};
    salad_item->addAllowedExtras(extras);

    // Update the toppings page label.
    ui->food_label_2->setText("What toppings would you like on your salad?");

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

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_fries_button_clicked()
{
    // Add the fries item to the scroll box.
    Item *fries_item = new Item();
    fries_item->setId(new_order->getItemCount() + 1);
    fries_item->setItemsLeft(fries_item->getItemsLeft() - 1);
    fries_item->setPrice(1.99);
    fries_item->setName(string("Fries"));

    new_order->addItem(fries_item);

    vector<string> extras {"Chili","Cheese","Bacon","Ketchup","Mustard"};
    fries_item->addAllowedExtras(extras);

    // Update the toppings page label.
    ui->food_label_2->setText("What toppings would you like on your fries?");

    // Create the topping buttons.
    button_factory("Chili", 1);
    button_factory("Cheese",2);
    button_factory("Bacon",3);
    button_factory("Ketchup",4);
    button_factory("Mustard",5);

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_soda_button_clicked()
{
    // Add the soda item to the scroll box.
    Item *soda_item = new Item();
    soda_item->setId(new_order->getItemCount() + 1);
    soda_item->setItemsLeft(soda_item->getItemsLeft() - 1);
    soda_item->setPrice(1.49);
    soda_item->setName(string("Soda"));

    new_order->addItem(soda_item);

    vector<string> extras {"Cherry","Cola","Orange","Lemon-Lime","Grape","Root Beer", "Ginger Ale","Water"};
    soda_item->addAllowedExtras(extras);

    // Update the toppings page label.
    ui->food_label_2->setText("What flavor of soda would you like?");

    // Create the topping buttons.
    button_factory("Cherry", 1);
    button_factory("Cola",2);
    button_factory("Orange",3);
    button_factory("Lemon-Lime",4);
    button_factory("Grape",5);
    button_factory("Root Beer",6);
    button_factory("Ginger Ale",7);
    button_factory("Water",8);

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tea_button_clicked()
{
    // Add the tea item to the scroll box.
    Item *tea_item = new Item();
    tea_item->setId(new_order->getItemCount() + 1);
    tea_item->setItemsLeft(tea_item->getItemsLeft() - 1);
    tea_item->setPrice(0.99);
    tea_item->setName(string("Tea"));

    new_order->addItem(tea_item);

    vector<string> extras {"Honey Mustard","Hot Sauce","Barbecue","Ketchup","Mustard"};
    tea_item->addAllowedExtras(extras);

    // Update the toppings page label.
    ui->food_label_2->setText("What flavor of tea would you like?");

    // Create the topping buttons.
    button_factory("Green Tea", 1);
    button_factory("Peach Tea",2);
    button_factory("Strawberry",3);
    button_factory("Sweet Tea",4);
    button_factory("Unsweet Tea",5);
    button_factory("Lemon Tea",6);

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_milk_shake_button_clicked()
{
    // Add the milkshake item to the scroll box.
    Item *milkshake_item = new Item();
    milkshake_item->setId(new_order->getItemCount() + 1);
    milkshake_item->setItemsLeft(milkshake_item->getItemsLeft() - 1);
    milkshake_item->setPrice(3.99);
    milkshake_item->setName(string("Milkshake"));

    new_order->addItem(milkshake_item);

    vector<string> extras {"Chocolate","Vanilla","Strawberry","Cherry","Whipped Cream", "Sprinkles"};
    milkshake_item->addAllowedExtras(extras);

    // Update the toppings page label.
    ui->food_label_2->setText("What flavor of shake would you like?");

    // Create the topping buttons.
    button_factory("Chocolate", 1);
    button_factory("Vanilla",2);
    button_factory("Strawberry",3);
    button_factory("Cherry",4);
    button_factory("Whipped Cream",5);
    button_factory("Sprinkles",6);

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_admin_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_checkout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
    while((item = layout->takeAt(0)) != NULL)
    {
        if (item->layout()) {
            clear_items(item->layout());
        }
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
    connect(topping_button, &QPushButton::toggled, [=] {
        Item *item = new_order->itemArray->back();
        if (topping_button->isChecked()) {
            item->addExtra(name);
        } else {
            item->removeExtra(name);
        }
        emit new_order->itemsChanged();
    });

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
    if (ui->scrollAreaWidgetContents->layout())
        clear_items(ui->scrollAreaWidgetContents->layout());
        delete ui->scrollAreaWidgetContents->layout();

    vector<Item*> *items = new_order->itemArray;
    vector<Item*>::iterator it;
    QVBoxLayout* scroll_layout = new QVBoxLayout();
    scroll_layout->setAlignment(Qt::AlignTop);
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
        remove_button->setStyleSheet("color:white;background-color:rgb(195,50,46);max-width: 20px");
        QLabel *item = new QLabel(QString::fromStdString((*it)->getName()));
        item->setStyleSheet("font: 75 14pt 'MS Shell Dlg 2';");
        QLabel *price = new QLabel(QString::fromStdString(str_price));
        price->setStyleSheet("font: 75 14pt 'MS Shell Dlg 2';");
        QHBoxLayout *item_line = new QHBoxLayout();
        item_line->addWidget(remove_button);
        item_line->addWidget(item);
        item_line->addWidget(price);
        scroll_layout->addLayout(item_line);

        //trying to put extras in cart on main page
        QLabel *toppings = new QLabel(QString::fromStdString((*it)->getExtras()));
        QHBoxLayout *item_line2 = new QHBoxLayout();
        item_line2->addWidget(toppings);
        scroll_layout->addLayout(item_line2);


        // Set the function to be called when the remove button is clicked.
        // In this case I'm using a lambda and using an inline function.
        connect(remove_button, &QPushButton::clicked, [=] {new_order->removeItem(i);});
    }
    ui->scrollAreaWidgetContents->setLayout(scroll_layout);
}

void MainWindow::update_totals() {
    ui->subtotal_label->setText("$" + QString::number(new_order->getSubtotal()));
    ui->total_label->setText("$" + QString::number(new_order->getTotal()));
}

void MainWindow::on_no_confirmbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_yes_confirm_button_clicked()
{
    // Clear the scroll area.
    if (ui->scrollAreaWidgetContents_2->layout())
        clear_items(ui->scrollAreaWidgetContents_2->layout());
        delete ui->scrollAreaWidgetContents_2->layout();

    // Create the vertical layout for the inside of the scroll.
    QVBoxLayout* receipt_layout = new QVBoxLayout();
    receipt_layout->setAlignment(Qt::AlignTop);

    // Print out a receipt header.
    QHBoxLayout *logo_line = new QHBoxLayout();
    QLabel *logo = new QLabel(QString::fromStdString("XYZ Burgers"));
    logo->setStyleSheet("font: 75 24pt 'MS Shell Dlg 2';");
    logo_line->addWidget(logo);

    QHBoxLayout *thanks_line = new QHBoxLayout();
    QLabel *thanks = new QLabel(QString::fromStdString("Thank you for your order!"));
    thanks->setStyleSheet("font: 50 12pt 'MS Shell Dlg 2';");
    thanks_line->addWidget(thanks);

    QHBoxLayout *time_line = new QHBoxLayout();
    const time_t ctt = time(0);
    string time_str = "Order Placed: ";
    time_str += asctime(localtime(&ctt));
    QLabel *time = new QLabel(QString::fromStdString(time_str));
    time->setStyleSheet("font: 50 12pt 'MS Shell Dlg 2';");
    time_line->addWidget(time);

    receipt_layout->addLayout(logo_line);
    receipt_layout->addLayout(thanks_line);
    receipt_layout->addLayout(time_line);

    // Print out the items.
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

        QLabel *item = new QLabel(QString::fromStdString((*it)->getName()));
        item->setStyleSheet("font: 75 14pt 'MS Shell Dlg 2';");
        QLabel *price = new QLabel(QString::fromStdString(str_price));
        price->setStyleSheet("font: 75 14pt 'MS Shell Dlg 2';");
        QHBoxLayout *item_line = new QHBoxLayout();
        item_line->addWidget(item);
        item_line->addWidget(price);
        receipt_layout->addLayout(item_line);

        //trying to put extras in cart on main page
        QLabel *toppings = new QLabel(QString::fromStdString((*it)->getExtras()));
        QHBoxLayout *item_line2 = new QHBoxLayout();
        item_line2->addWidget(toppings);
        receipt_layout->addLayout(item_line2);
    }

    // Add the footer.
    QHBoxLayout *line_line = new QHBoxLayout();
    QLabel *line = new QLabel(QString::fromStdString(string(60, '_')));
    line_line->addWidget(line);
    receipt_layout->addLayout(line_line);

    // Add the subtotal line.
    QHBoxLayout *subtotal_line = new QHBoxLayout();
    QLabel *blank = new QLabel("");
    QLabel *subtotal = new QLabel("Subtotal:  $" + QString::number(new_order->getSubtotal()));
    subtotal->setStyleSheet("font: 12pt 'MS Shell Dlg 2';");
    subtotal_line->addWidget(blank);
    subtotal_line->addWidget(subtotal);
    receipt_layout->addLayout(subtotal_line);

    // Add the total line.
    QHBoxLayout *total_line = new QHBoxLayout();
    QLabel *total = new QLabel("Total:\t$" + QString::number(new_order->getTotal()));
    total->setStyleSheet("font: 14pt 'MS Shell Dlg 2';");
    total_line->addWidget(blank);
    total_line->addWidget(total);
    receipt_layout->addLayout(total_line);

    // Add the layout to the scroll area.
    ui->scrollAreaWidgetContents_2->setLayout(receipt_layout);

    // Navigate to the receipt page.
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_receipt_done_button_clicked()
{
    new_Inventory->updateInventory(new_order->itemArray);
    new_order->clearOrder();    //clears itemarray and totals
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_password_enter_button_clicked()
{
    if(ui->password_box->text() == "admin")
    {
        ui->stackedWidget->setCurrentIndex(5);

        ui->password_box->setText("");
    }
}

void MainWindow::on_inventory_done_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_password_box_editingFinished()
{
    if(ui->password_box->text() == "admin"){
        ui->stackedWidget->setCurrentIndex(5);
        ui->password_box->setText("");
    }
}

void MainWindow::on_hamburger_inv_button_clicked()
{
    ui->manage_label->setText("How many hamburgers would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_hotdog_inv_button_clicked()
{
    ui->manage_label->setText("How many hotdogs would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_chick_sand_inv_button_clicked()
{
    ui->manage_label->setText("How many chicken sandwiches would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_chick_nug_inv_button_clicked()
{
    ui->manage_label->setText("How many chicken nuggets would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_salad_inv_button_clicked()
{
    ui->manage_label->setText("How many salads would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_fries_inv_button_clicked()
{
    ui->manage_label->setText("How many fries would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_soft_drink_inv_button_clicked()
{
    ui->manage_label->setText("How many soft drinks would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_tea_inv_button_clicked()
{
    ui->manage_label->setText("How much tea would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_milkshake_inv_button_clicked()
{
    ui->manage_label->setText("How many milkshakes would you like to add to the inventory?");

    ui->stackedWidget->setCurrentIndex(6);

    ui->manage_box->setText("");
}

void MainWindow::on_manage_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
