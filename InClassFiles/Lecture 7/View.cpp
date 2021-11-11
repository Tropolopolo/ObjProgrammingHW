#include "View.h"

void View::show_menu()
{
	std::string menu = R"(
================
CSE 1325 Planner
================

(1) View all events
(2) Add event
(3) Delete event
(0) Exit

Select an option
?)";
	
	std::cout << menu << std::endl;
}

void View::view_all_events()
{
	std::cout << p.get_all_events() << std::endl;
}

void View::prompt_for_input(std::string prompt)
{
	std::cout << "Please input " << prompt << std::endl;
}
