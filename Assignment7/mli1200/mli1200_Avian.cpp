#include "mli1200_Avian.h"

std::string Avian::act()
{
	std::cout << name << " " << "flys" << std::endl;
}

std::string Avian::to_string()
{
	std::ostringstream oss;
	oss << name << " " << id_number << " " << gender << " " << age << " " << health_status << " " << type;
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Avian& avian)
{
	ost << "Name: " << avian.name << " ID#: " << avian.id_number << " Gender: " << avian.gender << " Age: " << avian.age << " Health: " << avian.health_status << " Type: " << avian.type << " Species: " << avian.species;
	return ost;
}