#pragma once
#include "mli1200_Animal.h"

class Aquatic : public virtual Animal
{
public:
	Aquatic(std::string n = "britt", int id = 3, bool g = 1, int a = 25, std::string hs = "Good", std::string t = "Fish", std::string s = "Aquatic") : Animal(n, id, g, a, hs, t, s) {};
	std::string swim();
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& ost, const Aquatic& aquatic);
};