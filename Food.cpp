#include <iostream>
#include <string>

class Food
{
	protected:
		std::string name, description;
		double price;
	public:
		Food(std::string s1, std::string s2, double n) : name(s1), description(s2), price(n) {}
};

class Print
{
	public:
		void print(std::string s1, std::string s2, double n);
};

void Print::print(std::string s1, std::string s2, double n)
{
	std::cout << s1 << ", " << s2 << ", " << n << '\n';
}

class Burger: public Food, public Print
{
	public:
		Burger(std::string s1, std::string s2, double n) : Food(s1, s2, n) {}
		std::string str1 ()
			{ return name; }
		std::string str2 ()
			{ return description; }
		double num ()
			{ return price; }
	
};

class Fries: public Food, public Print
{
	public:
		Fries(std::string s1, std::string s2, double n) : Food(s1, s2, n) {}
		std::string str1 ()
			{ return name; }
		std::string str2 ()
			{ return description; }
		double num ()
			{ return price; }
};

class Hotdog: public Food, public Print
{
	public:
		Hotdog(std::string s1, std::string s2, double n) : Food(s1, s2, n) {}
		std::string str1 ()
			{ return name; }
		std::string str2 ()
			{ return description; }
		double num ()
			{ return price; }
};

class Nuggets: public Food, public Print
{
	public:
		Nuggets(std::string s1, std::string s2, double n) : Food(s1, s2, n) {}
		std::string str1 ()
			{ return name; }
		std::string str2 ()
			{ return description; }
		double num ()
			{ return price; }
	
};

class Chicken: public Food, public Print
{
	public:
		Chicken(std::string s1, std::string s2, double n) : Food(s1, s2, n) {}
		std::string str1 ()
			{ return name; }
		std::string str2 ()
			{ return description; }
		double num ()
			{ return price; }
	
};

class Salad: public Food, public Print
{
	public:
		Salad(std::string s1, std::string s2, double n) : Food(s1, s2, n) {}
		std::string str1 ()
			{ return name; }
		std::string str2 ()
			{ return description; }
		double num ()
			{ return price; }
	
};

//int main()
//{
//	Burger burger("Hamburger", "USDA Prime Beef", 3.99);
//	burger.print(burger.str1(), burger.str2(), burger.num());
//	Fries fries("French Fries", "Hand-cut with a dash of sea salt", 0.99);
//	fries.print(fries.str1(), fries.str2(), fries.num());
//	// DON'T USE THE DESCRIPTION BELOW
//	Hotdog hotdog("Hotdog", "Kosher, so you can gobble that meaty sausage without shaming your rabbi", 1.25);
//	hotdog.print(hotdog.str1(), hotdog.str2(), hotdog.num());
//	return 0;
//}
