#include "mli1200_Controller.h"
#include "mli1200_Save.h"

void Controller::cli()
{
	int cmd = -1;
	do
	{
		view.show_menu();
		std::cin >> cmd;
		execute_cmd(cmd);
	} while (cmd > 0);
}

std::vector<bool> Controller::get_multianimal_info(int num)
{
	std::vector<bool> t;
	std::string species;
	for (int i = 0; i < num; i++)
	{
		std::string aNumi = std::to_string(i + 1);
		std::string string;
		int num_animals;
		string = "How many animals in exhibit " + aNumi;
		view.get_input(string);
		std::cin >> num_animals;

		string = "What are the species of these animals?";
		view.get_input(string);
		std::cin >> species;

		for (int j = 0; j < num_animals; j++)
		{
			std::string aNumj = std::to_string(j + 1);
			std::string name;
			int id_number;
			bool gender;
			int age;
			std::string health_status;
			std::string type;

			string = "animal " + aNumj + "'s name?";
			view.get_input(string);
			std::cin >> name;
			try
			{
				string = "animal " + aNumj + "'s id number?";
				view.get_input(string);
				std::cin >> id_number;
				if (id_number < 0)
					throw new negative_id();
			}
			catch (Controller::negative_id* e) //This doesn't really do anything except say that there is a problem.
			{
				view.error(e->what());
			}
			

			string = "animal " + aNumj + "'s gender (0 for male, 1 for female)?";
			view.get_input(string);
			std::cin >> gender;

			
			try
			{
				string = "animal " + aNumj + "'s age?";
				view.get_input(string);
				std::cin >> age;
				if (age < 0)
					throw new negative_age();
			}
			catch (Controller::negative_age* e)//This doesn't really do anything except say that there is a problem.
			{
				view.error(e->what());
			}

			string = "animal " + aNumj + "'s health status?";
			view.get_input(string);
			std::cin >> health_status;

			int x = -1;
			do
			{
				string = "animal " + aNumj + "'s type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n";
				view.get_input(string);
				std::cin >> x;
				if (typeid(x) != typeid(int))	//This is an exception
				{
					view.incorrect_selection();
					view.get_input(string);
					std::cin >> x;
				}
				switch (x)
				{
					case 1:
					{
						type = "Terrestrial";
						break;
					}
					case 2:
					{
						type = "Aquatic";
						break;
					}
					case 3:
					{
						type = "Avian";
						break;
					}
					case 4:
					{
						type = "Amphibious";
						break;
					}
					default:
					{
						view.incorrect_selection();
						break;
					}	
				}
			} while (x <= 0 && x > 4);

			

			Animal* a;
			/*
			switch (type)
			{
				case Terrestrial:
				{
					a = new Terrestrial(name, id_number, gender, age, health_status, type, species);
				}
				case "Aquatic":
				{
					a = new Aquatic(name, id_number, gender, age, health_status, type, species);
				}
				case "Avian":
				{
					a = new Avian(name, id_number, gender, age, health_status, type, species);
				}
				case "Amphibious":
				{
					a = new Amphibious(name, id_number, gender, age, health_status, type, species);
				}
				default:
				{
					a = new Animal(name, id_number, gender, age, health_status, type, species);	//This may not work, we will see
				}
			}
			*/

			if (type == "Terrestrial")
				a = new Terrestrial(name, id_number, gender, age, health_status, type, species);
			else if(type == "Aquatic")
				a = new Aquatic(name, id_number, gender, age, health_status, type, species);
			else if(type == "Avian")
				a = new Avian(name, id_number, gender, age, health_status, type, species);
			else if(type == "Amphibious")
				a = new Amphibious(name, id_number, gender, age, health_status, type, species);
			else 
				a = new Animal(name, id_number, gender, age, health_status, type, species);	//This may not work, we will see
			


			if (!(zoo.add_animal(a)))
			{
				t.push_back(false);
			}
			else
				t.push_back(true);
		}
	}

	return t;
}

