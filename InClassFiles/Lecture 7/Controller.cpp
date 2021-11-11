#include "Controller.h"

void Controller::cli()
{
	int cmd = -1;
	do
	{
		v.show_menu();
		std::cin >> cmd;
		execute_cmd(cmd);
	}while(cmd > 0);
}

void Controller::execute_cmd(int cmd)
{
	switch(cmd)
	{
		case 1:
			v.view_all_events();
			break;
		case 2:
			add_event();
			break;
		case 3:
			break;
		case 0:
			break;
		default:
			break;
	}
}

void Controller::add_event()
{
	int y,m,d;
	std::string event;
	v.prompt_for_input("a Date (MM DD YYYY)");
	std::cin >> m >> d >> y;
	v.prompt_for_input("an event");
	std::cin >> event;
	p.create_event(Date(y,m,d),event);
}
