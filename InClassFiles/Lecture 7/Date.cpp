#include "Date.h"

Date::Date() // Defualt Constructor
{
	year = 1369;
	month = 7;
	day = 22;
}
Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::set_day(int d)
{
	if(d > 0 && d < 31)
		day = d;
}
int Date::get_day() const
{
	return day;
}
void Date::add_day() //add 1 to the current day
{
	day++;
	if(day == 31)
	{
		month++;
		day = 1;
		if (month == 13)
		{	
			year++;
			month = 1;
		}
	}
}

void Date::add_day(int n)
{
	day += n;
	if(day >= 31)
	{
		month++;
		day = 1;
		if (month == 13)
		{	
			year++;
			month = 1;
		}
	}
}
std::string Date::to_string() const
{
	std::string result = "";
	result += std::to_string(year) + " " + std::to_string(month) + " " + std::to_string (day);
	return result;
}
std::ostream& operator<<(std::ostream& ost, const Date& d)
{
	ost << d.month << " " << d.day << " " << d.year;
	return ost;
}

bool Date::operator<(const Date& d) const
{
	if(year > d.year)
		return false;
	//(*this).
	if(this->year < d.year)
		return true;
	if(this->month > d.month)
		return false;
	if(this->month < d.month)
		return true;
	if(this->day >= d.day)
		return false;
	return true;
}

