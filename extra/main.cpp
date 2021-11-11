//Matthew Irvine
#include <iostream>
int main()
{
	double sum = 0;
	double i = 0;

	for (int k = 1; k <= 6; k++)
	{
		i = (double)k;
		sum = sum + (i*((9*i)+2));
		std::cout << sum<< std::endl;
	}

	std::cout << sum << std::endl;
}