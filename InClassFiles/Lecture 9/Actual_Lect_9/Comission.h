#include "Employee.h"

class Comission : public Employee
{
	public:
		Comission(std::string n = "John Doe", int id = 123, double cr = 0.1, double ts = 0) : Employee(n, id), comission_rate(cr), total_sales(ts) {};
		double pay();
		void add_sales(double);
	protected:
		double comission_rate;
		double total_sales;
};
