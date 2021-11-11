#pragma once
#include "mli1200_Animal.h"

class Avian : public virtual Animal
{
public:
	Avian(std::string n = "shannon", int id = 4, bool g = 1, int a = 43, std::string hs = "Good", std::string t = "Bird", std::string s = "Avian") : Animal(n, id, g, a, hs, t, s) {};
	std::string fly();
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& ost, const Avian& avian);
private:

};