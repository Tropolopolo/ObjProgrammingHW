#include "FileHandle.h"
#include <map>

void FileHandle::Save(Trainer* t)
{
	file.open(path + filename);

	if (file.fail())
	{
		v->print("Error: Failed to Open " + filename);
		exit(1);
	}

	file << *t;
	file.close();
}

Trainer* FileHandle::Load()
{
	Trainer* t;
	Monster* m;

	int counter = 0;

	std::string tname;
	bool tg;

	std::string mname;
	std::string mtype;
	int id;
	bool mg;
	std::string species;
	int hlth;
	int str;
	int def;

	file.open(path + filename);
	if (file.fail())
	{
		v->print("Error: Failed to Open" + filename);
		exit(1);
	}
	
	std::vector<std::string> st;
	std::string w;

	while (!file.eof())
	{
		file >> w;
		st.push_back(w);
	}

	for (int x = 0; x < st.size(); x++)
	{
		
		if (st.at(x) == begin_trainer)
		{
			x++;
			tname = st.at(x);
			x++;
			tg = std::stoi(st.at(x));

			t = new Trainer(tname, tg);
		}
		else if (st.at(x) == begin_monster)
		{
			x++;
			mname = st.at(x);
			x++;
			mtype = st.at(x);
			x++;
			id = std::stoi(st.at(x));
			x++;
			mg= std::stoi(st.at(x));
			x++;
			species = st.at(x);
			x++;
			hlth = std::stoi(st.at(x));
			x++;
			str = std::stoi(st.at(x));
			x++;
			def = std::stoi(st.at(x));

			m = new Monster(mname, mtype, id, mg, species, hlth, str, def);
			t->addMonster(m);
		}
	}

	file.close();
	return t;
}

std::string FileHandle::getFileName()
{
	return filename;
}

std::string FileHandle::getPath()
{
	return path;
}