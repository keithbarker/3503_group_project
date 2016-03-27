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

void Order::printReceipt(Item &items, const double tax, double subtotal, double total) {

}

void Order::addItem(Item &toBeAdded) {

}

void Order::removeItem(Item &toBeRemoved) {



}

void Order::findSubtotal() {

	
}

void Order::findTotal() {
	


}