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
