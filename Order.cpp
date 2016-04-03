#include "Order.h"

Order::Order(){
	this->subtotal = 0;
	this->total = 0;
}

double Order::getTax() {
	return tax;
}

void Order::setSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Order::getSubtotal() {
	return subtotal;
}

void Order::setTotal(double total) {
	this->total = total;
}

double Order::getTotal() {
	return total;
}

void Order::printReceipt() {
	// need to know how gui works in order to implement
}

// TODO: Come back to this section to add items.
//void Order::addItem(Item &toBeAdded) {
    //for (int i = 0; i < itemArray.size(); ++i) {
    //	if () {	//if item already in array increase quantity of item



    //	}
    //}

//}

// TODO: Come back to this section to remove items.
//void Order::removeItem(Item &toBeRemoved) {
//}

void Order::findSubtotal() {
	double tempSubtotal = 0;	//temp counter
    for (unsigned int i = 0; i < itemArray.size(); ++i) {
        // If check not necessary, since vector::size() returns
        // the number of indexes with items in it.
        tempSubtotal += itemArray.at(i).getPrice();
	}
	subtotal = tempSubtotal;
}

void Order::findTotal() {
	total = subtotal + (subtotal * tax);
}
