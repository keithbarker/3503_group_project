#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Order.h"
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
    // setup the gui.
    ui->setupUi(this);

    // Create a new order and inventory.
    new_order = new Order();
    new_Inventory = new Inventory();

    // Set up signals when items get added or removed.
    connect(new_order, SIGNAL(itemsChanged()), this, SLOT(update_list()));
    connect(new_order, SIGNAL(itemsChanged()), this, SLOT(update_totals()));

    // Prevents the inventory menu from selecting an item to manage.
    inv_item = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hamburger_button_clicked()
{
    // Add the hamburger item to the scroll box.
    Item *hamburger_item = new Item();
    hamburger_item->setItemsLeft(hamburger_item->getItemsLeft() - 1);
    hamburger_item->setPrice(3.99);
    hamburger_item->setName(string("Hamburger"));

    // Set the allowed toppings.
    vector<string> extras {"Bacon","Cheese","Lettuce","Tomatoes","Pickles","Onions","Ketchup","Mustard","Barbeque","Mayo"};
    hamburger_item->addAllowedExtras(extras);

    // Add the hamburger to the order.
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

    // This is what changes "pages".
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_hotdog_button_clicked()
{

    // Add the hotdog item to the scroll box.
    Item *hotdog_item = new Item();
    hotdog_item->setItemsLeft(hotdog_item->getItemsLeft() - 1);
    hotdog_item->setPrice(2.99);
    hotdog_item->setName(string("Hotdog"));

    // Set the allowed toppings.
    vector<string> extras {"Chili","Cheese","Onions","Sauerkraut","Relish","Ketchup","Mustard"};
    hotdog_item->addAllowedExtras(extras);

    // Add the hotdog item to the order.
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

    // Navigate to the topping page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_chick_sand_button_clicked()
{
    // Add the chicken sandwich item to the scroll box.
    Item *chick_sand_item = new Item();
    chick_sand_item->setItemsLeft(chick_sand_item->getItemsLeft() - 1);
    chick_sand_item->setPrice(3.49);
    chick_sand_item->setName(string("Chicken Sandwich"));

    vector<string> extras {"Bacon","Cheese","Lettuce","Tomatoes","Pickles","Onions","Ketchup","Mustard","Barbeque","Mayo"};
    chick_sand_item->addAllowedExtras(extras);

    // Add the chicken sandwich item to the order.
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

    // Navigate to the topping page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_chick_nug_button_clicked()
{

    // Add the chicken nugget item to the scroll box.
    Item *chick_nug_item = new Item();
    chick_nug_item->setItemsLeft(chick_nug_item->getItemsLeft() - 1);
    chick_nug_item->setPrice(1.99);
    chick_nug_item->setName(string("Chicken Nuggets"));

    vector<string> extras {"Honey Mustard","Hot Sauce","Barbecue","Ketchup","Mustard"};
    chick_nug_item->addAllowedExtras(extras);

    // Add the nuggets item to the order.
    new_order->addItem(chick_nug_item);

    // Update the toppings page label.
    ui->food_label_2->setText("What sauce would you like?");

    // Create the topping buttons.
    button_factory("Honey Mustard",1);
    button_factory("Hot Sauce",2);
    button_factory("Barebecue",3);
    button_factory("Ketchup",4);
    button_factory("Mustard",5);

    // Navigate to the topping page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_salad_button_clicked()
{
    // Add the salad item to the scroll box.
    Item *salad_item = new Item();
    salad_item->setItemsLeft(salad_item->getItemsLeft() - 1);
    salad_item->setPrice(3.99);
    salad_item->setName(string("Salad"));

    // Add the salad item to the order.
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

    // Navigate to the topping page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_fries_button_clicked()
{
    // Add the fries item to the scroll box.
    Item *fries_item = new Item();
    fries_item->setItemsLeft(fries_item->getItemsLeft() - 1);
    fries_item->setPrice(1.99);
    fries_item->setName(string("Fries"));

    // Add the fries item to the order.
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

    // Navigate to the topping page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_soda_button_clicked()
{
    // Add the soda item to the scroll box.
    Item *soda_item = new Item();
    soda_item->setItemsLeft(soda_item->getItemsLeft() - 1);
    soda_item->setPrice(1.49);
    soda_item->setName(string("Soda"));

    // Add the soda item to the order.
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

    // Navigate to the flavor page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tea_button_clicked()
{
    // Add the tea item to the scroll box.
    Item *tea_item = new Item();
    tea_item->setItemsLeft(tea_item->getItemsLeft() - 1);
    tea_item->setPrice(0.99);
    tea_item->setName(string("Tea"));

    // Add the tea item to the order.
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

    // Navigate to the flavor page.
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_milk_shake_button_clicked()
{
    // Add the milkshake item to the scroll box.
    Item *milkshake_item = new Item();
    milkshake_item->setItemsLeft(milkshake_item->getItemsLeft() - 1);
    milkshake_item->setPrice(3.99);
    milkshake_item->setName(string("Milkshake"));

    // Add the milkshake item to the order.
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

    // Navigate to the flavor page.
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

    // Clear out the topping buttons.
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
    // Take the layout/widget from the top of the given layout
    // and delete it's contents.
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
    // Add the awesome color, size, and font to our buttons.
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
    // Button factory used to create the topping buttons.
    QString topping_name = QString::fromStdString(name);
    QPushButton *topping_button = new QPushButton(topping_name);
    set_button_style(topping_button);

    // Set up a function to be called when the buttons are toggled.
    // In this case, I'm using a lambda to make an inline function.
    connect(topping_button, &QPushButton::toggled, [=] {
        Item *item = new_order->itemArray->back();
        if (topping_button->isChecked()) {
            item->addExtra(name);

            // Adjust pricing for certian toppings.
            if (name == "Bacon") {
                item->setPrice(item->getPrice() + 0.75);
            } else if (name == "Cheese") {
                item->setPrice(item->getPrice() + 0.50);
            } else if (name == "Chili") {
                item->setPrice(item->getPrice() + 0.75);
            }
        } else {
            item->removeExtra(name);

            // Again, adjust pricing for certain toppings.
            if (name == "Bacon") {
                item->setPrice(item->getPrice() - 0.75);
            } else if (name == "Cheese") {
                item->setPrice(item->getPrice() - 0.50);
            } else if (name == "Chili") {
                item->setPrice(item->getPrice() - 0.75);
            }
        }

        // Throw the signal that the items have changed.
        emit new_order->itemsChanged();
    });

    // Decide where to put the button in the topping layouts.
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
    // Updates the side list with the current list of items.
    // This gets called when the Order::itemsChanged() signal is raised.

    // Remove the old layout.
    if (ui->scrollAreaWidgetContents->layout())
        clear_items(ui->scrollAreaWidgetContents->layout());
        delete ui->scrollAreaWidgetContents->layout();

    // Get the items from the order
    vector<Item*> *items = new_order->itemArray;
    vector<Item*>::iterator it;

    // Create a new scroll layout and add the items to it.
    QVBoxLayout* scroll_layout = new QVBoxLayout();
    scroll_layout->setAlignment(Qt::AlignTop);
    int i = 0;
    for (it = items->begin(); it != items->end(); it++, i++) {
        string str_price = price_to_str((*it)->getPrice());

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

    // Add the new scroll layout to the contents of the scroll area.
    ui->scrollAreaWidgetContents->setLayout(scroll_layout);
}

void MainWindow::update_totals() {
    // Also called when Order::itemsChanges() is raised.
    // updates the subtotal and total labels at the bottom of the main page.
    ui->subtotal_label->setText(QString::fromStdString(price_to_str(new_order->getSubtotal())));
    ui->total_label->setText(QString::fromStdString(price_to_str(new_order->getTotal())));
}

string MainWindow::price_to_str(double price) {
    // Turn the double into a string.
    std::ostringstream strs;
    strs << price;
    string str_price = strs.str();

    // Make sure the precision is 2 decimal places.
    size_t period = str_price.find(".");
    if (period != string::npos) {
        if (str_price.length() - period == 1) {
            str_price += "00";
        } else if (str_price.length() - period == 2) {
            str_price += "0";
        }
        if (str_price.length() - period == str_price.length()) {
            str_price = "0" + str_price;
        }
    }

    // Add a $ sign and give it back.
    str_price = "$" + str_price;
    return str_price;
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
        string str_price = price_to_str((*it)->getPrice());

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
    QLabel *subtotal = new QLabel("Subtotal:  " + QString::fromStdString(price_to_str(new_order->getSubtotal())));

    subtotal->setStyleSheet("font: 12pt 'MS Shell Dlg 2';");
    subtotal_line->addWidget(blank);
    subtotal_line->addWidget(subtotal);
    receipt_layout->addLayout(subtotal_line);

    // Add the total line.
    QHBoxLayout *total_line = new QHBoxLayout();
    QLabel *total = new QLabel("Total:\t" + QString::fromStdString(price_to_str(new_order->getTotal())));
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
    // When the user is done and they select new order, update the inventory,
    // delete the old order and return them to the main page.
    new_Inventory->updateInventory(new_order->itemArray);
    new_order->clearOrder();    //clears itemarray and totals
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_password_enter_button_clicked()
{
    // Verify the user has access to the admin section.
    if(ui->password_box->text() == "admin")
    {
        ui->stackedWidget->setCurrentIndex(5);

        ui->inv_label->setText(QString::number(new_Inventory->getHamburgerCount()));
        ui->inv_label_2->setText(QString::number(new_Inventory->getHotdogCount()));
        ui->inv_label_3->setText(QString::number(new_Inventory->getChickenSandwichCount()));
        ui->inv_label_4->setText(QString::number(new_Inventory->getChickenNuggetCount()));
        ui->inv_label_5->setText(QString::number(new_Inventory->getSaladCount()));
        ui->inv_label_6->setText(QString::number(new_Inventory->getFriesCount()));
        ui->inv_label_7->setText(QString::number(new_Inventory->getSodaCount()));
        ui->inv_label_8->setText(QString::number(new_Inventory->getTeaCount()));
        ui->inv_label_9->setText(QString::number(new_Inventory->getMilkshakeCount()));

        ui->password_box->setText("");
    }
}

void MainWindow::on_inventory_done_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_password_box_editingFinished()
{
    // Same thing as on_password_enter_button_clicked()
    // but allows the user to just press enter.
    if(ui->password_box->text() == "admin"){
        ui->stackedWidget->setCurrentIndex(5);

        ui->inv_label->setText(QString::number(new_Inventory->getHamburgerCount()));

        ui->inv_label->setText(QString::number(new_Inventory->getHamburgerCount()));
        ui->inv_label_2->setText(QString::number(new_Inventory->getHotdogCount()));
        ui->inv_label_3->setText(QString::number(new_Inventory->getChickenSandwichCount()));
        ui->inv_label_4->setText(QString::number(new_Inventory->getChickenNuggetCount()));
        ui->inv_label_5->setText(QString::number(new_Inventory->getSaladCount()));
        ui->inv_label_6->setText(QString::number(new_Inventory->getFriesCount()));
        ui->inv_label_7->setText(QString::number(new_Inventory->getSodaCount()));
        ui->inv_label_8->setText(QString::number(new_Inventory->getTeaCount()));
        ui->inv_label_9->setText(QString::number(new_Inventory->getMilkshakeCount()));

        ui->password_box->setText("");
    }
}

void MainWindow::on_hamburger_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many hamburgers would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    this->inv_item = 1;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_hotdog_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many hotdogs would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 2;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_chick_sand_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many chicken sandwiches would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 3;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_chick_nug_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many chicken nuggets would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 4;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_salad_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many salads would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 5;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_fries_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many fries would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 6;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_soft_drink_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many soft drinks would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 7;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_tea_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How much tea would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 8;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_milkshake_inv_button_clicked()
{
    // Set the label for the manage page.
    ui->manage_label->setText("How many milkshakes would you like to add to the inventory?");

    // Navigate to the manage inventory page.
    ui->stackedWidget->setCurrentIndex(6);

    // This is how it knows which inventory item it needs to edit.
    inv_item = 9;

    // Clean up.
    ui->manage_box->setText("");
}

void MainWindow::on_manage_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_inv_enter_button_clicked()
{
    // Determine which inventory item to update and update it with the provided value.
    switch(this->inv_item)

    {
    case 1:
        new_Inventory->setHamburgerCount(new_Inventory->getHamburgerCount() + ui->manage_box->text().toInt());
        break;

    case 2:
        new_Inventory->setHotdogCount(new_Inventory->getHotdogCount() + ui->manage_box->text().toInt());
        break;

    case 3:
        new_Inventory->setChickenSandwichCount(new_Inventory->getChickenSandwichCount() + ui->manage_box->text().toInt());
        break;

    case 4:
        new_Inventory->setChickenNuggetCount(new_Inventory->getChickenNuggetCount() + ui->manage_box->text().toInt());
        break;

    case 5:
        new_Inventory->setSaladCount(new_Inventory->getSaladCount() + ui->manage_box->text().toInt());
        break;

    case 6:
        new_Inventory->setFriesCount(new_Inventory->getFriesCount() + ui->manage_box->text().toInt());
        break;

    case 7:
        new_Inventory->setSodaCount(new_Inventory->getSodaCount() + ui->manage_box->text().toInt());
        break;

    case 8:
        new_Inventory->setTeaCount(new_Inventory->getTeaCount() + ui->manage_box->text().toInt());
        break;

    case 9:
        new_Inventory->setMilkshakeCount(new_Inventory->getMilkshakeCount() + ui->manage_box->text().toInt());
        break;
    }

    ui->stackedWidget->setCurrentIndex(5);

    ui->inv_label->setText(QString::number(new_Inventory->getHamburgerCount()));
    ui->inv_label_2->setText(QString::number(new_Inventory->getHotdogCount()));
    ui->inv_label_3->setText(QString::number(new_Inventory->getChickenSandwichCount()));
    ui->inv_label_4->setText(QString::number(new_Inventory->getChickenNuggetCount()));
    ui->inv_label_5->setText(QString::number(new_Inventory->getSaladCount()));
    ui->inv_label_6->setText(QString::number(new_Inventory->getFriesCount()));
    ui->inv_label_7->setText(QString::number(new_Inventory->getSodaCount()));
    ui->inv_label_8->setText(QString::number(new_Inventory->getTeaCount()));
    ui->inv_label_9->setText(QString::number(new_Inventory->getMilkshakeCount()));

    ui->manage_box->setText("");
}
