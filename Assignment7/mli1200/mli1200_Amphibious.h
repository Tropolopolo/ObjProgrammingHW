#pragma once
#include "mli1200_Aquatic.h"
#include "mli1200_Terrestrial.h"

class Amphibious : public Aquatic, public Terrestrial
{
public:
	Amphibious(std::string n = "adam", int id = 5, bool g = 1, int a = 43, std::string hs = "Good", std::string t = "Amphibious", std::string s = "Frog") : Animal(n, id, g, a, hs, t, s) {};
	std::string to_string();
	std::string act();
	friend std::ostream& operator<<(std::ostream& ost, const Amphibious& amphibious);
};