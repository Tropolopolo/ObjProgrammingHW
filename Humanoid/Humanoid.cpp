#include "Humanoid.h"
#include <math>
#include <random>

std::random_device rd;

void Humanoid::Damage(unsigned int hlth, unsigned int damage)
{
		unsigned int h = hlth - damage;
		std::cout << h << std::endl;
}
	
Humanoid::Humanoid()//Default Constructor
{
		Race = "Default";
		description = "None";
		Health = 0;	
		strength = 0;
}

Humanoid::Humanoid(std::string race, std::string desc, unsigned int hlth, unsigned int str)
{
		Race = race;
		description = desc;
		Health = hlth;
		strength = str;
}

//get methods
std::string Humanoid::getRace()
{
		return Race;
}

std::string Humanoid::getDesc()
{
		return description;
}

unsigned int Humanoid::getHealth()
{
		return Health;	
}

//set methods
void Humanoid::setRace(std::string race)
{
		Race = race;
}

void Humanoid::setDesc(std::string des)
{
		description = des;
}

void Humanoid::setHealth(int hlth)
{
		Health = hlth;	
}

void Humanoid::takeDamage(unsigned int damage)//check to see if this and health states should be lower in the heirarchy
{
		Health = Health - damage;
		std::cout << Health << std::endl;
}

void Humanoid::heal()
{
	Health += 100;
	Health += strength / rd();
}
void Humanoid::give_damage(Humanoid h)
{
	unsigned int d = strength / rd();
	h.takeDamage(d);
}
//other methods

std::string Humanoid:to_string() const
{
		std::string s;
		s += "Race: " + Race + "\n" + "Description" + desciption + "\n" + "Health: " + Health;
		return s;
}

std::ostream& operator<<(std::ostream& ost, const Humanoid& humanoid)
{
	ost << Race << " " << description << " " << Health;
	return ost;
}