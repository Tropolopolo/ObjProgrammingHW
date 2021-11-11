#pragma once
#include "mli1200_Animal.h"

class Terrestrial : public virtual Animal
{
public:
	Terrestrial(std::string n = "caleb", int id = 2, bool g = 1, int a = 21, std::string hs = "Good", std::string t = "Terrestrial", std::string s = "Dog") : Animal(n, id, g, a, hs, t, s) {};
	std::string act();
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& ost, const Terrestrial& terrestrial);
};