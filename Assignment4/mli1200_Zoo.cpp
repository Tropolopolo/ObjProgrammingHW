#include "mli1200_Zoo.h"

Zoo::Zoo() {}

Zoo::Zoo(int c)
{
	//zoo.insert(std::pair<std::string, std::vector<Animal>>("D", {}));
	capacity = c;
}

//get methods
int Zoo::get_capacity()
{
	return capacity;
}

std::vector<Animal> Zoo::get_animals_of_type(std::string type)
{
	std::vector<Animal> v;
	for (auto x : z)
	{
		if (x.first == type)
		{
			for (int y = 0; y < x.second.size(); y++)
			{
				v.push_back(x.second.at(y));
			}
		}
	}
	return v;
}

//set methods
void Zoo::set_capacity(int c)
{
	capacity = c;
}

bool Zoo::add_animal(Animal animal)
{	
	if (z.size()<=capacity)
	{
		int counter = 0;
		for (auto x : z)
		{
			counter++;
			if (x.first == animal.get_type())
			{
				counter = 0;
				for (int y = 0; y < x.second.size(); y++)
				{
					if (x.second.at(y).get_id() == animal.get_id())
					{
						std::cout << "here" << std::endl;
						return false;
					}
				}
				x.second.push_back(animal);
				return true;
			}
		}
		if (counter == z.size())
		{
			z.insert(std::pair<std::string, std::vector<Animal>>(animal.get_type(), { animal }));
			return true;
		}
	}
	else
	{
		std::cout << 'h';
		return false;
	}
		
		
}

void Zoo::remove_animal(int id_number)
{
	for (auto x : z)
	{
		for (int y =0; y<x.second.size(); y++)
		{
			//std::cout << x.second.at(y).get_id() << ":" << id_number<< std::endl;
			if (x.second.at(y).get_id() == id_number)
			{
				//std::cout << x.second.at(y) << std::endl;
				x.second.erase(x.second.begin()+y);
			}
		}
	}
}

void Zoo::change_animal_age(int id_number, int age)
{
	for (auto x : z)
	{
		for (int y = 0; y < x.second.size(); y++)
		{
			if (x.second.at(y).get_id() == id_number)
			{
				x.second.at(y).set_age(age);
			}
		}
	}
}

void Zoo::change_animal_health_status(int id_number, std::string health_status)
{
	for (auto x : z)
	{
		for (int y = 0; y < x.second.size(); y++)
		{
			if (x.second.at(y).get_id() == id_number)
			{
				x.second.at(y).set_health_status(health_status);
			}
		}
	}
}

//other methods
bool Zoo::is_animal_in_zoo(int id_number)
{
	for (auto x : z)
	{
		for (int y = 0; y < x.second.size(); y++)
		{
			if (x.second.at(y).get_id() == id_number)
			{
				return true;
			}
		}
	}
	return false;
}

int Zoo::get_average_Age()
{
	int total = 0;
	int y;
	for (auto x : z)
	{
		for (y = 0; y < x.second.size(); y++)
		{
			total += x.second.at(y).get_age();
		}
	}
	return total / y;
}

std::ostream& operator<<(std::ostream& ost, const Zoo& zoo)
{
	for(auto x : zoo.z)
	{
		ost << x.first << ":\n";
		std::cout << x.second.size() << std::endl;
		for (int y = 0; y < x.second.size(); y++)
		{
			//std::cout << x.second.at(y) << std::endl;
			ost << "Animal " << y << ": " << x.second.at(y) << "\n";
		}	
	}
	return ost;
}
