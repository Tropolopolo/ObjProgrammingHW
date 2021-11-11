#include "mli1200_View.h"

void View::show_menu()
{
	std::string menu = R"(
============
CSE 1325 Zoo
============

(1) Add animals to a new exhibits.
(2) Add an animal to an exhibit.
(3) Remove an animal from the system.
(4) Change the zoo's capacity.
(5) View all animals in the system.
(6) Get all animals of a certain type.
(7) Get an individual animal given an id.
(8) Change an animal's age.
(9) Change an animal's health status.
(0) Exit.
Select an option
?)";

	std::cout << menu << std::endl;
}

auto View::get_input(std::string prompt)
{
	auto x;
	std::cout << "Please input " << prompt << std::endl;
	std::cin >> x;
	return x;
}

void View::print_list(std::vector<Animal> a)
{
	for (auto x : a)
	{
		std::cout << x << std::endl;
	}
}

void View::print(std::string s)
{
	std::cout << s << std::endl;
}

void View::print(std::pair<bool,Animal> a)
{
	if (a.first)
	{
		std::cout << a.second << std::endl;
	}
	else
		std::cout << "There is no animal with that ID." << std::endl;
	
}

void View::incorrect_selection()
{
	std::cout << "Invalid selection choosen, please select a valid menu option" << std::endl;
}
