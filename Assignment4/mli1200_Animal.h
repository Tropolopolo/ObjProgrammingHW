//Matthew Irvine 1001401200
#include <iostream>

class Animal
{
public:
	//constructors
	Animal();
	Animal(std::string n, int id, bool g, int a, std::string hs, std::string t);
	//get methods
	std::string get_name();
	int get_id();
	bool get_gender();
	int get_age();
	std::string get_health_status();
	std::string get_type();
	//set methods
	void set_name(std::string n);
	void set_id_number(int id);
	void set_gender(bool g);
	void set_age(int a);
	void set_health_status(std::string hs);
	void set_type(std::string t);
	//Other methods
	std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& ost, const Animal& animal);
	friend bool operator==(std::ostream& ost, const int& id);

private:
	std::string name;
	int id_number;
	bool gender;
	int age;
	std::string health_status;
	std::string atype;
};