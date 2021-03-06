#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() //default constructor (set values using setters)
{
    this->itemsLeft = 100; //defaulted to 100 items left
    this->price = 1.00; //default price of $1
    this->description = ""; /*all strings are initially set to null
    remember to change them if a food or drink item has one of these attributes.

 ***ALL ITEMS SHOULD HAVE NAME AND DESCRIPTIONS***
                                                             */
    this->name = "";
    this->size = "";
    this->flavor = "";
    this->quantity = 1; //defaulted to 1 item for the order
    this->requested_extras;
    this->allowed_extras;
}

//Item initializer list
Item::Item(int itemsLeft, double price, string name, string description, string size, string flavor, int quantity)
    : itemsLeft(itemsLeft), price(price), name(name), description(description), size(size), flavor(flavor), quantity(quantity){}

void Item::setItemsLeft(int itemsLeft) //set items left
{
	this->itemsLeft = itemsLeft;
}

int Item::getItemsLeft() //get items left
{
	return itemsLeft;
}

void Item::setPrice(double price) //set price
{
	this->price = price;
}

double Item::getPrice() //get price
{
	return price;
}

void Item::setDescription(std::string description) //set description
{
	this->description = description;
}

std::string Item::getDescription() //get description
{
	return description;
}

void Item::setName(std::string name) //set name
{
	this->name = name;
}

std::string Item::getName() //get name
{
	return name;
}

void Item::setSize(std::string size) //set size
{
	this->size = size;
}

std::string Item::getSize() //get size
{
	return size;
}

void Item::setFlavor(std::string flavor) //set flavor
{
	this->flavor = flavor;
}

std::string Item::getFlavor() //get flavor
{
	return flavor;
}

void Item::increaseQuantity() //set quantity
{
    this->quantity = this->quantity + 1;
}

void Item::decreaseQuantity()
{
    this->quantity = this->quantity - 1;
}

int Item::getQuantity() //get quantity
{
	return quantity;
}

void Item::addExtra(string extra)
{
    if (find(requested_extras.begin(), requested_extras.end(), extra) == requested_extras.end())
    {
        this->requested_extras.push_back(extra);
    }
}

string Item::getExtras()
{
    string extras = "Extras: ";
    for (auto const& s : requested_extras){
        extras += s;
        extras += ", ";
    }
    extras.pop_back();
    extras.pop_back();
    return extras;
}

void Item::removeExtra(string extra)
{
    vector<string>::iterator extra_it = find(requested_extras.begin(), requested_extras.end(), extra);

    if (extra_it != requested_extras.end())
    {
        requested_extras.erase(extra_it);
    }
}

void Item::addAllowedExtras(vector<string> extras)
{
    this->allowed_extras = extras;
}
