#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include "Item.h"

class Food : public Item{

public:
    Food();
    Food(int itemsLeft, double price, string name, string description, string size, string flavor, int quantity);

};


#endif // FOOD_H
