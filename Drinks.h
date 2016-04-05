#include "Item.h"

class Drinks: public Item
{
private:
    bool IceIce = false;    //default drink has no ice
public:
    Drinks();
    Drinks(int itemsLeft, double price, string name, string description, string size, string flavor, int quantity);
    bool hasIce();
    void setIce();
};
