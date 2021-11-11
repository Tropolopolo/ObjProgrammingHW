#ifndef _TRAINER_H
#define _TRAINER_H
#include "Monster.h"

#include <vector>
#define CAP 6
#define begin_trainer "$"
#define begin_monster "&"

class Trainer
{
public:
	Trainer(std::string n, bool g) : name(n), gender(g) { output = 0; };

	//gets
	std::string getName();
	int getCap();
	bool getGen();
	std::vector<Monster*> getAllMonsters();
	std::pair<bool,Monster*> getAMonster(int);
	int numMonsters();
	bool getOutput();

	//sets
	void setName(std::string);
	void setGender(bool);
	void setOutput(bool);

	//others
	bool addMonster(Monster*);
	bool removeMonster(int);
	bool CheckID(int);
	
	friend std::ostream& operator<<(std::ostream&, Trainer&);
private:
	std::string name;
	bool gender;
	std::vector<Monster*> mons;
	bool output;
};
#endif