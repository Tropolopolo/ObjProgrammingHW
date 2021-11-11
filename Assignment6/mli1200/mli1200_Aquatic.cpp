#include "mli1200_Aquatic.h"

std::string Aquatic::swim()
{
	std::cout << name << " " << "swims" << std::endl;
}

std::string Aquatic::to_string()
{
	std::ostringstream oss;
	oss << name << " " << id_number << " " << gender << " " << age << " " << health_status << " " << type;
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Aquatic& aquatic)
{
	ost << "Name: " << aquatic.name << " ID#: " << aquatic.id_number << " Gender: " << aquatic.gender << " Age: " << aquatic.age << " Health: " << aquatic.health_status << " Type: " << aquatic.type << " Species: " << aquatic.species;
	return ost;
}