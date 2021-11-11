#include "Hourly.h"

double Hourly::get_hours_worked()
{
	return hours_worked;
}

double Hourly::get_pay_rate()
{
	return pay_rate;
}

void Hourly::add_hours(double hrs)
{
	hours_worked += hrs;
}

double Hourly::pay()
{
	double amount_paid =  hours_worked*pay_rate;
	hours_worked = 0;
	return amount_paid;
}

std::string Hourly::pay_s()
{
	double amount_paid =  hours_worked*pay_rate;
	hours_worked = 0;
	std::string print = name + " got paid " + std::to_string(amount_paid);
	return print;
}
