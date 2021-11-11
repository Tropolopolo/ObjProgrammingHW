#include "Employee.h"

class Hourly : public Employee
{
	public:
		Hourly(std::string n = "John Doe", int id = 123, double hw = 0, double pr = 7.25) : Employee(n, id), hours_worked(hw), pay_rate(pr) {};
		double get_hours_worked();
		double get_pay_rate();
		double pay();
		std::string pay_s();
		void add_hours(double);
	private:
		double hours_worked;
		double pay_rate;
};
