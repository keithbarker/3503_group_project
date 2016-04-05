#pragma once

#include <string>
using namespace std;


class Item
{

private:
    int itemsLeft;
	double price;
    string name;
    string description;
    string size;
    string flavor;
	int quantity;

public:
	Item(); //default constructor declaration

    //constructor called when instance of Food or Drink is created
    Item(int itemsLeft, double price, string name, string description, string size, string flavor, int quantity);

	/*getters and setter
	methods declaration*/

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

	void setQuantity(int quantity);
	int getQuantity();
};
