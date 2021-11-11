//#include "Date.h"
#include "Planner.h"

int main()
{
	/*Date today {2019, 1, 28};
	//today.year = 2019; Wont compile due to private
	//today.set_day(28);
	
	std::cout << today.get_day() << std::endl;
	today.add_day();
	std::cout << today.get_day() << std::endl;
	
	today.add_day(5);
	std::cout << today.get_day() << std::endl;
	
	Date d;
	
	//today + 5;
	
	std::cout << today << std::endl;
	*/
	Planner p;
	
	p.create_event(Date(2019,2,4),"CSE 1325");
	p.create_event(Date(2019,2,5),"CSE 2312");
	p.create_event(Date(2019,2,1),"All day meeting");
	
	p.print_all_events();
	std::cout << "------------------" << std::endl;
	p.delete_event(Date(2019,2,1));
	
	p.print_all_events();
	std::cout << "------------------" << std::endl;
	
	p.create_event(Date(2019,2,6),"CSE 1325");
	p.print_all_events();
	std::cout << "------------------" << std::endl;
	
	p.i_hate_my_life();
	p.print_all_events();
	
	return 0;
}
