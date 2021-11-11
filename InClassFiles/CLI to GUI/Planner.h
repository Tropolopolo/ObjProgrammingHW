#include "Date.h"
#include <map>
#include <sstream>

class Planner
{
public:
	Planner();
	Planner(std::map<Date, std::string>);
	std::string print_all_events();
	std::string get_event(Date) const;
	bool create_event(Date, std::string);
	bool delete_event(Date);
	bool delete_all_events(std::string);
	bool i_hate_my_life();
	int size();
private:
	std::map<Date, std::string> event_list;
};
