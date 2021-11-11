#include "mli1200_View.h"

void View::preface()
{
	std::string preface = R"(
note to TA:

I have already included some test case animals without you having to add them.
These are only designed to test all features of the program in the case that 
both animal adding functions do not work...

)";

	Dialogs::message(preface, "preface");
}

int View::show_menu() // IDK if a vector include is neccessary
{
	std::string menu = R"(
============
CSE 1325 Zoo
============

(1) Add animals to new exhibits.
(2) Add an animal to an exhibit.
(3) Remove an animal from the system.
(4) Change the zoo's capacity.
(5) View all animals in the system.
(6) Get all animals of a certain species.
(7) Get an individual animal given an id.
(8) Change an animal's age.
(9) Change an animal's health status.
(10) View animals of a certain type.
(11) View the Zoo's Capacity.
(12) View the Animals' actions.
(0) Exit.
Select an option
?)";
	std::string result = Dialogs::input(menu, "Main Menu", "", "0");
	std::istringstream iss(result);
	int cmd;
	iss >> cmd;
	return cmd;
}

int View::get_input_i(std::string prompt)
{
	prompt = "Please input" + prompt;
	std::string result = Dialogs::input(prompt, "Input");
	std::istringstream iss(result);
	int x;
	iss >> x;
	return x;
}

std::string View::get_input_s(std::string prompt)
{
	prompt = "Please input" + prompt;
	return Dialogs::input(prompt, "Input");
}

void View::print_list(std::vector<Animal*> a)
{
	std::string msg;
	for (auto x : a)
	{

		if (x->get_type() == "Terrestrial")
			msg = msg + (dynamic_cast<Terrestrial*>(x))->to_string() + "\n";
		if (x->get_type() == "Aquatic")
			msg = msg + (dynamic_cast<Aquatic*>(x))->to_string() + "\n";
		if (x->get_type() == "Amphibious")
			msg = msg + (dynamic_cast<Amphibious*>(x))->to_string() + "\n";
		if (x->get_type() == "Avian")
			msg = msg + (dynamic_cast<Avian*>(x))->to_string() + "\n";
		std::cout << std::endl;
	}

	Dialogs::message(msg, "Animal list");
}

void View::messageP(int x, std::string s)
{
	std::string i = std::to_string(x);
	//std::cout << Dialogs::message(i, s) << std::endl;
	Dialogs::message(i, s);
}

void View::messageP(std::string m, std::string s)
{
	//std::cout << Dialogs::message(m, s) << std::endl;
	Dialogs::message(m, s);
}

void View::printAnimal(std::pair<bool,Animal*> a)
{
	auto x = a.second;
	if (a.first)
	{
		//std::cout << Dialogs::message(*(dynamic_cast<Terrestrial*>(x)), "printAnimal") << std::endl;
		if (x->get_type() == "Terrestrial")
			Dialogs::message((dynamic_cast<Terrestrial*>(x))->to_string(), "printAnimal");
		if (x->get_type() == "Aquatic")
			Dialogs::message((dynamic_cast<Aquatic*>(x))->to_string(), "printAnimal");
		if (x->get_type() == "Amphibious")
			Dialogs::message((dynamic_cast<Amphibious*>(x))->to_string(), "printAnimal");
		if (x->get_type() == "Avian")
			Dialogs::message((dynamic_cast<Avian*>(x))->to_string(), "printAnimal");
	}
	else
		Dialogs::message("There is no animal with that ID.", "Failure");
	
}

void View::incorrect_selection()
{
	//std::cout << Dialogs::message("Invalid selection choosen, please select a valid option", "Invalid") << std::endl;
	Dialogs::message("Invalid selection choosen, please select a valid option", "Invalid");
}

void View::error(std::string s)
{
	std::string e = "Error: " + s;
	//std::cerr << Dialogs::message(e, "Error") << std::endl;
	Dialogs::message(e, "Error");
}