bool Controller::get_animal_info()
{
	std::string name;
	int id_number;
	bool gender;
	int age;
	std::string health_status;
	std::string type;
	std::string species;

	view.get_input("animal's name?");
	std::cin >> name;

	try
	{
		view.get_input("animal's id number?");
		std::cin >> id_number;
		if (id_number < 0)
			throw new negative_id();
	}
	catch (Controller::negative_id* e)//This doesn't really do anything except say that there is a problem.
	{
		view.error(e->what());
	}

	view.get_input("animal's gender (0 for male, 1 for female)?");
	std::cin >> gender;

	try
	{
		view.get_input("animal's age?");
		std::cin >> age;
		if (age < 0)
			throw new negative_age();
	}
	catch (Controller::negative_age* e)//This doesn't really do anything except say that there is a problem.
	{
		view.error(e->what());
	}

	view.get_input("animal's health status?");
	std::cin >> health_status;

	int x = -1;
	do
	{
		view.get_input("animal's type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n");
		std::cin >> x;
		if (typeid(x) != typeid(int))	//This is an exception
		{
			view.incorrect_selection();
			view.get_input("animal's type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n");
			std::cin >> x;
		}
		switch (x)
		{
			case 1:
			{
				type = "Terrestrial";
				break;
			}
			case 2:
			{
				type = "Aquatic";
				break;
			}
			case 3:
			{
				type = "Avian";
				break;
			}
			case 4:
			{
				type = "Amphibious";
				break;
			}
			default:
			{
				view.incorrect_selection();
				break;
			}
		}
	} while (x <= 0 && x > 4);

	view.get_input("animal's species?");
	std::cin >> species;

	Animal* a;
	if (type == "Terrestrial")
		a = new Terrestrial(name, id_number, gender, age, health_status, type, species);
	else if (type == "Aquatic")
		a = new Aquatic(name, id_number, gender, age, health_status, type, species);
	else if (type == "Avian")
		a = new Avian(name, id_number, gender, age, health_status, type, species);
	else if (type == "Amphibious")
		a = new Amphibious(name, id_number, gender, age, health_status, type, species);
	else
		a = new Animal(name, id_number, gender, age, health_status, type, species);	//This may not work, we will see

	return zoo.add_animal(a);
}

void Controller::execute_cmd(int cmd)
{
	Save save("ZooSave8.txt");
	int i =0;
	std::string species = "";
	switch (cmd)
	{
		case 1:
		{
			view.get_input("How many Exhibits would you like to add?");
			int x;
			std::cin >> x;
			std::vector<bool> t = get_multianimal_info(x);
			for (x = 0; x < t.size(); x++)
			{
				if (t.at(x))
				{
					view.printP("Success");
				}
				else
					view.printP("Failure: Likely due to exceeding zoo capacity.");
			}
			break;
		}
		case 2:
		{
			if (get_animal_info())
				view.printP("Success");
			else
				view.printP("Failure: Likely due to exceeding zoo capacity.");
			break;
		}
		case 3:
		{
			view.get_input("an animal id.");
			std::cin >> i;
			zoo.remove_animal(i);
			break; 
		}
		case 4:
		{
			view.get_input("the new capacity.");
			std::cin >> i;
			zoo.set_capacity(i);
			break;
		}
		case 5:
		{
			std::vector<Animal*> alist = zoo.get_all_animals();
			view.print_list(alist);
			break;
		}
		case 6:
		{
			view.get_input("the species of animal to display.");
			std::cin >> species;
			view.print_list(zoo.get_animals_of_species(species));
			break;
		}
		case 7:
		{
			view.get_input("the animal's id.");
			std::cin >> i;
			view.printAnimal(zoo.get_animal(i));
			break;
		}
		case 8:
		{
			view.get_input("the animal's id.");
			std::cin >> i;
			view.get_input("the animal's new age.");
			int a;
			std::cin >> a;
			zoo.change_animal_age(i, a);
			break;
		}
		case 9:
		{	// here I reuse the string species to preserve memory.
			view.get_input("the animal's id.");
			std::cin >> i;
			view.get_input("the animal's health status.");
			std::cin >> species;
			zoo.change_animal_health_status(i, species);
			break;
		}
		case 10:
		{	//I reuse Species here to preserve memory...
			
			int x;
			view.get_input("animal's type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n");
			std::cin >> x;
			switch (x)
			{
			case 0:
			{
				species = "Animal";
				break;
			}
			case 1:
			{
				species = "Terrestrial";
				break;
			}
			case 2:
			{
				species = "Aquatic";
				break;
			}
			case 3:
			{
				species = "Avian";
				break;
			}
			case 4:
			{
				species = "Amphibious";
				break;
			}
			default:
			{
				view.incorrect_selection();
				break;
			}
			}
			std::vector<Animal*> alist = zoo.get_animals_of_type(species);
			view.print_list(alist);
			break;
		}
		case 11:
		{
			view.printP(zoo.get_capacity());
			break;
		}
		case 12:
		{
			std::vector<Animal*> alist = zoo.get_all_animals();
			auto vec_it = alist.begin();
			for (; vec_it != alist.end(); vec_it++)
			{
				view.printP((*vec_it)->act());
			}
			break;
		}
		case 13:
		{
			std::vector<Animal*> alist = zoo.get_all_animals();
			save.writeAnimals(alist);
			for (auto x : alist)
			{
				zoo.remove_animal(x->get_id_number());
			}
			break;
		}
		case 14:
		{
			std::vector<Animal*> alist = save.readAnimals();
			for (auto x : alist)
			{
				zoo.add_animal(x);
			}
			break;
		}
		case 15:
		{
			view.printP(save.getFilename());
			break;
		}
		case 16:
		{
			std::string s;
			view.get_input("the desired filename.");
			std::cin >> s;
			save.setFilename(s);
			break;
		}
		case 0:
		{
			view.printP("Have a nice day!!");
			break;
		}
		default:
		{
			view.incorrect_selection();
			break;
		}
	}
}
