#include "Item.h"

class Drinks: public Item
{
private:
	bool IceIce;
public:
	Drinks();
	bool hasIce(bool IceIce);
};
