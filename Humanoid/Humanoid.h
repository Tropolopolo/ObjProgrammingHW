#pragma once 
//Matthew Irvine
#include <string>
#include <iostream>

class Humanoid
{
public: 
	//constructors
	Humanoid();
	Humanoid(std::string race, std::string desc, unsigned int hlth);
	//get methods
	std::string getRace();
	std::string getDesc();
	unsigned int getHealth();
	//set methods
	void setRace(std:: string race);
	void setDesc(std:: string desc);
	void setHealth(unsigned int hlth);
	void takeDamage(unsigned int damage);
	//other methods
	void heal();
	void give_damage(Humanoid);
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& ost, const Humanoid& humanoid);

private:
	std::string Race;
	std::string description;
	unsigned int Health;
	unsigned int strength;
	void Damage(unsigned int hlth, unsigned int damage);
};
