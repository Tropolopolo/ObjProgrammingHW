#pragma once
#include "mli1200_Aquatic.h"
#include "mli1200_Terrestrial.h"

class Amphibious : public Aquatic, public Terrestrial
{
public:
	Amphibious(std::string n = "adam", int id = 5, bool g = 1, int a = 43, std::string hs = "Good", std::string t = "Frog", std::string s = "Amphibious") : Animal(n, id, g, a, hs, t, s) {};
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& ost, const Amphibious& amphibious);
};