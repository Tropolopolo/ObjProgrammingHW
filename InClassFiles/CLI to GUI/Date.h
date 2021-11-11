//What goes in our .h
// Class Declarations
// Function Delcarions
// Variables

#include <iostream>

class Date 
{
public:	
	//Default constructor
	Date();
	Date(int, int, int);	
	int get_year();	
	int get_month();	
	int get_day() const;
	void set_day(int);
	void add_day(int);	
	friend std::ostream& operator<<(std::ostream&, const Date&);
	std::string to_string() const;
	void add_dates(Date);
	bool operator<(const Date&) const;
private:	
	int year;
	int month;
	int day;
};
