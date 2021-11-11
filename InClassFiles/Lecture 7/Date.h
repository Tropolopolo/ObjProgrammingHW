#include <iostream>

class Date
{
	public:
		Date(); // Defualt Constructor
		Date(int y, int m, int d);
		void set_day(int d);
		int get_day() const;
		void add_day(); //add one to the date
		void add_day(int n);
		std::string to_string() const;
		friend std::ostream& operator<<(std::ostream& ost, const Date& d);
		bool operator<(const Date&) const;
	private:
		int year;
		int month;
		int day;
	
};
