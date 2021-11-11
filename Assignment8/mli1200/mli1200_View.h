#include "mli1200_Zoo.h"

class View
{
public:
	View();
	View(Zoo& z) : zoo(z) {};
	void preface();
	void show_menu();
	void get_input(std::string);
	void print_list(std::vector<Animal*>);
	void printP(std::string);
	void printP(int);
	void printAnimal(std::pair<bool,Animal*>);
	void incorrect_selection();
	void error(std::string);
private: 
	Zoo& zoo;
};