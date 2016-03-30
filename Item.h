#pragma once

#include <string>
#include "Order.h"

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
	Item(); //default constructor declaration

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
};