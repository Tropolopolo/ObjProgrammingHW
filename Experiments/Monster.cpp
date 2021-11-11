#include "Monster.h"

//gets
std::string Monster::getName()
{
	return name;
}
std::string Monster::getType()
{
	return type;
}
int Monster::getId()
{
	return id;
}
bool Monster::getGender()
{
	return gender;
}
std::string Monster::getSpecies()
{
	return species;
}
int Monster::getHealth()
{
	return hlth;
}
int Monster::getStr()
{
	return str;
}
int Monster::getDef()
{
	return def;
}
bool Monster::getOutput()
{
	return output;
}

//sets
void Monster::setName(std::string n)
{
	name = n;
}
void Monster::setType(std::string t)
{
	type = t;
}
void Monster::setId(int i)
{
	id = i;
}
void Monster::setGender(bool g)
{
	gender = g;
}
void Monster::setSpecies(std::string s)
{
	species = s;
}
void Monster::setHealth(int h)
{
	hlth = h;
}
void Monster::setStr(int s)
{
	str = s;
}
void Monster::setDef(int d)
{
	def = d;
}
void Monster::setOutput(bool b)
{
	output = b;
}

//others
std::ostream& operator<<(std::ostream& ost, const Monster& mon)
{
	if (!mon.output)
	{
		ost << mon.name << std::endl << mon.type << std::endl << mon.id << std::endl << mon.gender << std::endl << mon.species << std::endl << mon.hlth << std::endl << mon.str << std::endl << mon.def << std::endl;
	}
	else
	{
		ost << "Name: " << mon.name << "\tType: " << mon.type << "\tId: " << mon.id << "\tGender: " << mon.gender << "\tSpecies: " << mon.species << "\tHealth: " << mon.hlth << "\tStrength: " << mon.str << "\tDefense: " << mon.def << std::endl;
	}
	return ost;
}

bool operator>(const Monster& ml, const Monster& mr)
{
	if (ml.id > mr.id)
	{
		return true;
	}
	return false;
}