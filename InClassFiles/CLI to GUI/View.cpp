#include "View.h"

int View::show_menu()
{
	//system("clear");
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

	std::string result = Dialogs::input(menu, "Main Menu", "", "0");
	std::istringstream iss(result);
	int cmd;
	iss >> cmd;
	return cmd;
	//std::cout << menu << std::endl;
}

void View::show_all_events()
{
	std::string header = R"(
+++++++++++++++++++++
All events in planner
+++++++++++++++++++++
)";
	//std::cout << header << std::endl;
	if(planner.size() == 0)
		header += "No Events\n";
	else
		header += planner.print_all_events();
		
	Dialogs::message(header, "All Events");
}

void View::show_menu_input_error()
{
	std::cout << "Invalid input. Please select a number from the list." << std::endl;
}

Date View::prompt_for_date()
{
	std::string result = Dialogs::input("Input a date (YYYY MM DD)", "What Date?", "", "0 0 0");
	
	std::istringstream iss(result);
	int y, m ,d;
	iss >> y >> m >> d;
	return Date(y, m, d);
}

void View::prompt_for_event_name()
{
	std::cout << "Input an event name" << std::endl;
}
