#include "mli1200_Controller.h"

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

	Animal* a = new Terrestrial("m", 1, 0, 5, "Good", "Terrestrial", "Dog");
	z.add_animal(a);
	c.cli();

	return 0;
}
