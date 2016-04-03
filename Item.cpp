#include "Item.h"

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
}

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

void Item::setQuantity(int quantity) //set quantity
{
	this->quantity = quantity;
}

int Item::getQuantity() //get quantity
{
	return quantity;
}
