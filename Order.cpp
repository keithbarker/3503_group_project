#include "Order.h"

Order::Order(){
	this->subtotal = 0;
	this->total = 0;
}

double Order::getTax() {
	return tax;
}

void Order::setSubtotal(double subtotal) {
	this->subtotal = subtotal
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

void Order::addItem(Item &toBeAdded) {
	for (int i = 0; i < itemArray.size(); ++i) {
		if () {	//if item already in array increase quantity of item



		}
	}

}

void Order::removeItem(Item &toBeRemoved) {



}

void Order::findSubtotal() {
	double tempSubtotal = 0;	//temp counter
	for (int i = 0; i < itemArray.size(); ++i) {
		if (itemArray.at(i) != NULL) {
			tempSubtotal += itemArray.at(i).getPrice();
		}
	}
	subtotal = tempSubtotal;
}

void Order::findTotal() {
	total = subtotal + (subtotal * tax);
}