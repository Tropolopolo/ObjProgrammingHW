#include "Employee.h"

class Salaried : public Employee
{
	public:
		Salaried(std::string n = "John Doe", int id = 123, double ys = 50000) : Employee(n, id), yearly_salary(ys) {};
		double pay();
	protected:
		double yearly_salary;
};
