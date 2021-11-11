#include "mli1200_Terrestrial.h"

std::string Terrestrial::walk()
{
	std::cout << name << " " << "walks" << std::endl;
}

std::string Terrestrial::to_string()
{
	std::ostringstream oss;
	oss << name << " " << id_number << " " << gender << " " << age << " " << health_status << " " << type;
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Terrestrial& terrestrial)
{
	ost << "Name: " << terrestrial.name << " ID#: " << terrestrial.id_number << " Gender: " << terrestrial.gender << " Age: " << terrestrial.age << " Health: " << terrestrial.health_status << " Type: " << terrestrial.type << " Species: " << terrestrial.species;
	return ost;
}