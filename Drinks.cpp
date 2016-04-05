#include <iostream>
#include "Drinks.h"
#include "Item.h"
#include <string>

using namespace std;

//call this constructor with appropriate arguments when buying type of drink (Drink constructor calls Item constructor)
Drinks::Drinks(int itemsLeft, double price, string name, string description, string size, string flavor, int quantity)
    :Item(itemsLeft,price,name,description,size,flavor,quantity){}


bool Drinks::hasIce(){
    return IceIce;
}

void Drinks::setIce(){  //when function called on drink, switches boolean of ice
    if(IceIce){
        this->IceIce = false;
    }
    else if (IceIce == false){
        this->IceIce = true;
    }
}
