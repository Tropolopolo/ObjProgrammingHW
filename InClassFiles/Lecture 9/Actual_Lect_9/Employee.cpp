#include "Employee.h"

std::string Employee::get_name()
{
	return name;
}

int Employee::get_id_number()
{
	return id_number;
}

void Employee::set_name(std::string n)
{
	name = n;
}

void Employee::set_id_number(int id)
{
	id_number = id;
}
