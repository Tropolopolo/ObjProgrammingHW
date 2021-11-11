#ifndef _MONSTER_H
#define _MONSTER_H
#include <iostream>
#include <string>

class Monster
{

public:
	Monster(std::string n = "", std::string t = "", int i = 0, bool g = 0, std::string s = "", int h = 0, int st = 0, int d = 0) : name(n), type(t), id(i), gender(g), species(s), maxHlth(h), maxStr(st), maxDef(d) { hlth = maxHlth; str = maxStr; def = maxDef; };
	//gets
	std::string getName();
	std::string getType();
	int getId();
	bool getGender();
	std::string getSpecies();
	int getHealth();
	int getStr();
	int getDef();
	bool getOutput();

	//sets
	void setName(std::string);
	void setType(std::string);
	void setId(int);
	void setGender(bool);
	void setSpecies(std::string);
	void setHealth(int);
	void setStr(int);
	void setDef(int);
	void setOutput(bool);

	//others
	friend std::ostream& operator<<(std::ostream&, const Monster&);
	friend bool operator>(const Monster&, const Monster&);
private:
	std::string name;
	std::string type;
	int id;
	bool gender;
	std::string species;
	bool output;

	//stats
	int maxHlth;
	int maxStr;
	int maxDef;

	int hlth;
	int str;
	int def;
};

#endif // !MONSTER_H