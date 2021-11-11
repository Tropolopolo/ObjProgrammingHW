#include "mli1200_Animal.h"

std::string Animal::get_name() const
{
	return name;
}

int Animal::get_id_number() const
{
	return id_number;
}

bool Animal::get_gender() const
{
	return gender;
}

int Animal::get_age() const
{
	return age;
}

std::string Animal::get_health_status() const
{
	return health_status;
}

std::string Animal::get_type() const
{
	return type;
}

std::string Animal::get_species() const
{
	return species;
}

void Animal::set_name(std::string n)
{
	name = n;
}

void Animal::set_id_number(int id)
{
	id_number = id;
}

void Animal::set_gender(bool g)
{
	gender = g;
}

void Animal::set_age(int a)
{
	age = a;
}

void Animal::set_health_status(std::string hs)
{
	health_status = hs;
}

void Animal::set_type(std::string t)
{
	type = t;
}

void Animal::set_species(std::string s)
{
	species = s;
}

std::string Animal::to_string() const
{
	/*		-Removed in program 7
	std::ostringstream oss;
	oss << name << " " << id_number << " " << gender << " " << age << " " << health_status << " " << type << " " << species;
	return oss.str();
	*/
}

std::string Animal::act() {}

/*		-Removed in program 7
std::ostream& operator<<(std::ostream& ost, const Animal& animal)
{
	ost << "Name: " << animal.name <<" ID#: " << animal.id_number << " Gender: " << animal.gender << " Age: " << animal.age << " Health: " << animal.health_status << " Type: " << animal.type << " Species: " << animal.species;
	return ost;
}
*/

bool Animal::operator==(Animal a) const
{
	return id_number == a.id_number;
}
