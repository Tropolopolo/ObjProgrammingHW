#include "View.h"

int View::showMenu(bool b, std::string s)
{
	int result;
	if (b)//true for if you want to use an original menu...
	{
		std::cout << s << std::endl;
		std::cin >> result;
		return result;
	}
	else
	{
		std::cout << menu << std::endl;
		std::cin >> result;

		return result;
	}
}