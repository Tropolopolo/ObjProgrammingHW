#include "Planner.h"

Planner::Planner() {}

Planner::Planner(std::map<Date, std::string> el)
{
	event_list = el;
}

bool Planner::create_event(Date d, 					std::string event_name)
{
	return event_list.insert( std::pair<Date,std::string>(d, event_name) ).second;
}

std::string Planner::print_all_events()
{
	std::ostringstream oss;
	for(auto x : event_list)
	{
		oss << x.first << " - " << x.second << std::endl;
	}
	return oss.str();
}

bool Planner::delete_event(Date d)
{
	event_list.erase(d);
	
	if(event_list.count(d))
		return false;
	return true;
}

bool Planner::i_hate_my_life()
{
	event_list.clear();
	if(event_list.size() == 0)
		return true;
	else
		return false;
}

int Planner::size()
{
	return event_list.size();
}
