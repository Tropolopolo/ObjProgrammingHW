#include "mli1200_Zoo.h"

Zoo::Zoo()
{
	capacity = 25;
}

Zoo::Zoo(int c)
{
	capacity = c;
}

int Zoo::get_capacity() const
{
	return capacity;
}

void Zoo::set_capacity(int c)
{
	capacity = c;
}

bool Zoo::add_animal(Animal* animal)
{
	
	int animals_in_zoo = 0;
	for(auto x : zoo)
	{
		animals_in_zoo += x.second.size();
	}
	if(animals_in_zoo >= capacity)
		return false;
	
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(animal == a)
				return false;
		}
	}
	
	if(zoo.count(animal->get_species()) == 1)
	{
		zoo.at(animal->get_species()).push_back(animal);
	}
	else
	{
		//std::cout << "here" << std::endl;
		zoo.insert(std::pair<std::string, std::vector<Animal*>>(animal->get_species(), {animal}));
	}
	
	return true;
}

std::pair<bool,Animal*> Zoo::get_animal(int id) const
{
	std::pair<bool, Animal*> a;
	auto map_it = zoo.begin();
	for (; map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for (; vec_it != map_it->second.end(); vec_it++)
		{
			if ((*vec_it)->get_id_number() == id)
			{
				a.first = true;
				a.second = *vec_it;
				return a;
			}
		}
	}
	a.first = false;
	return a;
}

std::vector<Animal*> Zoo::get_all_animals() const
{
	std::vector<Animal*> alist;

	if (zoo.empty())
	{
		return alist;
	}
	else
	{
		auto map_it = zoo.begin();
		for (; map_it != zoo.end(); map_it++)
		{
			auto vec_it = map_it->second.begin();
			for (; vec_it != map_it->second.end(); vec_it++)
			{
				alist.push_back(*vec_it);
			}
		}
	}
}

std::vector<Animal*> Zoo::get_animals_of_species(std::string species) const
{
	return zoo.at(species);
}

std::vector<Animal*> Zoo::get_animals_of_type(std::string type) const
{
	std::vector<Animal*> alist;

	if (zoo.empty())
	{
		return alist;
	}
	else
	{
		auto map_it = zoo.begin();
		for (; map_it != zoo.end(); map_it++)
		{
			auto vec_it = map_it->second.begin();
			for (; vec_it != map_it->second.end(); vec_it++)
			{
				if ((*vec_it)->get_type() == type)
				{
					alist.push_back(*vec_it);
				}
			}
		}
	}
}

bool Zoo::is_animal_in_zoo(int id) const
{
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(a->get_id_number() == id)
				return true; 
		}
	}
	
	return false;
}

void Zoo::remove_animal(int id)
{
	auto map_it = zoo.begin();
	for(;map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for(; vec_it != map_it->second.end(); vec_it++)
		{
			if((*vec_it)->get_id_number() == id)
				{
					map_it->second.erase(vec_it);
					break;
				}
		}
	}
}

void Zoo::change_animal_age(int id, int age)
{
	auto map_it = zoo.begin();
	for(;map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for(; vec_it != map_it->second.end(); vec_it++)
		{
			if((*vec_it)->get_id_number() == id)
				{
					(*vec_it)->set_age(age);
				}
		}
	}
}

void Zoo::change_animal_health_status(int id, std::string status)
{
	auto map_it = zoo.begin();
	for(;map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for(; vec_it != map_it->second.end(); vec_it++)
		{
			if((*vec_it)->get_id_number() == id)
				{
					(*vec_it)->set_health_status(status);
				}
		}
	}
}

std::ostream& operator<<(std::ostream& ost, const Zoo& zoo)
{
		
	for(auto it = zoo.zoo.begin(); it != zoo.zoo.end(); it++)
	{
		ost << it->first << std::endl;
		for (Animal* a : it->second)
		{
			if (a->get_type() == "Terrestrial")
				ost << "\t" << *(dynamic_cast<Terrestrial*>(a)) << std::endl;
			if (a->get_type() == "Aquatic")
				ost << "\t" << *(dynamic_cast<Aquatic*>(a)) << std::endl;
			if (a->get_type() == "Amphibious")
				ost << "\t" << *(dynamic_cast<Amphibious*>(a)) << std::endl;
			if (a->get_type() == "Avian")
				ost << "\t" << *(dynamic_cast<Avian*>(a)) << std::endl;
		}
		ost << std::endl;
	}
	
return ost;
}
