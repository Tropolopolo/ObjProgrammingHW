// Matthew Irvine 1001401200

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <utility>
#include <map>

int main(int argc, char *argv[])
{
	int a =1;
	std::string line;
	std::string temp;
	std::vector<std::string> vW;
	std::vector<int> vI;
	std::vector<int> vI2;
	std::map <std::string, int > map1;
	std::ifstream myfile(argv[a], std::ios_base::in);

	if (myfile.is_open())
	{
		std::cout << "Opening " << argv[a] << std::endl;
		std::cout << std::endl;
		int counter = 0;
		while (myfile >> line) //if myfile.good()
		{
			std::cout << line << std::endl;
			vW.push_back(line);
			for (int x=counter; x < vW.size(); x++)
			{
				temp = vW.at(x);
				//std::cout << temp.size() << std::endl;
				for (int y = 0; y < temp.size(); y++)
				{
					if (std::isdigit(temp.at(y)))
					{
						//std::cout << "temp= " << temp << "| for line :" << line << std::endl;
						vI.push_back(temp.at(y)-48);
						//std::cout << "vI at y = " << vI.at(y) << std::endl;
					}
				}
			}
			counter++;
		}
		std::cout << std::endl;
		for (int t=0; t < vI.size(); t++)
		{
			std::cout << vI.at(t)<<std::endl;
			//std::cout << t << std::endl;
		}
		std::cout << std::endl;

		if (myfile.eof()) {
			std::cout << "End of " << argv[a]<< std::endl;
			//return 0;
		}

		//std::cout << vI.size();
		myfile.close();
		vW.clear();	
	}
	a++;
	myfile.open(argv[a], std::ios_base::in);

	if (myfile.is_open())
	{
		std::cout << "Opening " << argv[a] << std::endl;
		std::cout << std::endl;
		while (myfile >> line) //if myfile.good()
		{		
			vW.push_back(line);
			
		}
		for (int x=0; x < vW.size(); x++)
		{
			temp = vW.at(x);
			if (std::isdigit(temp.at(0)))
			{
				vI2.push_back((temp.at(0) - 48));
				vW.erase(vW.begin()+x);
			}

			std::string s = vW.at(x);
			int i = vI2.at(x);
			map1.insert (std::pair<std::string, int>(s, i) );
		}
		std::cout << std::endl;
		for (auto temp : map1)
			std::cout << temp.first << "," << temp.second << std::endl;

		std::cout << std::endl;
		
		for (int n = 0; n < vI.size(); n++)
		{
			for (auto temp : map1)
			{
				//std::cout << temp.second << "," << vI.at(n) << std::endl;
				if (temp.second == vI.at(n))
					std::cout << temp.first;
			}
		}

		std::cout << std::endl;

		if (myfile.eof()) {
			std::cout << "End of " << argv[a] << std::endl;
			//return 0;
		}
		myfile.close();
		vW.clear();
		vI2.clear();
		vI.clear();
	}

	if (!myfile.is_open())
		return 0;
	else if (myfile.bad())
		throw std::runtime_error("bad");
	else 
		std::cout << "Unable to open " << argv[a] << std::endl;
	return 0;
}
