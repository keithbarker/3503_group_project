#pragma once

#include <string>
#include <QObject>
using namespace std;


class Item : public QObject
{

private:
    Q_OBJECT
    int id;
    int itemsLeft;
	double price;
    string name;
    string description;
    string size;
    string flavor;
	int quantity;
    vector<string> requested_extras; // Used to store selected "toppings".
    vector<string> allowed_extras; // Used to store list of allowed "toppings".

public:
    Item(); //default constructor declaration

    //constructor called when instance of Food or Drink is created
    Item(int id, int itemsLeft, double price, string name, string description, string size, string flavor, int quantity);

	/*getters and setter
	methods declaration*/

    void setId(int id);
    int getId();

	void setItemsLeft(int itemsLeft);
	int getItemsLeft();

	void setPrice(double price);
	double getPrice();

    void setDescription(string description);
    string getDescription();

    void setName(string name);
    string getName();

    void setSize(string size);
    string getSize();

    void setFlavor(string flavor);
    string getFlavor();

    void increaseQuantity();
    void decreaseQuantity();
	int getQuantity();
};
