#include "Order.h"

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
    // IMO no need to check if the item already exists.
    // Let them add however many hamburgers they want and I don't think
    // there is a way to add the same exact item twice.
    itemArray->push_back(toBeAdded);
    emit itemsChanged();
//    bool alreadyInArray = false;
//    //first determine if instance of object already in Item Array
//    for(unsigned int i = 0; i < itemArray.size(); ++i){
//        // if statement may have to be changed to accomodate for
//        // items with different toppings but same food type being added
//        // currently only checks if name of item to add is same
//        // as one already in array
//        if(itemArray[i].getName() == toBeAdded.getName()){
//            //quantity of item in array increased
//            alreadyInArray = true;
//            itemArray[i].increaseQuantity();
//            break;
//        }
//    }
//    if(!alreadyInArray){    //if item not in array yet
//        itemArray.push_back(toBeAdded);

//    }
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
