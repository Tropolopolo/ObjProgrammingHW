#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
	public:
		Employee(std::string n = "John Doe", int id = 123) : name(n), id_number(id) {};
		std::string get_name();
		int get_id_number();
		void set_name(std::string);
		void set_id_number(int);
	protected:
		std::string name;
		int id_number;
};

#endif
