#pragma once

#include "Item.h"
#include <vector>

class Order {
	const double tax = 0.06;
	double subtotal;
	double total;
	std::vector<Item> itemArray;	//dynamic vector for items (easier to add and remove with vector)

public:
	Order();	//default order constructor called immediately after starting new order

	double getTax();

	void setSubtotal(double subtotal);
	double getSubtotal();

	void setTotal(double total);
	double getTotal();

	void printReceipt();
	void addItem(Item &toBeAdded);	// add food or drink to item array
	void removeItem(Item &toBeRemoved);	//remove food or drink from item array
	void findSubtotal();	//calculates subtotal based on price of each item in array
	void findTotal();	//calculate total from tax and subtotal

};