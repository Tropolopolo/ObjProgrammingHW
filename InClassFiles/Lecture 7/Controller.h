#include "View.h"

class Controller
{
	public:
		Controller(Planner& pl, View& vi) : p(pl), v(vi) {};
		void cli();
		void execute_cmd(int);
		void add_event();
	private:
		View& v;
		Planner& p;
};
