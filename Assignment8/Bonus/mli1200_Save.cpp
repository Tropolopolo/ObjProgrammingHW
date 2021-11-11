#include "mli1200_Save.h"
/*
void Save::writeAnimals(std::vector<Animal*> alist)
{
	pFile = fopen(filename.c_str(), "w");
	if (pFile == NULL)
		perror("Error opening file ");
	else
	{
		for (auto x : alist)
		{
			if (x->get_type() == "Terrestrial")
			{
				Terrestrial s = *(dynamic_cast<Terrestrial*>(x));

				std::string y = s.to_string();

				std::cout << y << std::endl;
				char buffer[y.size() + 1];

				strcpy(buffer, y.c_str());


				if (!feof(pFile))
				{
					
					if ( ftell(pFile) == 0)
					{
						std::cout << "here" << std::endl;
						break;
					}
					

					fputs(buffer, pFile);
				}
				else
				{
					perror("End of File ");
					break;
				}

				lengths.push_back((y.size() + 1));
			}
				
			if (x->get_type() == "Aquatic")
			{
				Aquatic s = *(dynamic_cast<Aquatic*>(x));

				std::string y = s.to_string();
				std::cout << y << std::endl;
				char buffer[y.size() + 1];

				strcpy(buffer, y.c_str());


				if (!feof(pFile))
				{
					
						if ( ftell(pFile) == 0)
						{
							std::cout << "here" << std::endl;
							break;
						}
						

					fputs(buffer, pFile);
				}
				else
				{
					perror("End of File ");
					break;
				}

				lengths.push_back((y.size() + 1));
			}
				
			if (x->get_type() == "Amphibious")
			{
				Amphibious s = *(dynamic_cast<Amphibious*>(x));

				std::string y = s.to_string();
				std::cout << y << std::endl;
				char buffer[y.size() + 1];
				strcpy(buffer, y.c_str());
				if (!feof(pFile))
				{
					
					if ( ftell(pFile) == 0)
					{
						std::cout << "here" << std::endl;
						break;
					}
					


					fputs(buffer, pFile);
				}
				else
				{
					perror("End of File ");
					break;
				}
				lengths.push_back((y.size() + 1));
			}
				
			if (x->get_type() == "Avian")
			{
				Avian s = *(dynamic_cast<Avian*>(x));

				std::string y = s.to_string_file();

				std::cout << y << std::endl;
				char buffer[y.size() + 1];

				strcpy(buffer, y.c_str());

				
				if (!feof(pFile))
				{
					
					if ( ftell(pFile) == 0)
					{
						std::cout << "here" << std::endl;
						break;
					}
					
					std::cout << "here" << std::endl;
					fputs(buffer, pFile);
					//fputs("\n", pFile);
				}
				else
				{
					perror("End of File ");
					break;
				}

				lengths.push_back((y.size() + 1));
			}
		}
		//havesaved = true;
		fclose(pFile);
	}
}

std::vector<Animal*> Save::readAnimals()
{
	std::vector<Animal*> alist;
	std::string name;
	int id;
	int age;
	int gender;
	std::string health;
	std::string type;
	std::string species;
	pFile = fopen(filename.c_str(), "r");
	if (pFile == NULL)
		perror("Error opening file ");
	else
	{
		int x = 0;
		while (!feof(pFile))
		{
			
			char buffer[100];

			if (fgets(buffer, 100, pFile) == NULL)
				break;
			else
			{
				
				char * pch;
				pch = strtok(buffer, ",");
				int counter = 0;
				while (pch != NULL)
				{
					
					switch (counter)
					{
					case 0:
					{
						name = pch;
						break;
					}
					case 1:
					{
						std::cout << *pch << std::endl;
						id = (int) (*pch) - 48;
						std::cout << "\t" << id  << std::endl;
						break;
					}
					case 2:
					{
						std::cout << *pch << std::endl;
						age = (int) *pch - 48;
						break;
					}
					case 3:
					{
						std::cout << *pch << std::endl;
						std::cout << "________________________" << std::endl;
						gender = (int) *pch - 48;
						break;
					}
					case 4:
					{
						health = pch;
						break;
					}
					case 5:
					{
						type = pch;
						break;
					}
					case 6:
					{
						species = pch;
						break;
					}
					default:
						break;
					}

					
					pch = strtok(NULL, ",");
					counter++;
				}

				Animal* a;
				if (type == "Terrestrial")
					a = new Terrestrial(name, id, age, gender, health, type, species);
				else if (type == "Aquatic")
					a = new Aquatic(name, id, age, gender, health, type, species);
				else if (type == "Avian")
					a = new Avian(name, id, age, gender, health, type, species);
				else if (type == "Amphibious")
					a = new Amphibious(name, id, age, gender, health, type, species);

				alist.push_back(a);
			}

			x++;
		}
	}
	fclose(pFile);
	return alist;
}
*/

void Save::writeAnimals(std::vector<Animal*> alist)
{
	
	fs.open("SaveFile8.txt", std::ios_base::out);
	if (fs.is_open())
	{
		for (auto a : alist)
		{
			if (a->get_type() == "Terrestrial")
			{
				std::cout << "\t" << *(dynamic_cast<Terrestrial*>(a)) << std::endl;
			}

			if (a->get_type() == "Aquatic")
			{
				std::cout << "\t" << *(dynamic_cast<Aquatic*>(a)) << std::endl;
			}

			if (a->get_type() == "Amphibious")
			{
				std::cout << "\t" << *(dynamic_cast<Amphibious*>(a)) << std::endl;
			}

			if (a->get_type() == "Avian")
			{
				std::cout << "\t" << *(dynamic_cast<Avian*>(a)) << std::endl;
			}
		}
	}
	else
	{
		
	}
	
	//fs.close();
}

std::vector<Animal*> Save::readAnimals()
{
	fs.open(filename, std::ios_base::in);

	fs.close();
}

std::string Save::getFilename()
{
	return filename;
}

/*
std::fstream Save::getFStream()
{
	return fs;
}
*/

void Save::setFilename(std::string s)
{
	filename = s;
}

/*
void Save::setFStream(std::fstream FS)
{
	fs = FS;
}
*/