//#include "Date.h"
#include "Controller.h"

using namespace std;

int main()
{
	Planner planner;

	View view{planner};
	
	Controller controller{planner, view};
	
	controller.cli();
	
	return 0;
}
