#include "View.h"

class Controller
{
public:
	Controller(Planner& p, View& v) : planner(p), view(v) {};
	void cli();
	void execute_cmd(int);
	void add_event();
	void delete_event();
private:
	Planner& planner;
	View& view;
};


