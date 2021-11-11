//#include "Date.h"
#include "Controller.h"

int main()
{
	Planner p;
	View v(p);
	Controller c(p, v);
	
	c.cli();
	
	return 0;
}
