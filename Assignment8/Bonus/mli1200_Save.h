#pragma once
#include "mli1200_Zoo.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>

class Save
{
public:
	Save(std::string f = "SaveFile8.txt") : filename(f) {};
	void writeAnimals(std::vector<Animal*> alist);
	std::vector<Animal*> readAnimals();
	std::string getFilename();
	//std::fstream getFStream();
	void setFilename(std::string);
	//void setFStream(std::fstream);
private:
	std::string filename = "";
	std::fstream fs;
	std::vector<int> lengths = {};
};