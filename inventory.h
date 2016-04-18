#ifndef INVENTORY_H
#define INVENTORY_H

#include "Order.h"


class Inventory : public Order{
    int hamburgerCount;
    int hotdogCount;
    int chickensandwichCount;
    int chickennuggetCount;
    int saladCount;
    int friesCount;
    int sodaCount;
    int teaCount;
    int shakeCount;

public:
    Inventory();
    void updateInventory();
    void addCount(std::string countName);
};


#endif // INVENTORY_H
