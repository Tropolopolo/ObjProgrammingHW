#include "Trainer.h"
//gets
std::string Trainer::getName()
{
	return name;
}

int Trainer::getCap()
{
	return CAP;
}

bool Trainer::getGen()
{
	return gender;
}

std::vector<Monster*> Trainer::getAllMonsters()
{
	return mons;
}

bool Trainer::getOutput()
{
	return output;
}

//sets
void Trainer::setName(std::string n)
{
	name = n;
}

void Trainer::setGender(bool b)
{
	gender = b;
}

void Trainer::setOutput(bool b)
{
	output = b;
}
//others
bool Trainer::addMonster(Monster* mon)
{
	if (mons.size() >= CAP)
	{
		return false;
	}

	mons.push_back(mon);
}

bool Trainer::removeMonster(int i)
{
	for (auto it = mons.begin(); it!= mons.end(); it++)
	{
		if ((*it)->getId() == i)
		{
			mons.erase(it);
			return true;
		}
	}

	return false;
}

std::pair<bool, Monster*> Trainer::getAMonster(int i)
{
	std::pair<bool, Monster*> p;
	for (auto it = mons.begin(); it != mons.end(); it++)
	{
		if ((*it)->getId() == i)
		{
			p.first = true;
			p.second = *it;
			return p;
		}
	}
	p.first = false;
	p.second = NULL;
	return p;
}

std::ostream& operator<<(std::ostream& ost, Trainer& t)
{
	if (!t.output)
	{
		ost << begin_trainer << std::endl;
		ost << t.name << std::endl << t.gender << std::endl;

		std::vector<Monster*> mlist = t.getAllMonsters();
		for (auto m : mlist)
		{
			ost << begin_monster << std::endl;
			ost << *m;

		}
		return ost;
	}
	else
	{
		ost << "Trainer:" << std::endl;
		ost << "Name: " << t.name << "\tGender: " << t.gender << std::endl;

		ost << std::endl << "Monsters: " << std::endl;
		std::vector<Monster*> mlist = t.getAllMonsters();
		for (auto m : mlist)
		{
			m->setOutput(1);
			ost << *m;
			m->setOutput(0);
		}
		return ost;
	}

}

int Trainer::numMonsters()
{
	return mons.size();
}

bool Trainer::CheckID(int i)
{
	//return false if there is no other monster with such id, true if there is.
	for (auto it = mons.begin(); it != mons.end(); it++)
	{
		if ((*it)->getId() == i)
		{
			return true;
		}
	}
	return false;
}