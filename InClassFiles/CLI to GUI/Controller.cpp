#include "Controller.h"

void Controller::cli()
{
	int cmd = -1;
	do{
	view.show_menu();
	std::cin >> cmd;
	execute_cmd(cmd);
	}while(cmd > 0);
}

void Controller::gui()
{
	int cmd = -1;
	do{
	cmd = view.show_menu();
	//std::cin >> cmd;
	execute_cmd(cmd);
	}while(cmd > 0);
}

void Controller::execute_cmd(int cmd)
{
	switch(cmd)
	{
		case 1:
			view.show_all_events();
			break;
		case 2:
			add_event();
			break;
		case 3:
			delete_event();
			break;
		case 0:
			break;
		default:
			view.show_menu_input_error();
	}
}

void Controller::add_event()
{
	//int y, m, d;
	std::string name;
	Date d = view.prompt_for_date();
	//std::cin >> y >> m >> d;
	view.prompt_for_event_name();
	//std::cin.ignore();
	std::getline(std::cin, name);
	planner.create_event(d,name);
}

void Controller::delete_event()
{
	int y, m, d;
	view.prompt_for_date();
	std::cin >> y >> m >> d;
	planner.delete_event(Date(y,m,d));
}
