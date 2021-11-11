#include "Hourly.h"
#include "Sales_Magager.h"
#include <iostream>

/*
inlcude Hourly means
class Employee;
Class Hourly;

include Comission
class Employee;
Class comission;
*/

int main()
{
	Employee e("Monica", 7);
	
	std::cout << e.get_name() << " " << e.get_id_number() << std::endl;
	
	Hourly h("Chandler", 19);
	
	h.add_hours(20);
	
	std::cout << h.pay_s() << std::endl;
	
	Comission c("Joey", 40);
	
	c.add_sales(20000);
	std::cout << c.pay() << std::endl;
	
	Salaried s("Rachel", 5);
	
	std::cout << s.pay() << std::endl;
	return 0;
}
