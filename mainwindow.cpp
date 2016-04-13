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
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *hotdog = new QLabel("Hotdog");
    QLabel *price = new QLabel("$1.25");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(hotdog);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *sauerkraut_button = new QPushButton("Sauerkraut");
    QPushButton *relish_button = new QPushButton("Relish");
    QPushButton *onion_button = new QPushButton("Onions");
    QPushButton *ketchup_button = new QPushButton("Ketchup");
    QPushButton *mustard_button = new QPushButton("Mustard");
    QPushButton *bbq_button = new QPushButton("Barbeque");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *medium_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(sauerkraut_button);
    set_button_style(relish_button);
    set_button_style(onion_button);
    set_button_style(ketchup_button);
    set_button_style(mustard_button);
    set_button_style(bbq_button);
    set_button_style(small_button);
    set_button_style(medium_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(sauerkraut_button);
    ui->gridLayout2->addWidget(relish_button);
    ui->gridLayout3->addWidget(onion_button);
    ui->gridLayout4->addWidget(ketchup_button);
    ui->gridLayout5->addWidget(mustard_button);
    ui->gridLayout6->addWidget(bbq_button);
    ui->gridLayout7->addWidget(small_button);
    ui->gridLayout8->addWidget(medium_button);
    ui->gridLayout9->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_chick_sand_button_clicked()
{
    // Add the chikcen sandwich item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *chick_sand = new QLabel("Chicken Sandwich");
    QLabel *price = new QLabel("$2.25");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(chick_sand);
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
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *medium_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

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
    set_button_style(small_button);
    set_button_style(medium_button);
    set_button_style(large_button);

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
    ui->gridLayout8->addWidget(small_button);
    ui->gridLayout9->addWidget(medium_button);
    ui->gridLayout10->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_chick_nug_button_clicked()
{
    // Add the chicken nugget item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *chick_nug = new QLabel("Chicken Nuggets");
    QLabel *price = new QLabel("$0.99");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(chick_nug);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *honey_mustard_button = new QPushButton("Honey Mustard");
    QPushButton *sweet_sour_button = new QPushButton("Sweet and Sour Sauce");
    QPushButton *ketchup_button = new QPushButton("Ketchup");
    QPushButton *mustard_button = new QPushButton("Mustard");
    QPushButton *bbq_button = new QPushButton("Barbeque");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *medium_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(honey_mustard_button);
    set_button_style(sweet_sour_button);
    set_button_style(ketchup_button);
    set_button_style(mustard_button);
    set_button_style(bbq_button);
    set_button_style(small_button);
    set_button_style(medium_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(honey_mustard_button);
    ui->gridLayout2->addWidget(sweet_sour_button);
    ui->gridLayout3->addWidget(ketchup_button);
    ui->gridLayout4->addWidget(mustard_button);
    ui->gridLayout5->addWidget(bbq_button);
    ui->gridLayout6->addWidget(small_button);
    ui->gridLayout7->addWidget(medium_button);
    ui->gridLayout8->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_salad_button_clicked()
{
    // Add the salad item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *salad = new QLabel("Salad");
    QLabel *price = new QLabel("$2.99");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(salad);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *broccoli_button = new QPushButton("Broccoli");
    QPushButton *tomatoe_button = new QPushButton("Tomatoes");
    QPushButton *carot_button = new QPushButton("Carots");
    QPushButton *onion_button = new QPushButton("Onions");
    QPushButton *olive_button = new QPushButton("Olive");
    QPushButton *cucumber_button = new QPushButton("Cucumbers");
    QPushButton *egg_button = new QPushButton("Eggs");
    QPushButton *corn_button = new QPushButton("Corn");
    QPushButton *cheese_button = new QPushButton("Cheese");
    QPushButton *chickpea_button = new QPushButton("Chickpeas");
    QPushButton *almond_button = new QPushButton("Almonds");
    QPushButton *crouton_button = new QPushButton("Croutons");
    QPushButton *chicken_button = new QPushButton("Chicken");
    QPushButton *bacon_button = new QPushButton("Bacon");
    QPushButton *oil_button = new QPushButton("Olive Oil");
    QPushButton *ranch_button = new QPushButton("Ranch");
    QPushButton *vinaigrette_button = new QPushButton("Vinaigrette");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *med_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(bacon_button);
    set_button_style(cheese_button);
    set_button_style(broccoli_button);
    set_button_style(tomatoe_button);
    set_button_style(corn_button);
    set_button_style(onion_button);
    set_button_style(olive_button);
    set_button_style(cucumber_button);
    set_button_style(egg_button);
    set_button_style(chickpea_button);
    set_button_style(almond_button);
    set_button_style(crouton_button);
    set_button_style(chicken_button);
    set_button_style(oil_button);
    set_button_style(ranch_button);
    set_button_style(vinaigrette_button);
    set_button_style(carot_button);
    set_button_style(small_button);
    set_button_style(med_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(bacon_button);
    ui->gridLayout2->addWidget(cheese_button);
    ui->gridLayout3->addWidget(broccoli_button);
    ui->gridLayout4->addWidget(tomatoe_button);
    ui->gridLayout5->addWidget(corn_button);
    ui->gridLayout6->addWidget(onion_button);
    ui->gridLayout7->addWidget(olive_button);
    ui->gridLayout8->addWidget(cucumber_button);
    ui->gridLayout9->addWidget(egg_button);
    ui->gridLayout10->addWidget(chickpea_button);
    ui->gridLayout11->addWidget(almond_button);
    ui->gridLayout12->addWidget(crouton_button);
    ui->gridLayout13->addWidget(chicken_button);
    ui->gridLayout14->addWidget(oil_button);
    ui->gridLayout15->addWidget(ranch_button);

    //Not enough room for all salad options
//    ui->gridLayout16->addWidget(vinaigrette_button);
//    ui->gridLayout17->addWidget(carot_button);
//    ui->gridLayout18->addWidget(small_button);
//    ui->gridLayout19->addWidget(med_button);
//    ui->gridLayout20->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_fries_button_clicked()
{
    // Add the fries item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *fries = new QLabel("Fries");
    QLabel *price = new QLabel("$0.99");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(fries);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *bacon_button = new QPushButton("Bacon");
    QPushButton *cheese_button = new QPushButton("Cheese");
    QPushButton *chili_button = new QPushButton("Chili");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *med_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(bacon_button);
    set_button_style(cheese_button);
    set_button_style(chili_button);
    set_button_style(small_button);
    set_button_style(med_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(bacon_button);
    ui->gridLayout2->addWidget(cheese_button);
    ui->gridLayout3->addWidget(chili_button);
    ui->gridLayout11->addWidget(small_button);
    ui->gridLayout12->addWidget(med_button);
    ui->gridLayout13->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_soda_button_clicked()
{
    // Add the soda item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *soda = new QLabel("Soda");
    QLabel *price = new QLabel("$0.99");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(soda);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *cherry_button = new QPushButton("Cherry");
    QPushButton *cola_button = new QPushButton("Cola");
    QPushButton *ginger_ale_button = new QPushButton("Ginger Ale");
    QPushButton *grape_button = new QPushButton("Grape");
    QPushButton *lemon_lime_button = new QPushButton("Lemon-Lime");
    QPushButton *orange_button = new QPushButton("Orange");
    QPushButton *root_beer_button = new QPushButton("Root Beer");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *medium_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(cherry_button);
    set_button_style(cola_button);
    set_button_style(ginger_ale_button);
    set_button_style(grape_button);
    set_button_style(lemon_lime_button);
    set_button_style(orange_button);
    set_button_style(root_beer_button);
    set_button_style(small_button);
    set_button_style(medium_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(cherry_button);
    ui->gridLayout2->addWidget(cola_button);
    ui->gridLayout3->addWidget(ginger_ale_button);
    ui->gridLayout4->addWidget(grape_button);
    ui->gridLayout5->addWidget(lemon_lime_button);
    ui->gridLayout6->addWidget(orange_button);
    ui->gridLayout7->addWidget(root_beer_button);
    ui->gridLayout8->addWidget(small_button);
    ui->gridLayout9->addWidget(medium_button);
    ui->gridLayout10->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tea_button_clicked()
{
    // Add the tea item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *tea = new QLabel("Tea");
    QLabel *price = new QLabel("$0.75");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(tea);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *cherry_button = new QPushButton("Cherry");
    QPushButton *green_button = new QPushButton("Green");
    QPushButton *lemon_button = new QPushButton("Lemon");
    QPushButton *peach_button = new QPushButton("Peach");
    QPushButton *strawberry_button = new QPushButton("Strawberry");
    QPushButton *sweet_button = new QPushButton("Sweet");
    QPushButton *unsweet_button = new QPushButton("Unsweet");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *medium_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(cherry_button);
    set_button_style(green_button);
    set_button_style(lemon_button);
    set_button_style(peach_button);
    set_button_style(strawberry_button);
    set_button_style(sweet_button);
    set_button_style(unsweet_button);
    set_button_style(small_button);
    set_button_style(medium_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(cherry_button);
    ui->gridLayout2->addWidget(green_button);
    ui->gridLayout3->addWidget(lemon_button);
    ui->gridLayout4->addWidget(peach_button);
    ui->gridLayout5->addWidget(strawberry_button);
    ui->gridLayout6->addWidget(sweet_button);
    ui->gridLayout7->addWidget(unsweet_button);
    ui->gridLayout8->addWidget(small_button);
    ui->gridLayout9->addWidget(medium_button);
    ui->gridLayout10->addWidget(large_button);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_milk_shake_button_clicked()
{
    // Add the milkshake item to the scroll box.
    // This will be set as a signal/slot on order when I get
    // the order class converted to using Qt.
    QPushButton *remove_button = new QPushButton("X");
    remove_button->setStyleSheet("color:white;background-color:red;max-width: 20px");
    QLabel *milkshake = new QLabel("Milkshake");
    QLabel *price = new QLabel("$2.99");
    QHBoxLayout *item_line = new QHBoxLayout();
    item_line->addWidget(remove_button);
    item_line->addWidget(milkshake);
    item_line->addWidget(price);
    ui->scroll_layout->addLayout(item_line);

    // Create the topping buttons.
    // This is a messy way, a better way would be to create a factory.
    // I'll work on that towards the end if we have time.
    QPushButton *cherry_button = new QPushButton("Cherry");
    QPushButton *whipped_cream_button = new QPushButton("Whipped Cream");
    QPushButton *chocolate_button = new QPushButton("Chocolate");
    QPushButton *vanilla_button = new QPushButton("Vanilla");
    QPushButton *strawberry_button = new QPushButton("Strawberry");
    QPushButton *small_button = new QPushButton("Small");
    QPushButton *medium_button = new QPushButton("Medium");
    QPushButton *large_button = new QPushButton("Large");

    // Set the style and make the button checkable.
    set_button_style(cherry_button);
    set_button_style(whipped_cream_button);
    set_button_style(chocolate_button);
    set_button_style(vanilla_button);
    set_button_style(strawberry_button);
    set_button_style(small_button);
    set_button_style(medium_button);
    set_button_style(large_button);

    // Add the button to the page.
    ui->gridLayout->addWidget(cherry_button);
    ui->gridLayout2->addWidget(whipped_cream_button);
    ui->gridLayout3->addWidget(chocolate_button);
    ui->gridLayout4->addWidget(vanilla_button);
    ui->gridLayout5->addWidget(strawberry_button);
    ui->gridLayout8->addWidget(small_button);
    ui->gridLayout9->addWidget(medium_button);
    ui->gridLayout10->addWidget(large_button);

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
