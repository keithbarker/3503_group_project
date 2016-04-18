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

    void setHamburgerCount(int count);
    int getHamburgerCount();

    void setHotdogCount(int count);
    int getHotdogCount();

    void setChickenSandwichCount(int count);
    int getChickenSandwichCount();

    void setChickenNuggetCount(int count);
    int getChickenNuggetCount();

    void setSaladCount(int count);
    int getSaladCount();

    void setFriesCount(int count);
    int getFriesCount();

    void setSodaCount(int count);
    int getSodaCount();

    void setTeaCount(int count);
    int getTeaCount();

    void setMilkshakeCount(int count);
    int getMilkshakeCount();


};


#endif // INVENTORY_H
