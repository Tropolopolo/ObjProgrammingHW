#include "mli1200_Zoo.h"
#include "mli1200_View.h"

class Controller
{
public:
	Controller();
	Controller(Zoo& z, View& v) : zoo(z), view(v) {};
	void cli();
	void execute_cmd(int cmd);
	std::vector<bool> get_multianimal_info(int);
	bool get_animal_info();
private:
	Zoo& zoo;
	View& view;
};