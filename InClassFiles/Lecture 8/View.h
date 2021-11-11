#include "Planner.h"
#include <stdlib.h>

class View
{
public:
	View(Planner& p) : planner(p) {};	
	void show_menu();
	void show_all_events();
	void show_menu_input_error();
	void prompt_for_date();
	void prompt_for_event_name();
private:
	Planner& planner;
};
