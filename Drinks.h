#include "Item.h"

class Drinks: public Item
{
private:
    bool IceIce = false;    //default drink has no ice
public:
	Drinks();
    bool hasIce();
    void setIce();
};
