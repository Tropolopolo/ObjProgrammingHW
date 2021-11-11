// What goes in our .cpp

// Function Definitions
#include "Date.h"

Date::Date()
{
	year = 15;
	month = 11;
	day = 23;
}

Date::Date(int y, int m, int d)
{
	year = y;
	if(m > 0 && m < 13)
		month = m;
	else
		month = 1;
	if(d > 0 && d <= 30)
		day = d;
	else 
		day = 1;
}

int Date::get_year()
{
	return year;
}

int Date::get_month()
{
	return month;
}

int Date::get_day() const
{
	return day;
}

void Date::set_day(int d)
{
	if(d > 0 && d <= 30)
		day = d;
}

void Date::add_day(int n)
{
	day = day + n;
	if(day > 30)
	{
		day -= 30;
		month++;
	}
}

std::string Date::to_string() const
{
	return std::to_string(year) + " " + std::to_string(month) + " " + std::to_string(day);
}

void Date::add_dates(Date d)
{
	this->day += d.day;
}

std::ostream& operator<<(std::ostream& ost, const Date& date)
{
	ost << date.year << " " << date.month << " " << date.day;
}

//date1 < date2
//date1.operator<(date2)
//this would refer to date1
bool Date::operator<(const Date& date_two) const
{
	if(this->year > date_two.year)
		return false;
	if(this->year < date_two.year)
		return true;
	if(this->month > date_two.month)
		return false;
	if(this->month < date_two.month)
		return true;
	if(this->day >= date_two.day)
		return false;
	return true;
}
