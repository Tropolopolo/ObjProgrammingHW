#include "mli1200_Controller.h"
#include <fstream>
/*
void Controller::cli()
{
	
	int cmd = -1;
	do
	{
		view.show_menu(buttons);
		std::cin >> cmd;
		execute_cmd(cmd);
	} while (cmd > 0);
}
*/
void Controller::gui()
{
	int cmd = -1;
	do 
	{
		cmd = view.show_menu();
		execute_gui_cmd(cmd);
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
		string = "How many animals in exhibit " + aNumi;
		int num_animals = view.get_input_i(string);

		string = "What are the species of these animals?";
		
		species = view.get_input_s(string);

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
			name = view.get_input_s(string);
			try
			{
				string = "animal " + aNumj + "'s id number?";
				id_number = view.get_input_i(string);
				if (id_number < 0)
					throw new negative_id();
			}
			catch (Controller::negative_id* e) //This doesn't really do anything except say that there is a problem.
			{
				view.error(e->what());
			}
			

			string = "animal " + aNumj + "'s gender (0 for male, 1 for female)?";
			gender = view.get_input_i(string);

			
			try
			{
				string = "animal " + aNumj + "'s age?";
				age = view.get_input_i(string);
				if (age < 0)
					throw new negative_age();
			}
			catch (Controller::negative_age* e)//This doesn't really do anything except say that there is a problem.
			{
				view.error(e->what());
			}

			string = "animal " + aNumj + "'s health status?";
			
			health_status = view.get_input_s(string);

			int x = -1;
			do
			{
				string = "animal " + aNumj + "'s type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n";
				x = view.get_input_i(string);
				if (typeid(x) != typeid(int))	//This is an exception
				{
					view.incorrect_selection();
					x = view.get_input_i(string);
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

	species = view.get_input_s("animal's species?");

	name = view.get_input_s("animal's name?");

	try
	{
		
		id_number = view.get_input_i("animal's id number?");
		if (id_number < 0)
			throw new negative_id();
	}
	catch (Controller::negative_id* e)//This doesn't really do anything except say that there is a problem.
	{
		view.error(e->what());
	}

	gender = view.get_input_i("animal's gender (0 for male, 1 for female)?");

	try
	{
		
		age = view.get_input_i("animal's age?");
		if (age < 0)
			throw new negative_age();
	}
	catch (Controller::negative_age* e)//This doesn't really do anything except say that there is a problem.
	{
		view.error(e->what());
	}

	health_status = view.get_input_s("animal's health status?");

	int x = -1;
	do
	{
		
		x = view.get_input_i("animal's type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n");
		if (typeid(x) != typeid(int))	//This is an exception
		{
			view.incorrect_selection();
			
			x = view.get_input_i("animal's type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n");
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

/*
void Controller::execute_cmd(int cmd)
{
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

*/

void Controller::execute_gui_cmd(int cmd)
{
	int i = 0;
	std::string species = "";
	switch (cmd)
	{
	case 1:
	{
		int x = view.get_input_i("How many Exhibits would you like to add?");
		std::vector<bool> t = get_multianimal_info(x);
		for (x = 0; x < t.size(); x++)
		{
			if (t.at(x))
			{
				std::string msg = "Success ";
				view.messageP(msg, std::to_string(x));
			}
			else
				view.messageP("Failure: Likely due to exceeding zoo capacity.", "false");
		}
		break;
	}
	case 2:
	{
		if (get_animal_info())
			view.messageP("Success", "true");
		else
			view.messageP("Failure: Likely due to exceeding zoo capacity.", "false");
		break;
	}
	case 3:
	{
		i = view.get_input_i("an animal id.");
		zoo.remove_animal(i);
		break;
	}
	case 4:
	{
		i = view.get_input_i("the new capacity.");
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
		species = view.get_input_s("the species of animal to display.");
		view.print_list(zoo.get_animals_of_species(species));
		break;
	}
	case 7:
	{
		i = view.get_input_i("the animal's id.");
		view.printAnimal(zoo.get_animal(i));
		break;
	}
	case 8:
	{
		i = view.get_input_i("the animal's id.");
		int a = view.get_input_i("the animal's new age.");;
		zoo.change_animal_age(i, a);
		break;
	}
	case 9:
	{	// here I reuse the string species to preserve memory.
		i = view.get_input_i("the animal's id.");
		species = view.get_input_s("the animal's health status.");
		zoo.change_animal_health_status(i, species);
		break;
	}
	case 10:
	{	//I reuse Species here to preserve memory...

		int x = view.get_input_i("animal's type?\n(1). Terrestrial\n(2). Aquatic\n(3). Avian\n(4). Amphibious\n");
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
		view.messageP(zoo.get_capacity(), "Zoo Capacity");
		break;
	}
	case 12:
	{
		std::vector<Animal*> alist = zoo.get_all_animals();
		auto vec_it = alist.begin();
		for (; vec_it != alist.end(); vec_it++)
		{
			view.messageP((*vec_it)->act(), "Animal Action");
		}
		break;
	}
	case 13:
	{
		
	// Preset animals for testing purposes...
	Animal* a1 = new Terrestrial("Ross", 6, 1, 31, "Good", "Terrestrial", "Dog");
	Animal* a2 = new Aquatic("Jamie", 7, 1, 33, "Good", "Aquatic", "Fish");
	Animal* a3 = new Avian("Orochimaru", 8, 1, 56, "Good", "Avian", "Birb");
	Animal* a4 = new Amphibious("Amaterasu no Okami", 9, 0, 10000, "Good", "Amphibious", "Frog");

	zoo.add_animal(a1);
	zoo.add_animal(a2);
	zoo.add_animal(a3);
	zoo.add_animal(a4);

	Animal* a5 = new Terrestrial("Mark", 10, 1, 32, "Good", "Terrestrial", "Dog");
	Animal* a6 = new Avian("April", 11, 0, 25, "Bad", "Avian", "HummingBird");

	zoo.add_animal(a5);
	zoo.add_animal(a6);
	break;
	// End of the test animals...
	
	}
	case 0:
	{
		view.messageP("Have a nice day!!", "Closing");
		break;
	}
	default:
	{
		view.incorrect_selection();
		break;
	}
	}
}

std::vector<bool> Controller::load_from_file()
{
	std::vector<bool> success;
	
	std::ifstream myfile;
	std::string str;
	myfile.open("Testfile.txt");
	std::cout << "here" << std::endl;
	if (myfile.is_open())
	{
		while (std::getline(myfile, str))
		{
			std::string name;
			int id_number;
			bool gender;
			int age;
			std::string health_status;
			std::string type;
			int typeint;
			std::string species;

			std::string delimiter = " ";
			size_t pos = str.find(delimiter);

			species = str.substr(0, pos);
			str.erase(0, pos + delimiter.length());
			pos = str.find(delimiter);
			
			name = str.substr(0, pos);
			str.erase(0, pos + delimiter.length());
			pos = str.find(delimiter);

			id_number = std::atoi(str.substr(0, pos).c_str());
			str.erase(0, pos + delimiter.length());
			pos = str.find(delimiter);

			gender = std::atoi(str.substr(0, pos).c_str());
			str.erase(0, pos + delimiter.length());
			pos = str.find(delimiter);

			age = std::atoi(str.substr(0, pos).c_str());
			str.erase(0, pos + delimiter.length());
			pos = str.find(delimiter);

			health_status = str.substr(0, pos);
			str.erase(0, pos + delimiter.length());
			pos = str.find(delimiter);

			typeint = std::atoi(str.substr(0, pos).c_str());
			str.erase(0, pos + delimiter.length());

			std::cout << species << " " << name << " " << id_number << " " << gender << " " << age << " " << health_status << " " << typeint << std::endl;

			if (typeid(typeint) != typeid(int))	//This is an exception
			{
				view.incorrect_selection();
			}
			switch (typeint)
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


			success.push_back(zoo.add_animal(a));
			
			if (myfile.eof())
			{
				break;
			}
		}
	}


}

void Controller::save_to_file()
{
	std::ofstream myfile;
	std::string str;
	myfile.open("Testfile.txt");
}