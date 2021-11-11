//Matthew Irvine 1001401200

#include <vector>
#include <fstream>
#include "mli1200_Animal.h"

int main(int argc, char *argv[])
{
	int a = 1;
	std::string line;
	std::ifstream myfile(argv[a], std::ios_base::in);
	std::vector<Animal> alist;

	if (myfile.is_open())
	{
		Animal a;
		//std::cout << "Opening " << argv[a] << std::endl;
		std::cout << std::endl;
		
		myfile >> a;
	}















	/*
	int x;
	std::cout << "How many animals would you like to create?" << std::endl;
	std::cin >> x;
	int counter = 0;
	while (counter < x)
	{
		Animal a;
		int ag;
		int id;
		bool g;
		std::string hs;
		std::string n;

		std::cout << "Name: " << std::endl;
		std::cin >> n;
		a.set_name(n);

		std::cout << "ID#: " << std::endl;
		std::cin >> id;
		a.set_id_number(id);

		std::cout << "Gender: " << std::endl;
		std::cin >> g;
		a.set_gender(g);

		std::cout << "Age: " << std::endl;
		std::cin >> ag;
		a.set_age(ag);

		std::cout << "Health: " << std::endl;
		std::cin >> hs;
		a.set_health_status(hs);

		alist.push_back(a);
		counter++;
	}
	*/

	std::cout << std::endl;
	int counter = 0;
	int total=0;
	for (int y = 0; y < alist.size(); y++)
	{
		std::cout << alist.at(y) << std::endl;
		total += (alist.at(y)).get_age();
		counter++;
	}
	int average = (total / counter);
	std::cout << "Average age: " << average << std::endl;
}