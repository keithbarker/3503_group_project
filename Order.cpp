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

void Order::addItem(Item &toBeAdded){
    bool alreadyInArray = false;
    //first determine if instance of object already in Item Array
    for(unsigned int i = 0; i < itemArray.size(); ++i){
        // if statement may have to be changed to accomodate for
        // items with different toppings but same food type being added
        // currently only checks if name of item to add is same
        // as one already in array
        if(itemArray[i].getName() == toBeAdded.getName()){
            //quantity of item in array increased
            alreadyInArray = true;
            itemArray[i].increaseQuantity();
            break;
        }
    }
    if(!alreadyInArray){    //if item not in array yet
        itemArray.push_back(toBeAdded);

    }
}
