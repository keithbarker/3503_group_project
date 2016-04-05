#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>

class Food : public Item{

public:
    Food(int itemsLeft, double price, string name, string description, string size, string flavor, int quantity);

};


#endif // FOOD_H
