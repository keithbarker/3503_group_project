#include <iostream>
#include "Drinks.h"
#include "Item.h"
#include <string>

using namespace std;
Drinks::Drinks(){

}

Drinks::hasIce(){
bool IceIce=false;
cout<<"Would you like ice(Yes or No)?"
string ice;
cin>>ice;
if(ice==yes||ice==Yes){
	IceIce=true;
}
return IceIce;
}