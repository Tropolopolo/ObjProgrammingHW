#include "mli1200_Amphibious.h"

std::string Amphibious::to_string()
{
	std::ostringstream oss;
	oss << name << " " << id_number << " " << gender << " " << age << " " << health_status << " " << type << " " << species;
	return oss.str();
}

std::string Amphibious::act()
{
	std::string a;
	a = Aquatic::act() + "and " + Terrestrial::act();
	return a;
}

std::ostream& operator<<(std::ostream& ost, const Amphibious& amphibious)
{
	ost << "Name: " << amphibious.name << " ID#: " << amphibious.id_number << " Gender: " << amphibious.gender << " Age: " << amphibious.age << " Health: " << amphibious.health_status << " Type: " << amphibious.type << " Species: " << amphibious.species;
	return ost;
}