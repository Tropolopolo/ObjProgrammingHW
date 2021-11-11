#include "mli1200_View.h"

void View::preface()
{
	std::string preface = R"(
/*note to TA

I have already included some test case animals without you having to add them.
These are only designed to test all features of the program in the case that 
both animal adding functions do not work...

*/)";

	std::cout << preface << std::endl;
}

void View::show_menu()
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
(13) Save the Animals to File.
(14) Load Animals from File.
(15) Show the file.
(16) Change Save file.
(0) Exit.
Select an option
?)";

	std::cout << menu << std::endl;
}

void View::get_input(std::string prompt)
{
	std::cout << "Please input " << prompt << std::endl;
}

void View::print_list(std::vector<Animal*> a)
{
	std::cout << "_______________________________________________________________________________________________________" << std::endl;
	for (auto x : a)
	{

		if (x->get_type() == "Terrestrial")
			std::cout << *(dynamic_cast<Terrestrial*>(x)) << std::endl;
		if (x->get_type() == "Aquatic")
			std::cout << *(dynamic_cast<Aquatic*>(x)) << std::endl;
		if (x->get_type() == "Amphibious")
			std::cout << *(dynamic_cast<Amphibious*>(x)) << std::endl;
		if (x->get_type() == "Avian")
			std::cout << *(dynamic_cast<Avian*>(x)) << std::endl;
		std::cout << std::endl;
	}
	std::cout << "_______________________________________________________________________________________________________" << std::endl;
}

void View::printP(std::string s)
{
	std::cout << "_________________________________________________________________________" << std::endl;
	std::cout << s << std::endl;
}

void View::printP(int x)
{
	std::cout << "_________________________________________________________________________" << std::endl;
	std::cout << x << std::endl;
}

void View::printAnimal(std::pair<bool,Animal*> a)
{
	std::cout << "_________________________________________________________________________" << std::endl;
	auto x = a.second;
	if (a.first)
	{
		if (x->get_type() == "Terrestrial")
			std::cout << *(dynamic_cast<Terrestrial*>(x)) << std::endl;
		if (x->get_type() == "Aquatic")
			std::cout << *(dynamic_cast<Aquatic*>(x)) << std::endl;
		if (x->get_type() == "Amphibious")
			std::cout << *(dynamic_cast<Amphibious*>(x)) << std::endl;
		if (x->get_type() == "Avian")
			std::cout << *(dynamic_cast<Avian*>(x)) << std::endl;
	}
	else
		std::cout << "There is no animal with that ID." << std::endl;
	
}

void View::incorrect_selection()
{
	std::cout << "Invalid selection choosen, please select a valid option" << std::endl;
}

void View::error(std::string s)
{
	std::cerr <<"Error: " <<  s << std::endl;
}
