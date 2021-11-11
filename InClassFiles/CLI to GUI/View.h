#include "Planner.h"
#include <iostream>
#include <sstream>
#include <gtkmm.h>
#include "dialog.h"

class View
{
public:
	View(Planner& p) : planner(p) {};	
	int show_menu();
	void show_all_events();
	void show_menu_input_error();
	Date prompt_for_date();
	void prompt_for_event_name();
private:
	Planner& planner;
};
