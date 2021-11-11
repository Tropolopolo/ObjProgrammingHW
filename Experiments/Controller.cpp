#include "Controller.h"

void Controller::cli()
{
	int cmd = -1;
	do
	{
		cmd = v->showMenu(false, "");
		v->printS(spacer);
		exeCMD(cmd);
	} while (cmd > 0);
}

void Controller::exeCMD(int cmd)
{
	int i;
	int subCmd;
	switch (cmd) {
	case 1:
	{
		subCmd = -1;
		v->print(t);
		v->print("What Monster do you want to get? (use ID #)");
		std::cin >> i;
		std::pair<bool, Monster*> p = t->getAMonster(i);
		Monster* m;
		if (p.first)
		{
			m = p.second;
		}
		else
		{
			v->print("Error: Failed to find monster with id of " + std::to_string(i));
			break;
		}

		std::string menu = R"(
		What would you like to do with the Monster?

		(1). Change name.
		(2). Change Health.
		(3). Change Strength.
		(4). Change Defense.
		(5). Change ID.
		(0). Go Back.

		Select an Option.)";

		do
		{
			v->print(m);
			subCmd = v->showMenu(true, menu);
			v->print(spacer);
			exeMonster(subCmd, m);
		} while (subCmd > 0);
		break;
	}
	case 2:
	{
		subCmd = -1;
		std::string s = R"(
		(1). Show Monsters.
		(2). Add Monster(s).
		(3). get a Monster.
		(4). get a list of Monsters.
		(5). Check max Capacity.
		(6). Remove a Monster.
		(0). Exit

		Select an Option.)";

		do
		{
			subCmd = v->showMenu(true, s);
			v->print(spacer);
			exeTrainer(subCmd, t);
		} while (subCmd > 0);
		break;
	}
	case 3:
	{
		subCmd = -1;
		std::string s = R"(
		(1). Save.
		(2). Load.
		(0). Exit.)";

		do
		{
			subCmd = v->showMenu(true, s);
			v->print(spacer);
			exeFileHandle(subCmd, f);
		} while (subCmd > 0);
		break;
	}
	case 4:
	{
		//Sorting
		subCmd = -1;
		std::string s = R"(
		(1). Sort by Health.
		(2). Sort by Strength.
		(3). Sort by Defense.
		(4). Sort by ID.
		(0). Exit.)";

		subCmd = v->showMenu(true, s);
		v->print(spacer);

		std::vector<Monster*> mlist = t->getAllMonsters();
		Sort<Monster*> sort(mlist, subCmd);
		break;
	}
	case 0:
	{
		cmd = -1;
		break;
	}
	default:
	{
		v->print("Not an option");
		break;
	}
	}
}

Monster* Controller::getMonsterInfo()
{
	Monster* m = new Monster();

	std::string s;
	int i;
	bool b;

	v->print("What is the Name of the Monster?");
	std::cin >> s;
	m->setName(s);

	v->print("What is the Type of the Monster?");
	std::cin >> s;
	m->setType(s);

	v->print("What is the Id of the Monster? (number)");
	std::cin >> i;
	m->setId(i);

	v->print("What is the gender of the Monster? (0- male, 1- female)");
	std::cin >> b;
	m->setGender(b);

	v->print("What is the species of the Monster?");
	std::cin >> s;
	m->setSpecies(s);

	v->print("What is the starting health of the Monster? (number)");
	std::cin >> i;
	m->setHealth(i);

	v->print("What is the starting strength of the Monster? (number)");
	std::cin >> i;
	m->setStr(i);

	v->print("What is the starting Defense of the Monster? (number)");
	std::cin >> i;
	m->setDef(i);

	return m;
}

void Controller::exeMonster(int subCmd, Monster* m)
{
	switch (subCmd)
	{
	case 1:
	{
		std::string n;
		v->print("What is the Name you want to change " + m->getName() + " to?");
		std::cin >> n;
		m->setName(n);
		break;
	}
	case 2:
	{
		int n;
		v->print("What is the Health you want to change " + m->getName() + " to?");
		std::cin >> n;
		m->setHealth(n);
		break;
	}
	case 3:
	{
		int n;
		v->print("What is the Strength you want to change " + m->getName() + " to?");
		std::cin >> n;
		m->setStr(n);
		break;
	}
	case 4:
	{
		int n;
		v->print("What is the Defense you want to change " + m->getName() + " to?");
		std::cin >> n;
		m->setDef(n);
		break;
	}
	case 5:
	{
		int n;
		v->print("What is the ID you want to change " + m->getName() + " to?");
		std::cin >> n;
		if (t->CheckID(n))
		{
			v->print("Error: Monster ID Already Exits");
			break;
		}
		m->setId(n);
		break;
	}
	case 0:
		break;
	default:
		break;
	}
}

void Controller::exeTrainer(int subCmd, Trainer* t)
{
	int i;
	switch (subCmd)
	{
	case 1:
	{
		v->printRef(t);
		break;
	}
	case 2:
	{
		i = t->getCap() - t->numMonsters();
		std::cout << "How many Monsters Would you like to make? (max of " + std::to_string(i) + ")" << std::endl;//have to make exception for now.
		std::cin >> i;
		while (i != 0)
		{
			t->addMonster(getMonsterInfo());
			i--;
		}
		break;
	}
	case 3:
	{
		int subCmd = -1;
		v->printRef(t);
		v->print("What Monster do you want to get? (use ID #)");
		std::cin >> i;
		std::pair<bool, Monster*> p = t->getAMonster(i);
		Monster* m;
		if (p.first)
		{
			m = p.second;
		}
		else
		{
			v->print("Error: Failed to find monster with id of " + std::to_string(i));
			break;
		}


		std::string menu = R"(
		What would you like to do with the Monster?

		(1). Change name.
		(2). Change Health.
		(3). Change Strength.
		(4). Change Defense.
		(5). Change ID.
		(0). Go Back.)";

		do
		{
			v->printRef(m);
			subCmd = v->showMenu(true, menu);
			v->print(spacer);
			exeMonster(subCmd, m);
		} while (subCmd > 0);

		break;
	}
	case 4:
	{
		//This will expand into different constraints to get only certain Monsters.
		break;
	}
	case 5:
	{
		v->print(t->getCap());
		break;
	}
	case 6:
	{
		v->printRef(t);
		v->print("What Monster do you want to remove? (use ID #)");
		std::cin >> i;
		if (t->removeMonster(i))
		{
			v->print("Successful");
		}
		else
		{
			v->print("Failure");
		}
		break;
	}
	case 0:
		break;
	default:
		break;
	}
}

void Controller::exeFileHandle(int subCmd, FileHandle* f)
{
	switch (subCmd)
	{
	case 1:
	{
		std::string s = "Are you sure you want to overwrite the file" + f->getFileName() + ". (0 for no, 1 for yes)";

		switch (v->showMenu(true, s))
		{
		case 1:
		{
			f->tempSave(t);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			v->print("Not an option.");
			break;
		}
		}
	}
	case 2:
	{
		t = f->Load();
		break;
	}
	case 0:
	{
		break;
	}
	default:
		break;
	}
}