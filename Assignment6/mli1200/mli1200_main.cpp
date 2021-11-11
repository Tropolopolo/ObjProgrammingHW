#include "mli1200_Amphibious.h"
#include "mli1200_Avian.h"
#include "mli1200_Aquatic.h"
#include "mli1200_Terrestrial.h"
#include "mli1200_Animal.h"

int main()
{
	
	Animal a;
	Terrestrial t;
	Aquatic aq;
	Avian av;
	Amphibious am;
	
	std::cout << a << std::endl;
	std::cout << t << std::endl;
	std::cout << aq << std::endl;
	std::cout << av << std::endl;
	std::cout << am << std::endl;

	std::cout << a.get_name() << " is an animal." << std::endl;
	t.walk();
	aq.swim();
	av.fly();
	am.Terrestrial::walk();
	am.Aquatic::swim();
	/*
	aq.swim();
	av.fly();
	am.walk();
	am.swim();
	*/

	return 0;
}
