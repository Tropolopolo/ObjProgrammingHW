#include "mli1200_Controller.h"
#include "mli1200_Save.h"

int main()
{
/*
	std::cout << "What is the capacity of the zoo (minimum of 10 for this example)" << std::endl;
	int x;
	std::cin >> x;
	while (x <= 9)
	{
		std::cout << "Error: not a valid number, please retype." << std::endl;
		std::cin >> x;
	}

	std::cout << "__________________________________________________________________________________________"<< std::endl;
	

	std::cout << zoo << std::endl;

	zoo.remove_animal(10);
	zoo.remove_animal(11);
	std::cout << "_________________________________________________________________________________________" << std::endl;
	std::cout << zoo << std::endl;
*/
	Zoo z;
	View v(z);
	Controller c(z,v);
	Save s;

	v.preface();
	// Preset animals for testing purposes...
	Animal* a1 = new Terrestrial("Ross", 6, 1, 31, "Good", "Terrestrial", "Dog");
	Animal* a2 = new Aquatic("Jamie", 7, 1, 33, "Good", "Aquatic", "Fish");
	Animal* a3 = new Avian("Orochimaru", 8, 1, 56, "Good", "Avian", "Birb");
	Animal* a4 = new Amphibious("Amaterasu no Okami", 9, 0, 10000, "Good", "Amphibious", "Frog");

	z.add_animal(a1);
	z.add_animal(a2);
	z.add_animal(a3);
	z.add_animal(a4);

	Animal* a5 = new Terrestrial("Mark", 10, 1, 32, "Good", "Terrestrial", "Dog");
	Animal* a6 = new Avian("April", 11, 0, 25, "Bad", "Avian", "HummingBird");
	//Animal* a7 = new Animal();

	z.add_animal(a5);
	z.add_animal(a6);
	//z.add_animal(a7);
	// End of the test animals...

	c.cli();

	return 0;
}
