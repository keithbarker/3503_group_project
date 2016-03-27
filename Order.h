#pragma once

#include "Item.h"

class Order {
	const double tax = 0.06;
	double subtotal;
	double total;
	Item *items = new Item[50](NULL);	//dynamic array for items that should initialize everything to null(have not tested yet)

public:
	Order();	//default order constructor called immediately after starting new order

	double getTax();

	void setSubtotal(double subtotal);
	double getSubtotal();

	void setTotal(double total);
	double getTotal();

	void printReceipt(Item &items, const double tax, double subtotal, double total);
	void addItem(Item &toBeAdded);	// add food or drink to item array
	void removeItem(Item &toBeRemoved);	//remove food or drink from item array
	void findSubtotal();	//calculates subtotal based on price of each item in array
	void findTotal();	//calculate total from tax and subtotal

};