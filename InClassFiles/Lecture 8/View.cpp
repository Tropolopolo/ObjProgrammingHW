#include "View.h"

void View::show_menu()
{
	system("clear");
	std::string menu = R"(
=========================
Planner Management System
=========================

(1) View all events
(2) Add event
(3) Delete event
(0) Exit

Select an Option.
)";

	std::cout << menu << std::endl;
}

void View::show_all_events()
{
	std::string header = R"(
+++++++++++++++++++++
All events in planner
+++++++++++++++++++++
)";
	std::cout << header << std::endl;
	if(planner.size() == 0)
		std::cout << "No Events" << std::endl;
	else
		planner.print_all_events();
}

void View::show_menu_input_error()
{
	std::cout << "Invalid input. Please select a number from the list." << std::endl;
}

void View::prompt_for_date()
{
	std::cout << "Input a date (YYYY MM DD)" << std::endl;
}

void View::prompt_for_event_name()
{
	std::cout << "Input an event name" << std::endl;
}
