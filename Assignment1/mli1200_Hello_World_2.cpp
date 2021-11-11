//Matthew Irvine 1001401200

#include <iostream>

int main()
{
	std:: string name;
	int x;
	int y;
	double dx;
	double dy;
	
	std::cout<<"Hello User"<<std::endl;
	std::cout<<"What is your name?"<<std::endl;
	std::cin>>name;
	
	std::cout<<"Thanks for telling me your name."<<std::endl;
	std::cout<<"Now, give me two integers"<<std::endl;
	std::cin>>x;
	std::cin>>y;
	
	std::cout<<"The sum is: "<< x+y<<std::endl;
	std::cout<<"The difference is: "<< x-y<<std::endl;
	std::cout<<"The Product is: "<< x*y<<std::endl;
	std::cout<<"The Quotient is: "<< x/y<<std::endl;
	
	std::cout<<"Please type out two numbers with decimals."<<std::endl;
	std::cin>>dx;
	std::cin>>dy;
	
	std::cout<<"The sum is: "<< dx+dy<<std::endl;
	std::cout<<"The difference is: "<< dx-dy<<std::endl;
	std::cout<<"The Product is: "<< dx*dy<<std::endl;
	std::cout<<"The Quotient is: "<< dx/dy<<std::endl;
	
	std::cout<<"Thank you for your time "<<name<<std::endl;
}
