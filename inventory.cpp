#include "inventory.h"

Inventory::Inventory(){
     hamburgerCount = 100;
     hotdogCount = 100;
     chickensandwichCount = 100;
     chickennuggetCount = 100;
     saladCount = 100;
     friesCount = 100;\
     sodaCount = 100;
     teaCount = 100;
     shakeCount = 100;
}

void Inventory::addCount(std::string countName){


}

void Inventory::updateInventory(){  //call only after order completed

     for (auto const& item : itemArray){
         if(item->getName() == "Hamburger"){
            --hamburgerCount;
         }
         else if(item->getName() == "Hotdog"){
            --hotdogCount;
         }
         else if(item->getName() == "Chicken Sandwich"){
             --chickensandwichCount;
         }
         else if(item->getName() == "Chicken Nuggets"){
             --chickennuggetCount;
         }
         else if(item->getName() == "Salad"){
             --saladCount;
         }
         else if(item->getName() == "Fries"){
             --friesCount;
         }
         else if(item->getName() == "Soda"){
             --sodaCount;
         }
         else if(item->getName() == "Tea"){
             --teaCount;
         }
         else if(item->getName() == "Milkshake"){
             --shakeCount;
         }
     }
}

void Inventory::setHamburgerCount(int count)
{
    this->hamburgerCount = count;
}

int Inventory::getHamburgerCount()
{
    return this->hamburgerCount;
}

void Inventory::setHotdogCount(int count)
{
    this->hotdogCount = count;
}

int Inventory::getHotdogCount()
{
    return this->hotdogCount;
}

void Inventory::setChickenSandwichCount(int count)
{
    this->chickensandwichCount = count;
}

int Inventory::getChickenSandwichCount()
{
    return this->chickensandwichCount;
}

void Inventory::setChickenNuggetCount(int count)
{
    this->chickennuggetCount = count;
}

int Inventory::getChickenNuggetCount()
{
    return this->chickennuggetCount;
}

void Inventory::setSaladCount(int count)
{
    this->saladCount = count;
}

int Inventory::getSaladCount()
{
    return this->saladCount;
}

void Inventory::setFriesCount(int count)
{
    this->friesCount = count;
}

int Inventory::getFriesCount()
{
    return this->friesCount;
}

void Inventory::setSodaCount(int count)
{
    this->sodaCount = count;
}

int Inventory::getSodaCount()
{
    return this->sodaCount;
}

void Inventory::setTeaCount(int count)
{
    this->teaCount = count;
}

int Inventory::getTeaCount()
{
    return this->teaCount;
}

void Inventory::setMilkshakeCount(int count)
{
    this->shakeCount = count;
}

int Inventory::getMilkshakeCount()
{
    return this->shakeCount;
}
