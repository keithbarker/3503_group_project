#include <iostream>
#include "Drinks.h"
#include "Item.h"
#include <string>

using namespace std;
Drinks::Drinks(){
this->IceIce=false;
}

Drinks::hasIce(bool IceIce){
this->IceIce=IceIce;
return IceIce;
}