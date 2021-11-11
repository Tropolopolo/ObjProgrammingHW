#ifndef _VIEW_H
#define _VIEW_H
#include "Trainer.h"
#include <typeinfo>

class View
{
public:
	View(Trainer* t) : tra(t) {};

	//others
	int showMenu(bool, std::string);

	template<typename T>
	void print(T t)
	{
		std::cout << t << std::endl;
	}

	template<typename T>
	void printRef(T* t)
	{
		t->setOutput(1);
		std::cout << *t << std::endl;
		t->setOutput(0);
	}


private:
	Trainer* tra;
	const std::string menu = R"(
		==============
		Matthew Irvine
		==============

		(1). Monsters.
		(2). Tainer.
		(3). File Handling.
		(4). Sorting.
		(0). Exit.
		
		Select an Option.
		)";
};
#endif