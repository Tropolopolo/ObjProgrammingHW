#include "mli1200_Zoo.h"

class View
{
public:
	View();
	View(Zoo& z) : zoo(z) {};
	void show_menu();
	void get_input(std::string);
	void print_list(std::vector<Animal>);
	void print(std::string);
	void print(std::pair<bool,Animal>);
	void incorrect_selection();
private: 
	Zoo& zoo;
};