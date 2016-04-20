#include "Order.h"
#include <cmath>

Order::Order(){
	this->subtotal = 0;
	this->total = 0;
    this->itemArray = new vector<Item*>();
}

double Order::getTax() {
	return tax;
}

void Order::setSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Order::getSubtotal() {
    findSubtotal();
    return subtotal;
}

void Order::setTotal(double total) {
	this->total = total;
}

double Order::getTotal() {
    findTotal();
    double fixed_total = pow(10, 2);
    return ((int)(total*fixed_total))/fixed_total;
}

void Order::removeItem(int index) {
    vector<Item*>::iterator it;
    itemArray->erase(itemArray->begin() + index);
    emit itemsChanged();
}

void Order::findSubtotal() {
	double tempSubtotal = 0;	//temp counter
    for (unsigned int i = 0; i < itemArray->size(); ++i) {
        // If check not necessary, since vector::size() returns
        // the number of indexes with items in it.
        tempSubtotal += itemArray->at(i)->getPrice();
	}
	subtotal = tempSubtotal;
}

void Order::findTotal() {
	total = subtotal + (subtotal * tax);
}

void Order::addItem(Item *toBeAdded){
    itemArray->push_back(toBeAdded);
    emit itemsChanged();
}

int Order::getItemCount() {
    if (itemArray != NULL && !itemArray->empty()) {
        return itemArray->size();
    }
    return 0;
}

 void Order::clearOrder(){
     itemArray->clear();
     this->subtotal = 0;
     this->total = 0;
    emit itemsChanged();
 }
