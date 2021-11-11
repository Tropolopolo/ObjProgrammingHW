#ifndef _MLI1200_ZOO_H
#define _MLI1200_ZOO_H
#include <map>
#include <vector>
#include "mli1200_Animal.h"
#include "mli1200_Amphibious.h"
#include "mli1200_Avian.h"
#include "mli1200_Aquatic.h"
#include "mli1200_Terrestrial.h"

class Zoo
{
public:
	Zoo();
	Zoo(int c);
	int get_capacity() const;
	void set_capacity(int);
	bool add_animal(Animal*);
	std::pair<bool,Animal*> get_animal(int) const;
	std::vector<Animal*> get_animals_of_species(std::string) const;
	std::vector<Animal*> get_animals_of_type(std::string) const;
	std::vector<Animal*> get_all_animals() const;
	bool is_animal_in_zoo(int) const;
	void remove_animal(int);
	void change_animal_age(int, int);
	void change_animal_health_status(int, std::string);
	friend std::ostream& operator<<(std::ostream&, const Zoo&);
private:
	std::map<std::string, std::vector<Animal*>> zoo;
	int capacity;
};
#endif



