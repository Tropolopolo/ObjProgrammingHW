//Matthew Irvine 1001401200
#include <vector>
#include <map>
#include "mli1200_Animal.h"
class Zoo
{
public:
	Zoo();
	Zoo(int c);
	//get methods
	int get_capacity();
	std::vector<Animal> get_animals_of_type(std::string type);
	//set methods
	void set_capacity(int c);
	bool add_animal(Animal animal);
	void remove_animal(int id_number);
	void change_animal_age(int id_number, int age);
	void change_animal_health_status(int id_number, std::string health_status);
	std::map<std::string, std::vector<Animal>> check();
	//other methods
	bool is_animal_in_zoo(int id_number);
	int get_average_Age();
	friend std::ostream& operator<<(std::ostream & ost, const Zoo& zoo);

private:
	std::map <std::string, std::vector<Animal>> z;
	int capacity;
};