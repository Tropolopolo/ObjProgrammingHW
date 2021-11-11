//#include "Date.h"
#include "Controller.h"

using namespace std;

int main(int argc, char* argv[])
{
	Gtk::Main kit(argc, argv);
	
	Planner planner;

	View view{planner};
	
	Controller controller{planner, view};
	
	controller.gui();
	
	return 0;
}
