#include <map>
#include <sstream>
#include "Date.h"

class Planner
{
	public:
		Planner();
		std::string get_event(Date) const;
		bool create_event(Date, std::string);
		void delete_event(Date);
		std::string get_all_events();
		void delete_all_events(std::string);
		void i_hate_my_life();		
		
	private:
		std::map<Date,std::string> planner;
};
