#pragma once

#include "Item.h"
#include <vector>
#include <QObject>
using namespace std;

class Order : public QObject
{
    Q_OBJECT
	const double tax = 0.06;
	double subtotal;
	double total;

public:
    vector<Item*> *itemArray;	//dynamic vector for items (easier to add and remove with vector)

	Order();	//default order constructor called immediately after starting new order

	double getTax();

    void setSubtotal(double subtotal);
	double getSubtotal();

	void setTotal(double total);
	double getTotal();

	void printReceipt();
    void addItem(Item *toBeAdded);	// add food or drink to item array
    void removeItem(int id);	//remove food or drink from item array

	void findSubtotal();	//calculates subtotal based on price of each item in array
	void findTotal();	//calculate total from tax and subtotal
    int getItemCount();

    void clearOrder();

public slots:

signals:
    void itemsChanged();
};
