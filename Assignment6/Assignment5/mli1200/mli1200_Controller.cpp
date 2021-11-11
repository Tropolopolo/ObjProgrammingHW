#include "mli1200_Controller.h"

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
	for (int i = 0; i < num; i++)
	{
		std::string aNumi = std::to_string(i + 1);
		std::string string;
		int num_animals;
		string = "How many animals in exhibit " + aNumi;
		view.get_input(string);
		std::cin >> num_animals;

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

			string = "animal " + aNumj + "'s id number?";
			view.get_input(string);
			std::cin >> id_number;

			string = "animal " + aNumj + "'s gender (0 for male, 1 for female)?";
			view.get_input(string);
			std::cin >> gender;

			string = "animal " + aNumj + "'s age?";
			view.get_input(string);
			std::cin >> age;

			string = "animal " + aNumj + "'s health status?";
			view.get_input(string);
			std::cin >> health_status;

			string = "animal " + aNumj + "'s type?";
			view.get_input(string);
			std::cin >> type;

			if (!(zoo.add_animal(Animal(name, id_number, gender, age, health_status, type))))
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
	std::string string;
	std::string name;
	int id_number;
	bool gender;
	int age;
	std::string health_status;
	std::string type;
	string = "animal's name?";
	view.get_input(string);
	std::cin >> name;

	string = "animal's id number?";
	view.get_input(string);
	std::cin >> id_number;

	string = "animal's gender (0 for male, 1 for female)?";
	view.get_input(string);
	std::cin >> gender;

	string = "animal's age?";
	view.get_input(string);
	std::cin >> age;

	string = "animal's health status?";
	view.get_input(string);
	std::cin >> health_status;

	string = "animal's type?";
	view.get_input(string);
	std::cin >> type;

	return zoo.add_animal(Animal(name, id_number, gender, age, health_status, type));
}

void Controller::execute_cmd(int cmd)
{
	int i =0;
	std::string type = "";
	switch (cmd)
	{
		case 1:
		{
			std::vector<bool> t = get_multianimal_info(zoo.get_capacity());
			for (int x = 0; x < t.size(); x++)
			{
				if (t.at(x))
				{
					view.print("Success");
				}
				else
					view.print("Failure: Likely due to exceeding zoo capacity.");
			}
			break;
		}
		case 2:
		{
			if (get_animal_info())
				view.print("Success");
			else
				view.print("Failure: Likely due to exceeding zoo capacity.");
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
			std::vector<Animal> alist = zoo.get_all_animals();
			view.print_list(alist);
			break;
		}
		case 6:
		{
			view.get_input("the type of animal to display.");
			std::cin >> type;
			view.print_list(zoo.get_animals_of_type(type));
			break;
		}
		case 7:
		{
			view.get_input("the animal's id.");
			std::cin >> i;
			view.print(zoo.get_animal(i));
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
		{
			view.get_input("the animal's id.");
			std::cin >> i;
			view.get_input("the animal's health status.");
			std::cin >> type;
			zoo.change_animal_health_status(i, type);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			view.incorrect_selection();
			break;
		}
	}
}


