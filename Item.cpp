#include <string>

class Item
{

private:
	int itemsLeft
	double price;
	std::string description;
	std::string name;
	std::string size;
	std:string flavor;
	int quantity;

public:

	/*getters and setter
		methods declaration*/

	void setItemsLeft(int itemsLeft);
	int getItemsLeft();

	void setPrice(double price);
	double getPrice();

	void setDescription(std::string description);
	std::string getDescription();

	void setName(std::string name);
	std::string getName();

	void setSize(std::string size);
	std::string getSize();

	void setFlavor(std::String flavor);
	std::string getFlavor();

	void setQuantity(int quantity);
	int getQuantity();

	Item(); //default constructor declaration
};

Item::Item() //default constructor (set values using setters)
{
	this->itemsLeft = 100; //defaulted to 100 items left
	this->price = 1.00 //default price of $1
	this->description = "null"; /*all strings are initially set to null
															 remember to change them if a food or drink item
															 has one of these attributes.

															 ***ALL ITEMS SHOULD HAVE NAME AND DESCRIPTIONS***
															 */
	this->name = "null";
	this->size = "null";
	this->flavor = "null";
	this->quantity = 1; //defaulted to 1 item for the order
}

void setItemsLeft(int itemsLeft) //set items left
{
	this->itemsLeft = itemsLeft;
}

int getItemsLeft() //get items left
{
	return itemsLeft;
}

void setPrice(double price) //set price
{
	this->price = price;
}

double getPrice() //get price
{
	return price;
}

void setDescription(std::string description) //set description
{
	this->description = description;
}

std::string getDescription() //get description
{
	return description;
}

void setName(std::string name) //set name
{
	this->name = name;
}

std::string getName() //get name
{
	return name;
}

void setSize(std::string size) //set size
{
	this->size = size;
}

std::string getSize() //get size
{
	return size;
}

void setFlavor(std::string flavor) //set flavor
{
	this->flavor = flavor;
}

std::string getFlavor() //get flavor
{
	return flavor;
}

void setQuantity(int quantity) //set quantity
{
	this->quantity = quantity;
}

int getQuantity() //get quantity
{
	return quantity;
}
