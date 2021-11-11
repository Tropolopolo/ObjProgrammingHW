#include "Planner.h"

class View
{
	public:
		View(Planner& pl) : p(pl) {};
		void show_menu();
		void view_all_events();
		void prompt_for_input(std::string);
		
	private:
		Planner& p;
};
