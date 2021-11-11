#include <vector>
#include <iostream>

template<typename T>
class Sort
{
public:
	Sort(std::vector<T> v = {}, int c = 0) : vec(v), choice(c) { std::cout << "here" << std::endl; Sorter(choice); };
	std::vector<T> Sorter(int c)
	{
		switch (c)
		{
		default:
		{	
			break;
		}
		case 4:
		{//sort by ID.
			int counter = 0;
			auto Lit = vec.begin();
			auto Rit = vec.begin() + 1;

			std::cout << typeid(Lit).name() << " " << typeid(Rit).name() << std::endl;

			/*
			for (; Rit != vec.end(); Lit++, Rit++, counter++)
			{
				if (*Rit > *Lit)
				{
					auto temp = Lit;
					vec.at(counter) = *Rit;
					vec.at((counter + 1)) = *temp;
				}
			}
			*/
			break;
		}
		case 1:
		{
			int counter = 0;
			auto Lit = vec.begin();
			auto Rit = vec.begin() + 1;
			for (; Rit != vec.end(); Lit++, Rit++, counter++)
			{
				if ((*Rit)->getHealth() > (*Lit)->getHealth())
				{
					auto temp = Lit;
					vec.at(counter) = *Rit;
					vec.at((counter + 1)) = *temp;
				}
			}
			break;
		}
		case 2:
		{
			int counter = 0;
			auto Lit = vec.begin();
			auto Rit = vec.begin() + 1;
			for (; Rit != vec.end(); Lit++, Rit++, counter++)
			{
				if ((*Rit)->getStr() > (*Lit)->getStr())
				{
					auto temp = Lit;
					vec.at(counter) = *Rit;
					vec.at((counter + 1)) = *temp;
				}
			}
			break;
		}
		case 3:
		{
			int counter = 0;
			auto Lit = vec.begin();
			auto Rit = vec.begin() + 1;
			for (; Rit != vec.end(); Lit++, Rit++, counter++)
			{
				if ((*Rit)->getDef() > (*Lit)->getDef())
				{
					auto temp = Lit;
					vec.at(counter) = *Rit;
					vec.at((counter + 1)) = *temp;
				}
			}
			break;
		}
		case 0:
		{
			break;
		}
		}
	}
private:
	std::vector<T> vec;
	int choice;
};