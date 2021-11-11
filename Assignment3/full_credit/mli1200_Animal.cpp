//Matthew Irvine 1001401200

#include "mli1200_Animal.h"

Animal::Animal()	
{
	name = "Default";
	id_number = 0;
	gender = false;
	age = 0;
	health_status = "Default";
}

Animal::Animal(std::string n, int id, bool g, int a, std::string hs)
{
	name = n;
	id_number = id;
	gender = g;
	age = a;
	health_status = hs;
}

std::string Animal::get_name()
{
	return name;
}

int Animal::get_id()
{
	return id_number;
}

bool Animal::get_gender()
{
	return gender;
}

int Animal::get_age()
{
	return age;
}

std::string Animal::get_health_status()
{
	return health_status;
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

std::string Animal::to_string() const
{
	std::string s;
	s += name + " " + std::to_string(id_number) + " " + std::to_string(gender) + " " + std::to_string(age) + " " + health_status;
	return s;
}

std::ostream& operator<<(std::ostream& ost, const Animal& animal)
{
	ost << "Name: " << animal.name << ", " << "ID#: " << animal.id_number << ", " << "Gender: " << animal.gender << ", " << "Age: " << animal.age << ", " << "Health: " << animal.health_status;
	return ost;
}