//Matthew Irvine 1001401200
#include "mli1200_Zoo.h"

bool Create_Animals(Zoo* z, int x)
{
	int counter = 0;
	while (counter < x)
	{
		int ag;
		int id;
		bool g;
		std::string hs;
		std::string n;
		std::string t;

		std::cout << std::endl;
		std::cout << "Name: " << std::endl;
		std::cin >> n;

		std::cout << "ID#: " << std::endl;
		std::cin >> id;

		std::cout << "Gender: " << std::endl;
		std::cin >> g;

		std::cout << "Age: " << std::endl;
		std::cin >> ag;

		std::cout << "Health: " << std::endl;
		std::cin >> hs;

		std::cout << "Type: " << std::endl;
		std::cin >> t;

		Animal a(n, id, g, ag, hs, t);
		if (z->add_animal(a))
		{
		}
		else
			return false;
		counter++;
	}
	return true;
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	Zoo zoo(0);
	std::vector<Animal> alist;
	std::cout << "How many exhibits to create?" << std::endl;
	int x;
	std::cin >> x;
	zoo.set_capacity(x);

	int counter = 0;
	while (counter < x)
	{
		int y = counter + 1;
		std::cout << "How many animals would you like to create for exhibit number " << y << "?" << std::endl;
		std::cin >> y;
		Create_Animals(&zoo, y);
		std::cout << std::endl;
		counter++;
	}

	//std::cout << zoo.check().size() << std::endl;
	std::cout << zoo << std::endl;
	std::cout << "Please create a new animal." << std::endl;
	if (!Create_Animals(&zoo, 1))
		std::cout << "Unsuccessful" << std::endl;


	std::cout << zoo << std::endl;
	std::cout << "Please remove one animal.\n What is the Animal ID? " << std::endl;
	std::cin >> x;
	zoo.remove_animal(x);
	std::cout << zoo << std::endl;

	std::cout << "Which type of animals do you want to see?" << std::endl;
	std::string t;
	std::cin >> t;
	alist = zoo.get_animals_of_type(t);
	std::cout << std::endl;
	for(int x = 0; x<alist.size(); x++)
	{
		std::cout << "Animal " << x << ": " << alist.at(x) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "What is the ID of an animal who's age you want to change?" << std::endl;
	std::cin >> x;
	std::cout << "What is the age that you want it to be?" << std::endl;
	int a;
	std::cin >> a;
	zoo.change_animal_age(x, a);
	std::cout << std::endl;
	std::cout << zoo << std::endl;

	std::cout << "What is the ID of an animal who's health status you want to change?" << std::endl;
	std::cin >> x;
	std::cout << "What is the health status that you want it to be?" << std::endl;
	std::cin >> t;
	zoo.change_animal_health_status(x, t);
	std::cout << std::endl;
	std::cout << zoo << std::endl;

	std::cout << "What is the ID of an animal to check to see if they are in the zoo?" << std::endl;
	std::cin >> x;
	std::cout << std::endl;
	if (zoo.is_animal_in_zoo(x))
		std::cout << "This animal is in the zoo." << std::endl;
	else
		std::cout << "This animal is not in the zoo." << std::endl;
	
	std::cout << std::endl;
	std::cout << "The average age of all the animals is: " << zoo.get_average_Age() << std::endl;
}