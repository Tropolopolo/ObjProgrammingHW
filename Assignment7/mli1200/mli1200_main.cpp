#include "mli1200_Amphibious.h"
#include "mli1200_Avian.h"
#include "mli1200_Aquatic.h"
#include "mli1200_Terrestrial.h"
#include "mli1200_Animal.h"
#include "mli1200_Zoo.h"

int main()
{
	std::cout << "What is the capacity of the zoo (minimum of 10 for this example)" << std::endl;
	int x;
	std::cin >> x;
	while (x <= 9)
	{
		std::cout << "Error: not a valid number, please retype." << std::endl;
		std::cin >> x;
	}

	std::cout << "__________________________________________________________________________________________"<< std::endl;
	Zoo zoo(x);
	Animal* a1 = new Terrestrial("Ross", 6, 1, 31, "Good", "Terrestrial", "Dog");
	Animal* a2 = new Aquatic("Jamie", 7, 1, 33, "Good", "Aquatic", "Fish");
	Animal* a3 = new Avian("Orochimaru", 8, 1, 56, "Good", "Avian", "Birb");
	Animal* a4 = new Amphibious("Amaterasu no Okami", 9, 0, 10000, "Good", "Amphibious", "Frog");
	
	zoo.add_animal(a1);
	zoo.add_animal(a2);
	zoo.add_animal(a3);
	zoo.add_animal(a4);

	Animal* a5 = new Terrestrial("Mark", 10, 1, 32, "Good", "Terrestrial", "Dog");
	Animal* a6 = new Avian("April", 11, 0, 25, "Bad", "Avian", "HummingBird");

	zoo.add_animal(a5);
	zoo.add_animal(a6);

	std::cout << zoo << std::endl;

	zoo.remove_animal(10);
	zoo.remove_animal(11);
	std::cout << "_________________________________________________________________________________________" << std::endl;
	std::cout << zoo << std::endl;
	return 0;
}
