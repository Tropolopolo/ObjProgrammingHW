#ifndef MLI1200_VIEW_H
#define MLI1200_VIEW_H

#include "mli1200_Zoo.h"
#include "mli1200_Dialogs.h"

class View
{
public:
	View();
	View(Zoo& z) : zoo(z){};
	void preface();
	int show_menu();
	int get_input_i(std::string);
	std::string get_input_s(std::string);
	void print_list(std::vector<Animal*>);
	void messageP(int, std::string);
	void messageP(std::string, std::string);
	void printAnimal(std::pair<bool,Animal*>);
	void incorrect_selection();
	void error(std::string);
private: 
	Zoo& zoo;
};
#endif