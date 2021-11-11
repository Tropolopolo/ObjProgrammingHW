#include "Planner.h"

Planner::Planner() {}

bool Planner::create_event(Date d, std::string event)
{
	return planner.insert(std::pair<Date,std::string>(d, event)).second;
}

std::string Planner::get_event(Date d) const
{
	return planner.at(d);
}

void Planner::delete_event(Date d)
{
	planner.erase(d);
}

void Planner::print_all_events()
{
	for(auto x : planner)//std::pair<Date, std::string>
	{
		std::cout << x.first << " - " << x.second << std::endl;
	}
}

void Planner::i_hate_my_life()
{	
	planner.clear();
}
